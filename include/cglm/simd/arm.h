/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_simd_arm_h
#define cglm_simd_arm_h
#include "intrin.h"
#ifdef CGLM_SIMD_ARM

#define glmm_load(p)      vld1q_f32(p)
#define glmm_store(p, a)  vst1q_f32(p, a)

static inline
float32x4_t
glmm_abs(float32x4_t v) {
  return vabsq_f32(v);
}

static inline
float
glmm_hadd(float32x4_t v) {
#if defined(__aarch64__)
  return vaddvq_f32(v);
#else
  v = vaddq_f32(v, vrev64q_f32(v));
  v = vaddq_f32(v, vcombine_f32(vget_high_f32(v), vget_low_f32(v)));
  return vgetq_lane_f32(v, 0);
#endif
}

static inline
float
glmm_hmin(float32x4_t v) {
  float32x2_t t;
  t = vpmin_f32(vget_low_f32(v), vget_high_f32(v));
  t = vpmin_f32(t, t);
  return vget_lane_f32(t, 0);
}

static inline
float
glmm_hmax(float32x4_t v) {
  float32x2_t t;
  t = vpmax_f32(vget_low_f32(v), vget_high_f32(v));
  t = vpmax_f32(t, t);
  return vget_lane_f32(t, 0);
}

static inline
float
glmm_dot(float32x4_t a, float32x4_t b) {
  return glmm_hadd(vmulq_f32(a, b));
}

static inline
float
glmm_norm(float32x4_t a) {
  return sqrtf(glmm_dot(a, a));
}

static inline
float
glmm_norm2(float32x4_t a) {
  return glmm_dot(a, a);
}

static inline
float
glmm_norm_one(float32x4_t a) {
  return glmm_hadd(glmm_abs(a));
}

static inline
float
glmm_norm_inf(float32x4_t a) {
  return glmm_hmax(glmm_abs(a));
}

#endif
#endif /* cglm_simd_arm_h */
