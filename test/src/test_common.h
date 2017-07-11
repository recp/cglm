/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef test_common_h
#define test_common_h

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#include <cglm.h>
#include <cglm-call.h>

void
test_rand_mat4(mat4 dest);

void
test_assert_mat4_eq(mat4 m1, mat4 m2);

#endif /* test_common_h */
