/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_neon_h
#define cglm_quat_neon_h
#if defined(CGLM_NEON_FP)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_quat_mul_neon(versor p, versor q, versor dest) {
  /*
   + (a1 b2 + b1 a2 + c1 d2 − d1 c2)i
   + (a1 c2 − b1 d2 + c1 a2 + d1 b2)j
   + (a1 d2 + b1 c2 − c1 b2 + d1 a2)k
     a1 a2 − b1 b2 − c1 c2 − d1 d2
   */

  glmm_128 xp, xq, xqr, r, x, y, z, s2, s3;
  glmm_128 s1 = glmm_float32x4_SIGNMASK_NPPN;

  float32x2_t   qh, ql;
  
  xp  = glmm_load(p); /* 3 2 1 0 */
  xq  = glmm_load(q);

  r   = vmulq_f32(glmm_splat_w(xp), xq);
  x   = glmm_splat_x(xp);
  y   = glmm_splat_y(xp);
  z   = glmm_splat_z(xp);

  ql  = vget_high_f32(s1);
  s3  = vcombine_f32(ql, ql);
  s2  = vzipq_f32(s3, s3).val[0];

  xqr = vrev64q_f32(xq);
  qh  = vget_high_f32(xqr);
  ql  = vget_low_f32(xqr);

  r = glmm_fmadd(glmm_xor(x, s3), vcombine_f32(qh, ql), r);
  
  r = glmm_fmadd(glmm_xor(y, s2), vcombine_f32(vget_high_f32(xq),
                                               vget_low_f32(xq)), r);
  
  r = glmm_fmadd(glmm_xor(z, s1), vcombine_f32(ql, qh), r);

  glmm_store(dest, r);
}

#endif
#endif /* cglm_quat_neon_h */
