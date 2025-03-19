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

#if defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC) || defined(__aarch64__)
# define CGLM_ARM64 1
#else
# define CGLM_ARM64 0
#endif

#define glmm_load(p)      vld1q_f32(p)
#define glmm_store(p, a)  vst1q_f32(p, a)

#define glmm_set1(x)      vdupq_n_f32(x)
#define glmm_set1_ptr(x)  vdupq_n_f32(*x)
#define glmm_set1_rval(x) vdupq_n_f32(x)
#define glmm_128          float32x4_t

#define glmm_splat_x(x) vdupq_lane_f32(vget_low_f32(x),  0)
#define glmm_splat_y(x) vdupq_lane_f32(vget_low_f32(x),  1)
#define glmm_splat_z(x) vdupq_lane_f32(vget_high_f32(x), 0)
#define glmm_splat_w(x) vdupq_lane_f32(vget_high_f32(x), 1)

#define glmm_xor(a, b)                                                        \
  vreinterpretq_f32_s32(veorq_s32(vreinterpretq_s32_f32(a),                   \
                                  vreinterpretq_s32_f32(b)))

#define glmm_swplane(v) vextq_f32(v, v, 2)
#define glmm_low(x)     vget_low_f32(x)
#define glmm_high(x)    vget_high_f32(x)

#define glmm_combine_ll(x, y) vcombine_f32(vget_low_f32(x),  vget_low_f32(y))
#define glmm_combine_hl(x, y) vcombine_f32(vget_high_f32(x), vget_low_f32(y))
#define glmm_combine_lh(x, y) vcombine_f32(vget_low_f32(x),  vget_high_f32(y))
#define glmm_combine_hh(x, y) vcombine_f32(vget_high_f32(x), vget_high_f32(y))

#if defined(_WIN32) && defined(_MSC_VER)
/* #  define glmm_float32x4_init(x, y, z, w) { .n128_f32 = { x, y, z, w } } */
CGLM_INLINE
float32x4_t
glmm_float32x4_init(float x, float y, float z, float w) {
  CGLM_ALIGN(16) float v[4] = {x, y, z, w};
  return vld1q_f32(v);
}
#else
#  define glmm_float32x4_init(x, y, z, w) { x, y, z, w }
#endif

#define glmm_float32x4_SIGNMASK_PNPN glmm_float32x4_init( 0.f, -0.f,  0.f, -0.f)
#define glmm_float32x4_SIGNMASK_NPNP glmm_float32x4_init(-0.f,  0.f, -0.f,  0.f)
#define glmm_float32x4_SIGNMASK_NPPN glmm_float32x4_init(-0.f,  0.f,  0.f, -0.f)

static inline float32x4_t glmm_abs(float32x4_t v)                { return vabsq_f32(v);    }
static inline float32x4_t glmm_min(float32x4_t a, float32x4_t b) { return vminq_f32(a, b); }
static inline float32x4_t glmm_max(float32x4_t a, float32x4_t b) { return vmaxq_f32(a, b); }

static inline
float32x4_t
glmm_vhadd(float32x4_t v) {
#if CGLM_ARM64
  float32x4_t p;
  p = vpaddq_f32(v, v); /* [a+b, c+d, a+b, c+d] */
  return vpaddq_f32(p, p); /* [t, t, t, t] */;
#else
  return vaddq_f32(vaddq_f32(glmm_splat_x(v), glmm_splat_y(v)),
                   vaddq_f32(glmm_splat_z(v), glmm_splat_w(v)));
#endif
  /* TODO: measure speed of this compare to above */
  /* return vdupq_n_f32(vaddvq_f32(v)); */

  /*
  return vaddq_f32(vaddq_f32(glmm_splat_x(v), glmm_splat_y(v)),
                   vaddq_f32(glmm_splat_z(v), glmm_splat_w(v)));
   */
  /*
   this seems slower:
   v = vaddq_f32(v, vrev64q_f32(v));
   return vaddq_f32(v, vcombine_f32(vget_high_f32(v), vget_low_f32(v)));
   */
}

static inline
float
glmm_hadd(float32x4_t v) {
#if CGLM_ARM64
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
float32x4_t
glmm_vdot(float32x4_t a, float32x4_t b) {
  return glmm_vhadd(vmulq_f32(a, b));
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
glmm_div(float32x4_t a, float32x4_t b) {
#if CGLM_ARM64
  return vdivq_f32(a, b);
#else
  /* 2 iterations of Newton-Raphson refinement of reciprocal */
  float32x4_t r0, r1;
  r0 = vrecpeq_f32(b);
  r1 = vrecpsq_f32(r0, b);
  r0 = vmulq_f32(r1, r0);
  r1 = vrecpsq_f32(r0, b);
  r0 = vmulq_f32(r1, r0);
  return vmulq_f32(a, r0);
#endif
}

static inline
float32x4_t
glmm_fmadd(float32x4_t a, float32x4_t b, float32x4_t c) {
#if CGLM_ARM64
  return vfmaq_f32(c, a, b); /* why vfmaq_f32 is slower than vmlaq_f32 ??? */
#else
  return vmlaq_f32(c, a, b);
#endif
}

static inline
float32x4_t
glmm_fnmadd(float32x4_t a, float32x4_t b, float32x4_t c) {
#if CGLM_ARM64
  return vfmsq_f32(c, a, b);
#else
  return vmlsq_f32(c, a, b);
#endif
}

static inline
float32x4_t
glmm_fmsub(float32x4_t a, float32x4_t b, float32x4_t c) {
  return glmm_fmadd(a, b, vnegq_f32(c));
}

static inline
float32x4_t
glmm_fnmsub(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vsubq_f32(vdupq_n_f32(0.0f), glmm_fmadd(a, b, c));
}

#endif
#endif /* cglm_simd_arm_h */
