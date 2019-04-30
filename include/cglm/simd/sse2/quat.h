/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_simd_h
#define cglm_quat_simd_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_quat_mul_sse2(versor p, versor q, versor dest) {
  /*
   + (a1 b2 + b1 a2 + c1 d2 − d1 c2)i
   + (a1 c2 − b1 d2 + c1 a2 + d1 b2)j
   + (a1 d2 + b1 c2 − c1 b2 + d1 a2)k
     a1 a2 − b1 b2 − c1 c2 − d1 d2
   */

  __m128 xp, xq, x0, r;

  xp = glmm_load(p); /* 3 2 1 0 */
  xq = glmm_load(q);

  r  = _mm_mul_ps(glmm_shuff1x(xp, 3), xq);

  x0 = _mm_xor_ps(glmm_shuff1x(xp, 0), _mm_set_ps(-0.f, 0.f, -0.f, 0.f));
  r  = _mm_add_ps(r, _mm_mul_ps(x0, glmm_shuff1(xq, 0, 1, 2, 3)));

  x0 = _mm_xor_ps(glmm_shuff1x(xp, 1), _mm_set_ps(-0.f, -0.f, 0.f, 0.f));
  r  = _mm_add_ps(r, _mm_mul_ps(x0, glmm_shuff1(xq, 1, 0, 3, 2)));

  x0 = _mm_xor_ps(glmm_shuff1x(xp, 2), _mm_set_ps(-0.f, 0.f, 0.f, -0.f));
  r  = _mm_add_ps(r, _mm_mul_ps(x0, glmm_shuff1(xq, 2, 3, 0, 1)));

  glmm_store(dest, r);
}


#endif
#endif /* cglm_quat_simd_h */
