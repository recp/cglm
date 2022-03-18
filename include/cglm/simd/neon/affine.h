/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_neon_h
#define cglm_affine_neon_h
#if defined(__ARM_NEON_FP)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mul_neon(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  glmm_128 l, r0, r1, r2, r3, v0, v1, v2, v3;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);
  r3 = glmm_load(m2[3]);

  v0 = vmulq_f32(glmm_splat_x(r0), l);
  v1 = vmulq_f32(glmm_splat_x(r1), l);
  v2 = vmulq_f32(glmm_splat_x(r2), l);
  v3 = vmulq_f32(glmm_splat_x(r3), l);

  l  = glmm_load(m1[1]);
  v0 = glmm_fmadd(glmm_splat_y(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_y(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_y(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_y(r3), l, v3);

  l  = glmm_load(m1[2]);
  v0 = glmm_fmadd(glmm_splat_z(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_z(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_z(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_z(r3), l, v3);

  v3 = glmm_fmadd(glmm_splat_w(r3), glmm_load(m1[3]), v3);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], v3);
}

CGLM_INLINE
void
glm_mul_rot_neon(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  glmm_128 l, r0, r1, r2, v0, v1, v2;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);

  v0 = vmulq_f32(glmm_splat_x(r0), l);
  v1 = vmulq_f32(glmm_splat_x(r1), l);
  v2 = vmulq_f32(glmm_splat_x(r2), l);

  l  = glmm_load(m1[1]);
  v0 = glmm_fmadd(glmm_splat_y(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_y(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_y(r2), l, v2);
  
  l  = glmm_load(m1[2]);
  v0 = glmm_fmadd(glmm_splat_z(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_z(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_z(r2), l, v2);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], glmm_load(m1[3]));
}

CGLM_INLINE
void
glm_inv_tr_neon(mat4 mat) {
  float32x4x4_t vmat;
  glmm_128      r0, r1, r2, x0;

  vmat = vld4q_f32(mat[0]);
  r0   = vmat.val[0];
  r1   = vmat.val[1];
  r2   = vmat.val[2];

  x0 = glmm_fmadd(r0, glmm_splat_w(r0),
                  glmm_fmadd(r1, glmm_splat_w(r1),
                             vmulq_f32(r2, glmm_splat_w(r2))));
  x0 = vnegq_f32(x0);

  glmm_store(mat[0], r0);
  glmm_store(mat[1], r1);
  glmm_store(mat[2], r2);
  glmm_store(mat[3], x0);
  
  mat[0][3] = 0.0f;
  mat[1][3] = 0.0f;
  mat[2][3] = 0.0f;
  mat[3][3] = 1.0f;

  /* TODO: ?
  zo   = vget_high_f32(r3);
  vst1_lane_f32(&mat[0][3], zo, 0);
  vst1_lane_f32(&mat[1][3], zo, 0);
  vst1_lane_f32(&mat[2][3], zo, 0);
  vst1_lane_f32(&mat[3][3], zo, 1);
  */
}

#endif
#endif /* cglm_affine_neon_h */
