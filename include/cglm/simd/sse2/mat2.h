/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat2_sse_h
#define cglm_mat2_sse_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat2_mul_sse2(mat2 m1, mat2 m2, mat2 dest) {
  __m128 x0, x1, x2, x3, x4;

  x1 = glmm_load(m1[0]); /* d c b a */
  x2 = glmm_load(m2[0]); /* h g f e */

  x3 = glmm_shuff1(x2, 2, 2, 0, 0);
  x4 = glmm_shuff1(x2, 3, 3, 1, 1);
  x0 = _mm_movelh_ps(x1, x1);
  x2 = _mm_movehl_ps(x1, x1);

  /*
   dest[0][0] = a * e + c * f;
   dest[0][1] = b * e + d * f;
   dest[1][0] = a * g + c * h;
   dest[1][1] = b * g + d * h;
   */
  x0 = glmm_fmadd(x0, x3, _mm_mul_ps(x2, x4));

  glmm_store(dest[0], x0);
}

CGLM_INLINE
void
glm_mat2_transp_sse2(mat2 m, mat2 dest) {
  /* d c b a */
  /* d b c a */
  glmm_store(dest[0], glmm_shuff1(glmm_load(m[0]), 3, 1, 2, 0));
}

#endif
#endif /* cglm_mat2_sse_h */
