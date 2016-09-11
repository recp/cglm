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

#endif /* cglm_mat_sse_h */
