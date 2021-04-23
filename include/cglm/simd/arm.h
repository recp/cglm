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

#define glmm_set1(x) vdupq_n_f32(x)
#define glmm_128     float32x4_t

#define glmm_splat_x(x) vdupq_lane_f32(vget_low_f32(x),  0)
#define glmm_splat_y(x) vdupq_lane_f32(vget_low_f32(x),  1)
#define glmm_splat_z(x) vdupq_lane_f32(vget_high_f32(x), 0)
#define glmm_splat_w(x) vdupq_lane_f32(vget_high_f32(x), 1)

#define SWIZZLE(NAME) \
  static inline float32x4_t NAME(glmm_128 v)

/* TODO:
 * I'm not sure if glmm_xxxx(), glmm_yyyy()... is better than glmm_0000()...
 */

SWIZZLE(glmm_0000) { return vdupq_lane_f32(vget_low_f32(v),  0); }
SWIZZLE(glmm_1111) { return vdupq_lane_f32(vget_low_f32(v),  1); }
SWIZZLE(glmm_2222) { return vdupq_lane_f32(vget_high_f32(v), 0); }
SWIZZLE(glmm_3333) { return vdupq_lane_f32(vget_high_f32(v), 1); }

SWIZZLE(glmm_1032) { return vrev64q_f32(v); }

SWIZZLE(glmm_0101) { float32x2_t vt = vget_low_f32(v);              return vcombine_f32(vt, vt); }
SWIZZLE(glmm_2323) { float32x2_t vt = vget_high_f32(v);             return vcombine_f32(vt, vt); }
SWIZZLE(glmm_1010) { float32x2_t vt = vrev64_f32(vget_low_f32(v));  return vcombine_f32(vt, vt); }
SWIZZLE(glmm_3232) { float32x2_t vt = vrev64_f32(vget_high_f32(v)); return vcombine_f32(vt, vt); }

SWIZZLE(glmm_0132) { return vcombine_f32(vget_low_f32(v), vrev64_f32(vget_high_f32(v))); }
SWIZZLE(glmm_1023) { return vcombine_f32(vrev64_f32(vget_low_f32(v)), vget_high_f32(v)); }
SWIZZLE(glmm_2310) { return vcombine_f32(vget_high_f32(v), vrev64_f32(vget_low_f32(v))); }
SWIZZLE(glmm_3201) { return vcombine_f32(vrev64_f32(vget_high_f32(v)), vget_low_f32(v)); }
SWIZZLE(glmm_3210) { return vcombine_f32(vrev64_f32(vget_high_f32(v)), vrev64_f32(vget_low_f32(v))); }

SWIZZLE(glmm_0022) { return vtrnq_f32(v, v).val[0]; }
SWIZZLE(glmm_1133) { return vtrnq_f32(v, v).val[1]; }

SWIZZLE(glmm_0011) { return vzipq_f32(v, v).val[0]; }
SWIZZLE(glmm_2233) { return vzipq_f32(v, v).val[1]; }

SWIZZLE(glmm_0202) { return vuzpq_f32(v, v).val[0]; }
SWIZZLE(glmm_1313) { return vuzpq_f32(v, v).val[1]; }

SWIZZLE(glmm_1230) { return vextq_f32(v, v, 1);     }
SWIZZLE(glmm_2301) { return vextq_f32(v, v, 2);     }
SWIZZLE(glmm_3012) { return vextq_f32(v, v, 3);     }

#undef SWIZZLE

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

static inline
float32x4_t
glmm_fmadd(float32x4_t a, float32x4_t b, float32x4_t c) {
#if defined(__aarch64__)
  return vfmaq_f32(c, a, b);
#else
  return vmlaq_f32(c, a, b);
#endif
}

static inline
float32x4_t
glmm_fnmadd(float32x4_t a, float32x4_t b, float32x4_t c) {
#if defined(__aarch64__)
  return vfmsq_f32(c, a, b);
#else
  return vmlsq_f32(c, a, b);
#endif
}

static inline
float32x4_t
glmm_fmsub(float32x4_t a, float32x4_t b, float32x4_t c) {
#if defined(__aarch64__)
  return vfmsq_f32(c, a, b);
#else
  return vmlsq_f32(c, a, b);
#endif
}

static inline
float32x4_t
glmm_fnmsub(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vsubq_f32(vdupq_n_f32(0.0f), glmm_fmadd(a, b, c));
}

#endif
#endif /* cglm_simd_arm_h */
