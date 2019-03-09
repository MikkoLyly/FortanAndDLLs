!-----------------------------------------------------------------------------
!> @file prog.f90
!> @author Mikko Lyly
!> @date 9 Mar 2019
!> @brief Program to test libutils.
!-----------------------------------------------------------------------------

program prog
  !-------------------------------------------------------
  ! Use ISO C-BINGINGS for interoperability with libutils
  !-------------------------------------------------------
  use, intrinsic :: iso_c_binding

  !----------------
  ! Assume nothing
  !----------------
  implicit none

  !-------------------------------
  ! Define interfaces to libutils
  !-------------------------------
  interface
     function plus(a, b) bind(C, name="utils_plus")
       use, intrinsic :: iso_c_binding     
       implicit none
       integer :: plus
       integer :: a, b
     end function plus
  end interface

  interface
     subroutine createclsid(clsid) bind(C, name="utils_createclsid")
       use, intrinsic :: iso_c_binding
       implicit none
       character(kind=c_char), dimension(*) :: clsid
     end subroutine createclsid
  end interface

  !-------------------------------------------------------------
  ! Local variables
  !
  ! Note that character strings in fortran are defined with
  ! attributes "len=N" and "dimension(1)". But when passed to
  ! C-functions they are treated as arrays with "len=1" and
  ! "dimension(N)". The transposition is possible as the data
  ! is always stored in contiguous bytes in memory.
  !-------------------------------------------------------------
  integer :: a, b, c
  character(kind=c_char, len=37) :: clsid

  !--------------------------------------
  ! Test a simple function from libutils
  !--------------------------------------
  a = 1
  b = 2
  c = plus(a, b)
  write(*, '(A, I1, A, I1, A, I1)') "addition: ", a, " + ", b, " = ", c

  !----------------------------------------------
  ! Test another simple subroutine from libutils
  !----------------------------------------------
  clsid = ''
  call createclsid(clsid)
  write(*, '(A, A)') "uuid: ", clsid
  
end program prog
