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

CGLM_INLINE
float
glm_mat4_det_neon(mat4 mat) {
  float32x4_t   r0, r1, r2, r3, x0, x1, x2;
  float32x2_t   ij, op, mn, kl, nn, mm, jj, ii, gh, ef, t12, t34;
  float32x4x2_t a1;
  float32x4_t   x3 = { 0.f, -0.f, 0.f, -0.f };

  /* 127 <- 0, [square] det(A) = det(At) */
  r0 = glmm_load(mat[0]);              /* d c b a */
  r1 = vrev64q_f32(glmm_load(mat[1])); /* g h e f */
  r2 = vrev64q_f32(glmm_load(mat[2])); /* l k i j */
  r3 = vrev64q_f32(glmm_load(mat[3])); /* o p m n */

  gh = vget_high_f32(r1);
  ef = vget_low_f32(r1);
  kl = vget_high_f32(r2);
  ij = vget_low_f32(r2);
  op = vget_high_f32(r3);
  mn = vget_low_f32(r3);
  mm = vdup_lane_f32(mn, 1);
  nn = vdup_lane_f32(mn, 0);
  ii = vdup_lane_f32(ij, 1);
  jj = vdup_lane_f32(ij, 0);
  
  /*
   t[1] = j * p - n * l;
   t[2] = j * o - n * k;
   t[3] = i * p - m * l;
   t[4] = i * o - m * k;
   */
  x0 = glmm_fnmadd(vcombine_f32(kl, kl), vcombine_f32(nn, mm),
                   vmulq_f32(vcombine_f32(op, op), vcombine_f32(jj, ii)));

  t12 = vget_low_f32(x0);
  t34 = vget_high_f32(x0);
  
  /* 1 3 1 3 2 4 2 4 */
  a1 = vuzpq_f32(x0, x0);
  
  /*
   t[0] = k * p - o * l;
   t[0] = k * p - o * l;
   t[5] = i * n - m * j;
   t[5] = i * n - m * j;
   */
  x1 = glmm_fnmadd(vcombine_f32(vdup_lane_f32(kl, 0), jj),
                   vcombine_f32(vdup_lane_f32(op, 1), mm),
                   vmulq_f32(vcombine_f32(vdup_lane_f32(op, 0), nn),
                             vcombine_f32(vdup_lane_f32(kl, 1), ii)));

  /*
     a * (f * t[0] - g * t[1] + h * t[2])
   - b * (e * t[0] - g * t[3] + h * t[4])
   + c * (e * t[1] - f * t[3] + h * t[5])
   - d * (e * t[2] - f * t[4] + g * t[5])
   */
  x2 = glmm_fnmadd(vcombine_f32(vdup_lane_f32(gh, 1), vdup_lane_f32(ef, 0)),
                   vcombine_f32(vget_low_f32(a1.val[0]), t34),
                   vmulq_f32(vcombine_f32(ef, vdup_lane_f32(ef, 1)),
                             vcombine_f32(vget_low_f32(x1), t12)));

  x2 = glmm_fmadd(vcombine_f32(vdup_lane_f32(gh, 0), gh),
                  vcombine_f32(vget_low_f32(a1.val[1]), vget_high_f32(x1)), x2);

  x2 = glmm_xor(x2, x3);

  return glmm_hadd(vmulq_f32(x2, r0));
}

#endif
#endif /* cglm_mat4_neon_h */
