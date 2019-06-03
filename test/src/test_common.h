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

#include <cglm/cglm.h>
#include <cglm/struct.h>
#include <cglm/call.h>

void
test_rand_mat4(mat4 dest);

void
test_rand_mat3(mat3 dest);

void
test_assert_eqf(float a, float b);

void
test_assert_mat4_eq(mat4 m1, mat4 m2);

void
test_assert_mat4_eq2(mat4 m1, mat4 m2, float eps);

void
test_assert_mat3_eq(mat3 m1, mat3 m2);

void
test_assert_vec3_eq(vec3 v1, vec3 v2);

void
test_assert_vec3s_eq(vec3s v1, vec3s v2);

void
test_assert_vec4_eq(vec4 v1, vec4 v2);

void
test_assert_vec4s_eq(vec4s v1, vec4s v2);

void
test_assert_quat_eq(versor v1, versor v2);

void
test_assert_quat_eq_abs(versor v1, versor v2);

void
test_rand_vec3(vec3 dest);

vec3s
test_rand_vec3s(void);

void
test_rand_vec4(vec4 dest);

vec4s
test_rand_vec4s(void);

float
test_rand(void);

void
test_rand_quat(versor q);

#endif /* test_common_h */
