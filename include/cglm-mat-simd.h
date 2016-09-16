/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_sse_h
#define cglm_mat_sse_h

#include "cglm-intrin.h"

#define CGLM_MAT_MUL_SSE_4x4f(L, R, D)                                        \
   do {                                                                       \
      __m128 r0;                                                              \
      __m128 r1;                                                              \
      __m128 r2;                                                              \
      __m128 r3;                                                              \
                                                                              \
      r0 = _mm_load_ps(R);                                                    \
      r1 = _mm_load_ps(R + 4);                                                \
      r2 = _mm_load_ps(R + 8);                                                \
      r3 = _mm_load_ps(R + 12);                                               \
                                                                              \
      _mm_store_ps(D,      _mm_madd4_ps(L,      r0, r1, r2, r3));             \
      _mm_store_ps(D + 4,  _mm_madd4_ps(L + 4,  r0, r1, r2, r3));             \
      _mm_store_ps(D + 8,  _mm_madd4_ps(L + 8,  r0, r1, r2, r3));             \
      _mm_store_ps(D + 12, _mm_madd4_ps(L + 12, r0, r1, r2, r3));             \
   } while (0)

#define CGLM_MAT_TRANSP_SSE_4x4f(M, D)                                        \
   do {                                                                       \
      __m128 r0;                                                              \
      __m128 r1;                                                              \
      __m128 r2;                                                              \
      __m128 r3;                                                              \
                                                                              \
      r0 = _mm_load_ps(M[0]);                                                 \
      r1 = _mm_load_ps(M[1]);                                                 \
      r2 = _mm_load_ps(M[2]);                                                 \
      r3 = _mm_load_ps(M[3]);                                                 \
                                                                              \
      _MM_TRANSPOSE4_PS(r0, r1, r2, r3);                                      \
                                                                              \
      _mm_store_ps(D[0], r0);                                                 \
      _mm_store_ps(D[1], r1);                                                 \
      _mm_store_ps(D[2], r2);                                                 \
      _mm_store_ps(D[3], r3);                                                 \
   } while (0)

#define CGLM_MAT_SCALE_SSE_4x4f(M, S)                                         \
   do {                                                                       \
     __m128 xmm0;                                                             \
     xmm0 = _mm_set1_ps(S);                                                   \
     _mm_store_ps(M[0], _mm_mul_ps(_mm_load_ps(M[0]), xmm0));                 \
     _mm_store_ps(M[1], _mm_mul_ps(_mm_load_ps(M[1]), xmm0));                 \
     _mm_store_ps(M[2], _mm_mul_ps(_mm_load_ps(M[2]), xmm0));                 \
     _mm_store_ps(M[3], _mm_mul_ps(_mm_load_ps(M[3]), xmm0));                 \
   } while (0)

