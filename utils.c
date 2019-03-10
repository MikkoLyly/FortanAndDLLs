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
 * @param a An integer.
 * @param b Another integer.
 * @return Sum of a and b.
 */
int utils_plus(int a, int b) {
  return a + b;
}

/**
 * @brief Creates UUID v4.
 * @param ch Pointer to a character buffer (length must be 37 or greater).
 * @return Replaces the first 37 characters of ch with the generated UUID v4.
 */
void utils_createclsid(char *ch) {
#ifdef __WIN32__
  UUID uuid;
  char *str;
  UuidCreate(&uuid);
  UuidToStringA(&uuid, (RPC_CSTR *)&str);
  memcpy(ch, str, 37);
  RpcStringFreeA((RPC_CSTR *)&str);
#else
  uuid_t uuid;
  uuid_generate_random(uuid);
  uuid_unparse(uuid, ch);
#endif
}
