/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_wasm_h
#define cglm_quat_wasm_h
#if defined(__wasm__) && defined(__wasm_simd128__)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_quat_mul_wasm(versor p, versor q, versor dest) {
  /*
   + (a1 b2 + b1 a2 + c1 d2 − d1 c2)i
   + (a1 c2 − b1 d2 + c1 a2 + d1 b2)j
   + (a1 d2 + b1 c2 − c1 b2 + d1 a2)k
     a1 a2 − b1 b2 − c1 c2 − d1 d2
   */

  glmm_128 xp, xq, x1, x2, x3, r, x, y, z;

  xp = glmm_load(p); /* 3 2 1 0 */
  xq = glmm_load(q);
  /* x1 = wasm_f32x4_const(0.f, -0.f, 0.f, -0.f); */
  x1 = glmm_float32x4_SIGNMASK_PNPN; /* TODO: _mm_set1_ss() + shuff ? */
  r  = wasm_f32x4_mul(glmm_splat_w(xp), xq);
  /* x2 = _mm_unpackhi_ps(x1, x1); */
  x2 = wasm_i32x4_shuffle(x1, x1, 2, 6, 3, 7);
  x3 = glmm_shuff1(x1, 3, 2, 0, 1);
  x  = glmm_splat_x(xp);
  y  = glmm_splat_y(xp);
  z  = glmm_splat_z(xp);

  x  = wasm_v128_xor(x, x1);
  y  = wasm_v128_xor(y, x2);
  z  = wasm_v128_xor(z, x3);
  
  x1 = glmm_shuff1(xq, 0, 1, 2, 3);
  x2 = glmm_shuff1(xq, 1, 0, 3, 2);
  x3 = glmm_shuff1(xq, 2, 3, 0, 1);
  
  r  = glmm_fmadd(x, x1, r);
  r  = glmm_fmadd(y, x2, r);
  r  = glmm_fmadd(z, x3, r);

  glmm_store(dest, r);
}

#endif
#endif /* cglm_quat_wasm_h */
