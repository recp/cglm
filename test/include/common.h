/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef tests_common_h
#define tests_common_h

#include <stdlib.h>
#include <stdio.h>

#include <cglm/cglm.h>
#include <cglm/struct.h>
#include <cglm/call.h>

typedef struct test_status_t {
  const char *msg;
  int         status;
} test_status_t;

typedef test_status_t (*fntest)(void);

typedef struct test_entry_t {
  char  *name;
  fntest entry;
  int    ret;
  int    show_output;
} test_entry_t;

#define TEST_DECLARE(FUN) test_status_t test_ ## FUN(void);
#define TEST_ENTRY(FUN)   { #FUN, test_ ## FUN, 0, 0 }
#define TEST_LIST         static test_entry_t tests[] = 

#define REAL_ASSERT(__VA_ARGS__)(__VA_ARGS__)
#define create(...) REAL_ASSERT(__VA_ARGS__)(__VA_ARGS__)

#define ASSERT_EXT(expr, ...)                                                 \
  if (!(expr)) {                                                              \
    fprintf(stderr,                                                           \
            "Assertion failed in %s on line %d: %s\n",                        \
            __FILE__,                                                         \
            __LINE__,                                                         \
            #expr);                                                           \
    return (test_status_t){__VA_ARGS__, 0};                                   \
  }

#define ASSERT_ARG1(expr)                  ASSERT_EXT(expr, NULL)
#define ASSERT_ARG2(expr, msg)             ASSERT_EXT(expr, msg)
#define ASSERT_ARG3(arg1, arg2, arg3, ...) arg3

#define ASSERT_CHOOSER(...) ASSERT_ARG3(__VA_ARGS__, ASSERT_ARG2, ASSERT_ARG1)
#define ASSERT(...) do { ASSERT_CHOOSER(__VA_ARGS__)(__VA_ARGS__) } while (0);

#define TEST_SUCCESS  return (test_status_t){NULL, 1};

#define TEST_IMPL(FUN)                                                        \
  test_status_t test_ ## FUN (void);                                          \
  test_status_t test_ ## FUN()

#endif /* common_h */
