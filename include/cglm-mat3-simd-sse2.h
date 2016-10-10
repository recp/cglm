/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat3_sse_h
#define cglm_mat3_sse_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "cglm-intrin.h"

CGLM_INLINE
void
glm_mat3_transp_to_sse2(mat3 m, mat3 dest){
  __m128 x0, x1, x2, x3, x4;
  /*
   a b c d        a d g b
   e f g h   ->   e h c f
   j              j
   */

  /* d c b a */
  /* h g f e */
  x0 = _mm_loadu_ps(&m[0][0]);
  x1 = _mm_loadu_ps(&m[1][1]);

  /* g g b b */
  /* a d g b */
  x2 = _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 2, 1, 1));
  x3 = _mm_shuffle_ps(x0, x2, _MM_SHUFFLE(0, 2, 3, 0));

  /* c c f f */
  /* e h c f */
  x2 = _mm_shuffle_ps(x1, x0, _MM_SHUFFLE(2, 2, 1, 1));
  x4 = _mm_shuffle_ps(x1, x2, _MM_SHUFFLE(0, 2, 3, 0));

  _mm_storeu_ps(&dest[0][0], x3);
  _mm_storeu_ps(&dest[1][1], x4);

  dest[2][2] = m[2][2];
}

CGLM_INLINE
void
glm_mat3_transp_sse2(mat3 m){
  __m128 x0, x1, x2, x3, x4;
  /*
   a b c d        a d g b
   e f g h   ->   e h c f
   j              j
   */

  /* d c b a */
  /* h g f e */
  x0 = _mm_loadu_ps(&m[0][0]);
  x1 = _mm_loadu_ps(&m[1][1]);

  /* g g b b */
  /* a d g b */
  x2 = _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 2, 1, 1));
  x3 = _mm_shuffle_ps(x0, x2, _MM_SHUFFLE(0, 2, 3, 0));

  /* c c f f */
  /* e h c f */
  x2 = _mm_shuffle_ps(x1, x0, _MM_SHUFFLE(2, 2, 1, 1));
  x4 = _mm_shuffle_ps(x1, x2, _MM_SHUFFLE(0, 2, 3, 0));

  _mm_storeu_ps(&m[0][0], x3);
  _mm_storeu_ps(&m[1][1], x4);
}

CGLM_INLINE
void
glm_mat3_mul_sse2(mat3 m1, mat3 m2, mat3 dest) {
  __m128 l0, l1, l2;
  __m128 r0, r1, r2;
  __m128 x0, x1, x2;

  l0 = _mm_loadu_ps(m1[0]);
  l1 = _mm_loadu_ps(&m1[1][1]);
  l2 = _mm_set1_ps(m1[2][2]);

  r0 = _mm_loadu_ps(m2[0]);
  r1 = _mm_loadu_ps(&m2[1][1]);
  r2 = _mm_set1_ps(m2[2][2]);

  x1 = _mm_shuffle2_ps(l0, l1, 1, 0, 3, 3, 0, 3, 2, 0);
  x2 = _mm_shuffle2_ps(l1, l2, 0, 0, 3, 2, 0, 2, 1, 0);

  x0 = _mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps(l0, 0, 2, 1, 0),
                             _mm_shuffle1_ps(r0, 3, 0, 0, 0)),
                  _mm_mul_ps(x1,
                             _mm_shuffle2_ps(r0, r1, 0, 0, 1, 1, 2, 0, 0, 0)));

  x0 = _mm_add_ps(x0,
                  _mm_mul_ps(x2,
                             _mm_shuffle2_ps(r0, r1, 1, 1, 2, 2, 2, 0, 0, 0)));

  _mm_storeu_ps(dest[0], x0);

  x0 = _mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps(l0, 1, 0, 2, 1),
                             _mm_shuffle_ps(r0, r1, _MM_SHUFFLE(2, 2, 3, 3))),
                  _mm_mul_ps(_mm_shuffle1_ps(x1, 1, 0, 2, 1),
                             _mm_shuffle1_ps(r1, 3, 3, 0, 0)));

  x0 = _mm_add_ps(x0,
                  _mm_mul_ps(_mm_shuffle1_ps(x2, 1, 0, 2, 1),
                             _mm_shuffle_ps(r1, r2, _MM_SHUFFLE(0, 0, 1, 1))));

  _mm_storeu_ps(&dest[1][1], x0);

  dest[2][2] = m1[0][2] * m2[2][0]
             + m1[1][2] * m2[2][1]
             + m1[2][2] * m2[2][2];
}

#endif
#endif /* cglm_mat3_sse_h */
