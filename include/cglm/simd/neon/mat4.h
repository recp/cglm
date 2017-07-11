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

#endif
#endif /* cglm_mat4_neon_h */
