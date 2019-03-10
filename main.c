/**
 * @file main.c
 * @author Mikko Lyly
 * @date 9 Mar 2019
 * @brief Main program to test libutils.
 */

#include <stdio.h>
#include "utils.h"

int main()
{
  //--------------------------------------
  // Test a simple function from libutils
  //--------------------------------------
  int a = 1;
  int b = 2;
  int c = utils_plus(a, b);
  printf("addition: %d + %d = %d\n", a, b, c);

  //--------------------------------------------  
  // Test another simple function from libutils
  //--------------------------------------------
  char ch[37];
  utils_createclsid(ch);
  printf("uuid: %s\n", ch);
}
