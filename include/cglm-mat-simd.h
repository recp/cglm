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
float
glm_mat4_det_sse2(mat4 mat) {
  __m128 v0, dt, t0, t1, t2, t3, t4, r0, r1, r2, r3;

  
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

  dt = _mm_mul_ps(_mm_shuffle1_ps(r0, 0, 1, 2, 3), v0);
  dt = _mm_add_ps(dt, _mm_shuffle1_ps(dt, 0, 1, 2, 3));
  dt = _mm_add_ps(dt, _mm_shuffle1_ps(dt, 1, 3, 3, 1));

  return _mm_cvtss_f32(dt);
}

CGLM_INLINE
void
glm_mat4_inv_see2(mat4 mat, mat4 dest) {
  __m128 r0, r1, r2, r3,
         v0, v1, v2, v3,
         t0, t1, t2, t3, t4, t5,
         x0, x1, x2, x3, x4, x5, x6, x7;

  /* 127 <- 0 */
  r0 = _mm_load_ps(mat[0]); /* d c b a */
  r1 = _mm_load_ps(mat[1]); /* h g f e */
  r2 = _mm_load_ps(mat[2]); /* l k j i */
  r3 = _mm_load_ps(mat[3]); /* p o n m */

  x0 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(3, 2, 3, 2));  /* p o l k */
  x1 = _mm_shuffle1_ps(x0, 1, 3, 3, 3);                  /* l p p p */
  x2 = _mm_shuffle1_ps(x0, 0, 2, 2, 2);                  /* k o o o */
  x0 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(3, 3, 3, 3));  /* h h l l */
  x3 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(2, 2, 2, 2));  /* g g k k */

  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = _mm_sub_ps(_mm_mul_ps(x3, x1), _mm_mul_ps(x2, x0));

  x4 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(2, 1, 2, 1)); /* o n k j */
  x4 = _mm_shuffle1_ps(x4, 0, 2, 2, 2);                 /* j n n n */
  x5 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(1, 1, 1, 1)); /* f f j j */

  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
  t1 = _mm_sub_ps(_mm_mul_ps(x5, x1), _mm_mul_ps(x4, x0));

  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = _mm_sub_ps(_mm_mul_ps(x5, x2), _mm_mul_ps(x4, x3));

  x6 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(0, 0, 0, 0)); /* e e i i */
  x7 = _mm_shuffle2_ps(r3, r2, 0, 0, 0, 0, 2, 0, 0, 0); /* i m m m */

  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = _mm_sub_ps(_mm_mul_ps(x6, x1), _mm_mul_ps(x7, x0));

  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = _mm_sub_ps(_mm_mul_ps(x6, x2), _mm_mul_ps(x7, x3));

  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = _mm_sub_ps(_mm_mul_ps(x6, x4), _mm_mul_ps(x7, x5));

  x0 = _mm_shuffle2_ps(r1, r0, 0, 0, 0, 0, 2, 2, 2, 0); /* a a a e */
  x1 = _mm_shuffle2_ps(r1, r0, 1, 1, 1, 1, 2, 2, 2, 0); /* b b b f */
  x2 = _mm_shuffle2_ps(r1, r0, 2, 2, 2, 2, 2, 2, 2, 0); /* c c c g */
  x3 = _mm_shuffle2_ps(r1, r0, 3, 3, 3, 3, 2, 2, 2, 0); /* d d d h */

  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = _mm_add_ps(_mm_mul_ps(x3, t2),
                  _mm_sub_ps(_mm_mul_ps(x1, t0),
                             _mm_mul_ps(x2, t1)));
  v0 = _mm_xor_ps(v0, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = _mm_add_ps(_mm_mul_ps(x3, t4),
                  _mm_sub_ps(_mm_mul_ps(x0, t0),
                             _mm_mul_ps(x2, t3)));
  v1 = _mm_xor_ps(v1, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = _mm_add_ps(_mm_mul_ps(x3, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t1),
                             _mm_mul_ps(x1, t3)));
  v2 = _mm_xor_ps(v2, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = _mm_add_ps(_mm_mul_ps(x2, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t2),
                             _mm_mul_ps(x1, t4)));
  v3 = _mm_xor_ps(v3, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /* determinant */
  x0 = _mm_shuffle_ps(v0, v1, _MM_SHUFFLE(0, 0, 0, 0));
  x1 = _mm_shuffle_ps(v2, v3, _MM_SHUFFLE(0, 0, 0, 0));
  x0 = _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 0, 2, 0));

  x0 = _mm_mul_ps(x0, r0);
  x0 = _mm_add_ps(x0, _mm_shuffle1_ps(x0, 0, 1, 2, 3));
  x0 = _mm_add_ps(x0, _mm_shuffle1_ps(x0, 1, 0, 0, 1));
  x0 = _mm_rcp_ps(x0);

  _mm_store_ps(dest[0], _mm_mul_ps(v0, x0));
  _mm_store_ps(dest[1], _mm_mul_ps(v1, x0));
  _mm_store_ps(dest[2], _mm_mul_ps(v2, x0));
  _mm_store_ps(dest[3], _mm_mul_ps(v3, x0));
}

#endif /* cglm_mat_sse_h */
