/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef tests_common_h
#define tests_common_h

#ifndef _USE_MATH_DEFINES
#  define _USE_MATH_DEFINES       /* for windows */
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#  define _CRT_SECURE_NO_WARNINGS /* for windows */
#endif

#ifndef _GNU_SOURCE
#  define _GNU_SOURCE /* for drand48() */
#endif

#ifndef CGLM_CLIPSPACE_INCLUDE_ALL
#  define CGLM_CLIPSPACE_INCLUDE_ALL
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

#ifndef GLM_TESTS_NO_COLORFUL_OUTPUT

#define RESET       "\033[0m"
#define BLACK       "\033[30m"             /* Black */
#define RED         "\033[31m"             /* Red */
#define GREEN       "\033[32m"             /* Green */
#define YELLOW      "\033[33m"             /* Yellow */
#define BLUE        "\033[34m"             /* Blue */
#define MAGENTA     "\033[35m"             /* Magenta */
#define CYAN        "\033[36m"             /* Cyan */
#define WHITE       "\033[37m"             /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#else

#define RESET
#define BLACK
#define RED
#define GREEN
#define YELLOW
#define BLUE
#define MAGENTA
#define CYAN
#define WHITE
#define BOLDBLACK
#define BOLDRED
#define BOLDGREEN
#define BOLDYELLOW
#define BOLDBLUE
#define BOLDMAGENTA
#define BOLDCYAN
#define BOLDWHITE

#endif

#define TEST_DECLARE(FUN) test_status_t test_ ## FUN(void);
#define TEST_ENTRY(FUN)   { #FUN, test_ ## FUN, 0, 0 },
#define TEST_LIST         static test_entry_t tests[] = 

/* __VA_ARGS__ workaround for MSVC: https://stackoverflow.com/a/5134656 */
#define EXPAND(x) x

#define TEST_OK 1
#define TEST_SUCCESS  return (test_status_t){NULL, TEST_OK};

#define TEST_IMPL_ARG1(FUN) \
  test_status_t test_ ## FUN (void);                                          \
  test_status_t test_ ## FUN()

#define TEST_IMPL_ARG2(PREFIX, FUN) TEST_IMPL_ARG1(PREFIX ## FUN)
#define TEST_IMPL_ARG3(arg1, arg2, arg3, ...) arg3

#define TEST_IMPL_CHOOSER(...)                                                \
  EXPAND(TEST_IMPL_ARG3(__VA_ARGS__, TEST_IMPL_ARG2, TEST_IMPL_ARG1))

#define TEST_IMPL(...) EXPAND(TEST_IMPL_CHOOSER(__VA_ARGS__)(__VA_ARGS__))

#define ASSERT_EXT(expr, msg)                                                 \
  if (!(expr)) {                                                              \
    fprintf(stderr,                                                           \
            RED "  assert fail" RESET                                         \
            " in " BOLDCYAN "%s " RESET                                       \
            "on " BOLDMAGENTA "line %d" RESET                                 \
            " : " BOLDWHITE " ASSERT(%s)\n" RESET,                            \
            __FILE__,                                                         \
            __LINE__,                                                         \
            #expr);                                                           \
    return (test_status_t){msg, 0};                                           \
  }

#define ASSERT_ARG1(expr)                  ASSERT_EXT(expr, NULL)
#define ASSERT_ARG2(expr, msg)             ASSERT_EXT(expr, msg)
#define ASSERT_ARG3(arg1, arg2, arg3, ...) arg3

#define ASSERT_CHOOSER(...) ASSERT_ARG3(__VA_ARGS__, ASSERT_ARG2, ASSERT_ARG1)
#define ASSERT(...) do { ASSERT_CHOOSER(__VA_ARGS__)(__VA_ARGS__) } while(0);
#define ASSERTIFY(expr) do {                                                  \
    test_status_t ts; \
    ts = expr; \
    if (ts.status != TEST_OK) {                                               \
      fprintf(stderr,                                                         \
              RED "  assert fail" RESET                                       \
              " in " BOLDCYAN "%s " RESET                                     \
              "on " BOLDMAGENTA "line %d" RESET                               \
              " : " BOLDWHITE " ASSERTIFY(%s)\n" RESET,                       \
              __FILE__,                                                       \
              __LINE__,                                                       \
              #expr);                                                         \
      return (test_status_t){ts.msg, 0};                                      \
    } \
  } while(0);

#if defined(_WIN32)
# define drand48()  ((float)(rand() / (RAND_MAX + 1.0)))
# define OK_TEXT    "ok:"
# define FAIL_TEXT  "fail:"
# define FINAL_TEXT "^_^"
#else
# define OK_TEXT    "✔︎"
# define FAIL_TEXT  "𐄂"
# define FINAL_TEXT "🎉"
#endif

#endif /* common_h */
