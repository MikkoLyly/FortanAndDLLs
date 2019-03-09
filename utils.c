/**
 * @file utils.c
 * @author Mikko Lyly
 * @date 9 Mar 2019
 * @brief Implements libutils functionality.
 */

#ifdef __WIN32__
#include <windows.h>
#include <rpc.h>
#else
#include <uuid/uuid.h>
#endif
#include <string.h>
#include "utils.h"

/**
 * @brief Addition of integers.
 * @param a Pointer to an integer.
 * @param b Pointer to an integer.
 * @return Sum of a and b.
 */
int utils_plus(int *a, int *b) {
  return *a + *b;
}

/**
 * @brief Creates UUID v4.
 * @param clsid Pointer to a character buffer (length >= 37).
 * @return Replaces the contents of clsid with UUID v4.
 */
void utils_createclsid(char *clsid) {
#ifdef __WIN32__
  UUID uuid;
  char *str;
  UuidCreate(&uuid);
  UuidToStringA(&uuid, (RPC_CSTR *)&str);
  memcpy(clsid, str, 37);
  RpcStringFreeA((RPC_CSTR *)&str);
#else
  uuid_t uuid;
  uuid_generate_random(uuid);
  uuid_unparse(uuid, clsid);
#endif
}