CGLM_INLINE
void
glm_mat4_inv_see2(mat4 mat, mat4 dest) {
  __m128 v0, v1, v2, v3, dt, t0, t1, t2, t3, t4, r0, r1, r2, r3, r4;

  r0 = _mm_load_ps(mat[0]);
  r1 = _mm_load_ps(mat[1]);
  r2 = _mm_load_ps(mat[2]);
  r3 = _mm_load_ps(mat[3]);

  t3 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r2, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r3, 3, 3, 2, 3)),
                  _mm_mul_ps(_mm_shuffle1_ps(r3, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r2, 3, 3, 2, 3)));

  t4 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r2, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r3, 2, 1, 2, 1)),
                  _mm_mul_ps(_mm_shuffle1_ps(r3, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r2, 2, 1, 2, 1)));

  t0 = _mm_shuffle1_ps(t3, 3, 3, 2, 1);
  t1 = _mm_shuffle2_ps(t3, t4, 1, 1, 2, 0, 1, 0, 0, 3);
  t2 = _mm_shuffle2_ps(t3, t4, 0, 1, 1, 1, 0, 2, 3, 3);

  v0 = _mm_mul_ps(_mm_shuffle1_ps(r1, 1, 0, 0, 0), t0);
  v0 = _mm_sub_ps(v0, _mm_mul_ps(_mm_shuffle1_ps(r1, 2, 2, 1, 1), t1));
  v0 = _mm_add_ps(v0, _mm_mul_ps(_mm_shuffle1_ps(r1, 3, 3, 3, 2), t2));
  v0 = _mm_xor_ps(v0, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  v1 = _mm_mul_ps(_mm_shuffle1_ps(r0, 1, 0, 0, 0), t0);
  v1 = _mm_sub_ps(v1, _mm_mul_ps(_mm_shuffle1_ps(r0, 2, 2, 1, 1), t1));
  v1 = _mm_add_ps(v1, _mm_mul_ps(_mm_shuffle1_ps(r0, 3, 3, 3, 2), t2));
  v1 = _mm_xor_ps(v1, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  t3 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r1, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r3, 3, 3, 2, 3)),
                  _mm_mul_ps(_mm_shuffle1_ps(r3, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r1, 3, 3, 2, 3)));

  t4 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r1, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r3, 2, 1, 2, 1)),
                  _mm_mul_ps(_mm_shuffle1_ps(r3, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r1, 2, 1, 2, 1)));

  t0 = _mm_shuffle1_ps(t3, 3, 3, 2, 1);
  t1 = _mm_shuffle2_ps(t3, t4, 1, 1, 2, 0, 1, 0, 0, 3);
  t2 = _mm_shuffle2_ps(t3, t4, 0, 1, 1, 1, 0, 2, 3, 3);

  v2 = _mm_mul_ps(_mm_shuffle1_ps(r0, 1, 0, 0, 0), t0);
  v2 = _mm_sub_ps(v2, _mm_mul_ps(_mm_shuffle1_ps(r0, 2, 2, 1, 1), t1));
  v2 = _mm_add_ps(v2, _mm_mul_ps(_mm_shuffle1_ps(r0, 3, 3, 3, 2), t2));
  v2 = _mm_xor_ps(v2, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  t3 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r1, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r2, 3, 3, 2, 3)),
                  _mm_mul_ps(_mm_shuffle1_ps(r2, 2, 1, 1, 0),
                             _mm_shuffle1_ps(r1, 3, 3, 2, 3)));

  t4 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle1_ps(r1, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r2, 2, 1, 2, 1)),
                  _mm_mul_ps(_mm_shuffle1_ps(r2, 0, 0, 0, 0),
                             _mm_shuffle1_ps(r1, 2, 1, 2, 1)));

  t0 = _mm_shuffle1_ps(t3, 3, 3, 2, 1);
  t1 = _mm_shuffle2_ps(t3, t4, 1, 1, 2, 0, 1, 0, 0, 3);
  t2 = _mm_shuffle2_ps(t3, t4, 0, 1, 1, 1, 0, 2, 3, 3);

  v3 = _mm_mul_ps(_mm_shuffle1_ps(r0, 1, 0, 0, 0), t0);
  v3 = _mm_sub_ps(v3, _mm_mul_ps(_mm_shuffle1_ps(r0, 2, 2, 1, 1), t1));
  v3 = _mm_add_ps(v3, _mm_mul_ps(_mm_shuffle1_ps(r0, 3, 3, 3, 2), t2));
  v3 = _mm_xor_ps(v3, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  dt = _mm_mul_ps(_mm_shuffle1_ps(r0, 0, 1, 2, 3), v0);
  dt = _mm_add_ps(dt, _mm_shuffle1_ps(dt, 0, 1, 2, 3));
  dt = _mm_add_ps(dt, _mm_shuffle1_ps(dt, 1, 3, 3, 1));
  dt = _mm_rcp_ps(dt);

  v0 = _mm_shuffle1_ps(v0, 0, 1, 2, 3);
  v1 = _mm_shuffle1_ps(v1, 0, 1, 2, 3);
  v2 = _mm_shuffle1_ps(v2, 0, 1, 2, 3);
  v3 = _mm_shuffle1_ps(v3, 0, 1, 2, 3);

  _mm_store_ps(dest[0], _mm_mul_ps(v0, dt));
  _mm_store_ps(dest[1], _mm_mul_ps(v1, dt));
  _mm_store_ps(dest[2], _mm_mul_ps(v2, dt));
  _mm_store_ps(dest[3], _mm_mul_ps(v3, dt));
}

#endif /* cglm_mat_sse_h */
