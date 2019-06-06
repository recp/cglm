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
glmm_dot(float32x4_t a, float32x4_t b) {
  return glmm_hadd(vmulq_f32(a, b));
}

static inline
float
glmm_norm(float32x4_t a) {
  return sqrtf(glmm_dot(a, a));
}

#endif
#endif /* cglm_simd_arm_h */
