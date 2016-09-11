/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_h
#define cglm_mat_h

#include "cglm.h"
#include "cglm-mat-simd.h"

#define GLM_MAT_IDENTITY_4F {1.0f, 0.0f, 0.0f, 0.0f,                          \
                             0.0f, 1.0f, 0.0f, 0.0f,                          \
                             0.0f, 0.0f, 1.0f, 0.0f,                          \
                             0.0f, 0.0f, 0.0f, 1.0f}

#define glm_mat_mul4_impl(l, r, d)                                            \
 do {                                                                         \
    d[0]  = l[0]  * r[0] + l[1]  * r[4] + l[2]  * r[8]  + l[3]  * r[12];      \
    d[1]  = l[0]  * r[1] + l[1]  * r[5] + l[2]  * r[9]  + l[3]  * r[13];      \
    d[2]  = l[0]  * r[2] + l[1]  * r[6] + l[2]  * r[10] + l[3]  * r[14];      \
    d[3]  = l[0]  * r[3] + l[1]  * r[7] + l[2]  * r[11] + l[3]  * r[15];      \
    d[4]  = l[4]  * r[0] + l[5]  * r[4] + l[6]  * r[8]  + l[7]  * r[12];      \
    d[5]  = l[4]  * r[1] + l[5]  * r[5] + l[6]  * r[9]  + l[7]  * r[13];      \
    d[6]  = l[4]  * r[2] + l[5]  * r[6] + l[6]  * r[10] + l[7]  * r[14];      \
    d[7]  = l[4]  * r[3] + l[5]  * r[7] + l[6]  * r[11] + l[7]  * r[15];      \
    d[8]  = l[8]  * r[0] + l[9]  * r[4] + l[10] * r[8]  + l[11] * r[12];      \
    d[9]  = l[8]  * r[1] + l[9]  * r[5] + l[10] * r[9]  + l[11] * r[13];      \
    d[10] = l[8]  * r[2] + l[9]  * r[6] + l[10] * r[10] + l[11] * r[14];      \
    d[11] = l[8]  * r[3] + l[9]  * r[7] + l[10] * r[11] + l[11] * r[15];      \
    d[12] = l[12] * r[0] + l[13] * r[4] + l[14] * r[8]  + l[15] * r[12];      \
    d[13] = l[12] * r[1] + l[13] * r[5] + l[14] * r[9]  + l[15] * r[13];      \
    d[14] = l[12] * r[2] + l[13] * r[6] + l[14] * r[10] + l[15] * r[14];      \
    d[15] = l[12] * r[3] + l[13] * r[7] + l[14] * r[11] + l[15] * r[15];      \
  } while (0)

CGLM_INLINE
void
glm_mat_mul4(mat4 m1, mat4 m2, mat4 dest) {
  float * __restrict d;
  float * __restrict l;

  d = (float *)dest;
  l = (float *)m1;

  if (m1 != m2) {
    float * __restrict r;

    r = (float *)m2;

#if defined( __SSE__ ) || defined( __SSE2__ )
    CGLM_MAT_MUL_SSE_4x4f(l, r, d);
#else
    glm_mat_mul4_impl(l, r, d);
#endif
  } else {
#if defined( __SSE__ ) || defined( __SSE2__ )
    CGLM_MAT_MUL_SSE_4x4f(l, l, d);
#else
    glm_mat_mul4_impl(l, l, d);
#endif
  }
}

#endif /* cglm_mat_h */
