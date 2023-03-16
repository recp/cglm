/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat2_neon_h
#define cglm_mat2_neon_h
#if defined(CGLM_NEON_FP)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat2_mul_neon(mat2 m1, mat2 m2, mat2 dest) {
  float32x4x2_t a1;
  glmm_128 x0,  x1, x2;
  float32x2_t   dc, ba;

  x1 = glmm_load(m1[0]); /* d c b a */
  x2 = glmm_load(m2[0]); /* h g f e */
  
  dc = vget_high_f32(x1);
  ba = vget_low_f32(x1);

  /* g g e e, h h f f */
  a1 = vtrnq_f32(x2, x2);
  
  /*
   dest[0][0] = a * e + c * f;
   dest[0][1] = b * e + d * f;
   dest[1][0] = a * g + c * h;
   dest[1][1] = b * g + d * h;
   */
  x0 = glmm_fmadd(vcombine_f32(ba, ba), a1.val[0],
                  vmulq_f32(vcombine_f32(dc, dc), a1.val[1]));

  glmm_store(dest[0], x0);
}

#endif
#endif /* cglm_mat2_neon_h */
