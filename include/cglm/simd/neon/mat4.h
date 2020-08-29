/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat4_neon_h
#define cglm_mat4_neon_h
#if defined(__ARM_NEON_FP)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat4_scale_neon(mat4 m, float s) {
  float32x4_t v0;
  
  v0 = vdupq_n_f32(s);

  vst1q_f32(m[0], vmulq_f32(vld1q_f32(m[0]), v0));
  vst1q_f32(m[1], vmulq_f32(vld1q_f32(m[1]), v0));
  vst1q_f32(m[2], vmulq_f32(vld1q_f32(m[2]), v0));
  vst1q_f32(m[3], vmulq_f32(vld1q_f32(m[3]), v0));
}

CGLM_INLINE
void
glm_mat4_transp_neon(mat4 m, mat4 dest) {
  float32x4x4_t vmat;
  
  vmat = vld4q_f32(m[0]);

  vst1q_f32(dest[0], vmat.val[0]);
  vst1q_f32(dest[1], vmat.val[1]);
  vst1q_f32(dest[2], vmat.val[2]);
  vst1q_f32(dest[3], vmat.val[3]);
}

CGLM_INLINE
void
glm_mat4_mul_neon(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */
  float32x4_t l0, l1, l2, l3, r, d0, d1, d2, d3;

  l0 = vld1q_f32(m2[0]);
  l1 = vld1q_f32(m2[1]);
  l2 = vld1q_f32(m2[2]);
  l3 = vld1q_f32(m2[3]);

  r  = vld1q_f32(m1[0]);
  d0 = vmulq_lane_f32(r, vget_low_f32(l0), 0);
  d1 = vmulq_lane_f32(r, vget_low_f32(l1), 0);
  d2 = vmulq_lane_f32(r, vget_low_f32(l2), 0);
  d3 = vmulq_lane_f32(r, vget_low_f32(l3), 0);

  r  = vld1q_f32(m1[1]);
  d0 = vmlaq_lane_f32(d0, r, vget_low_f32(l0), 1);
  d1 = vmlaq_lane_f32(d1, r, vget_low_f32(l1), 1);
  d2 = vmlaq_lane_f32(d2, r, vget_low_f32(l2), 1);
  d3 = vmlaq_lane_f32(d3, r, vget_low_f32(l3), 1);

  r  = vld1q_f32(m1[2]);
  d0 = vmlaq_lane_f32(d0, r, vget_high_f32(l0), 0);
  d1 = vmlaq_lane_f32(d1, r, vget_high_f32(l1), 0);
  d2 = vmlaq_lane_f32(d2, r, vget_high_f32(l2), 0);
  d3 = vmlaq_lane_f32(d3, r, vget_high_f32(l3), 0);

  r  = vld1q_f32(m1[3]);
  d0 = vmlaq_lane_f32(d0, r, vget_high_f32(l0), 1);
  d1 = vmlaq_lane_f32(d1, r, vget_high_f32(l1), 1);
  d2 = vmlaq_lane_f32(d2, r, vget_high_f32(l2), 1);
  d3 = vmlaq_lane_f32(d3, r, vget_high_f32(l3), 1);

  vst1q_f32(dest[0], d0);
  vst1q_f32(dest[1], d1);
  vst1q_f32(dest[2], d2);
  vst1q_f32(dest[3], d3);
}

CGLM_INLINE
void
glm_mat4_mulv_neon(mat4 m, vec4 v, vec4 dest) {
  float32x4_t l0, l1, l2, l3;
  float32x2_t vlo, vhi;
  
  l0  = vld1q_f32(m[0]);
  l1  = vld1q_f32(m[1]);
  l2  = vld1q_f32(m[2]);
  l3  = vld1q_f32(m[3]);

  vlo = vld1_f32(&v[0]);
  vhi = vld1_f32(&v[2]);

  l0  = vmulq_lane_f32(l0, vlo, 0);
  l0  = vmlaq_lane_f32(l0, l1, vlo, 1);
  l0  = vmlaq_lane_f32(l0, l2, vhi, 0);
  l0  = vmlaq_lane_f32(l0, l3, vhi, 1);

  vst1q_f32(dest, l0);
}

#endif
#endif /* cglm_mat4_neon_h */
