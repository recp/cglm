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

  __m128 xp, xq, x1, x2, x3, r, x, y, z;

  xp = glmm_load(p); /* 3 2 1 0 */
  xq = glmm_load(q);
  x1 = _mm_set_ps(-0.f, 0.f, -0.f, 0.f); /* TODO: _mm_set1_ss() + shuff ? */
  r  = _mm_mul_ps(glmm_splat_w(xp), xq);
  
  x2 = _mm_unpackhi_ps(x1, x1);
  x3 = glmm_shuff1(x1, 3, 2, 0, 1);
  x  = glmm_splat_x(xp);
  y  = glmm_splat_y(xp);
  z  = glmm_splat_z(xp);

  x  = _mm_xor_ps(x, x1);
  y  = _mm_xor_ps(y, x2);
  z  = _mm_xor_ps(z, x3);
  
  x1 = glmm_shuff1(xq, 0, 1, 2, 3);
  x2 = glmm_shuff1(xq, 1, 0, 3, 2);
  x3 = glmm_shuff1(xq, 2, 3, 0, 1);
  
  r  = glmm_fmadd(x, x1, r);
  r  = glmm_fmadd(y, x2, r);
  r  = glmm_fmadd(z, x3, r);

  glmm_store(dest, r);
}

#endif
#endif /* cglm_quat_simd_h */
