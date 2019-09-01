/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_VEC4_ONE_INIT
   GLM_VEC4_BLACK_INIT
   GLM_VEC4_ZERO_INIT
   GLM_VEC4_ONE
   GLM_VEC4_BLACK
   GLM_VEC4_ZERO

 Functions:
   CGLM_INLINE void  glm_vec4(vec3 v3, float last, vec4 dest);
   CGLM_INLINE void  glm_vec4_copy3(vec4 a, vec3 dest);
   CGLM_INLINE void  glm_vec4_copy(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_ucopy(vec4 v, vec4 dest);
   CGLM_INLINE float glm_vec4_dot(vec4 a, vec4 b);
   CGLM_INLINE float glm_vec4_norm2(vec4 v);
   CGLM_INLINE float glm_vec4_norm(vec4 v);
   CGLM_INLINE float glm_vec4_norm_one(vec4 v);
   CGLM_INLINE float glm_vec4_norm_inf(vec4 v);
   CGLM_INLINE void  glm_vec4_add(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_adds(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_sub(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_subs(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_mul(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_scale(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_scale_as(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_div(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_divs(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_addadd(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_subadd(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_muladd(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_muladds(vec4 a, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_maxadd(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_minadd(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_negate(vec4 v);
   CGLM_INLINE void  glm_vec4_inv(vec4 v);
   CGLM_INLINE void  glm_vec4_inv_to(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_normalize(vec4 v);
   CGLM_INLINE void  glm_vec4_normalize_to(vec4 vec, vec4 dest);
   CGLM_INLINE float glm_vec4_distance(vec4 a, vec4 b);
   CGLM_INLINE float glm_vec4_distance2(vec4 a, vec4 b);
   CGLM_INLINE void  glm_vec4_maxv(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_minv(vec4 a, vec4 b, vec4 dest);
   CGLM_INLINE void  glm_vec4_clamp(vec4 v, float minVal, float maxVal);
   CGLM_INLINE void  glm_vec4_lerp(vec4 from, vec4 to, float t, vec4 dest);
   CGLM_INLINE void  glm_vec4_lerpc(vec4 from, vec4 to, float t, vec4 dest);
   CGLM_INLINE void  glm_vec4_step_uni(float edge, vec4 x, vec4 dest);
   CGLM_INLINE void  glm_vec4_step(vec4 edge, vec4 x, vec4 dest);
   CGLM_INLINE void  glm_vec4_smoothstep_uni(float edge0, float edge1, vec4 x, vec4 dest);
   CGLM_INLINE void  glm_vec4_smoothstep(vec4 edge0, vec4 edge1, vec4 x, vec4 dest);
   CGLM_INLINE void  glm_vec4_smoothinterp(vec4 from, vec4 to, float t, vec4 dest);
   CGLM_INLINE void  glm_vec4_smoothinterpc(vec4 from, vec4 to, float t, vec4 dest);
   CGLM_INLINE void  glm_vec4_swizzle(vec4 v, int mask, vec4 dest);

 DEPRECATED:
   glm_vec4_dup
   glm_vec4_flipsign
   glm_vec4_flipsign_to
   glm_vec4_inv
   glm_vec4_inv_to
   glm_vec4_mulv
 */

#ifndef cglm_vec4_h
#define cglm_vec4_h

#include "common.h"
#include "vec4-ext.h"
#include "util.h"

/* DEPRECATED! functions */
#define glm_vec4_dup3(v, dest)         glm_vec4_copy3(v, dest)
#define glm_vec4_dup(v, dest)          glm_vec4_copy(v, dest)
#define glm_vec4_flipsign(v)           glm_vec4_negate(v)
#define glm_vec4_flipsign_to(v, dest)  glm_vec4_negate_to(v, dest)
#define glm_vec4_inv(v)                glm_vec4_negate(v)
#define glm_vec4_inv_to(v, dest)       glm_vec4_negate_to(v, dest)
#define glm_vec4_mulv(a, b, d)         glm_vec4_mul(a, b, d)

#define GLM_VEC4_ONE_INIT   {1.0f, 1.0f, 1.0f, 1.0f}
#define GLM_VEC4_BLACK_INIT {0.0f, 0.0f, 0.0f, 1.0f}
#define GLM_VEC4_ZERO_INIT  {0.0f, 0.0f, 0.0f, 0.0f}

#define GLM_VEC4_ONE        ((vec4)GLM_VEC4_ONE_INIT)
#define GLM_VEC4_BLACK      ((vec4)GLM_VEC4_BLACK_INIT)
#define GLM_VEC4_ZERO       ((vec4)GLM_VEC4_ZERO_INIT)

#define GLM_XXXX GLM_SHUFFLE4(0, 0, 0, 0)
#define GLM_YYYY GLM_SHUFFLE4(1, 1, 1, 1)
#define GLM_ZZZZ GLM_SHUFFLE4(2, 2, 2, 2)
#define GLM_WWWW GLM_SHUFFLE4(3, 3, 3, 3)
#define GLM_WZYX GLM_SHUFFLE4(0, 1, 2, 3)

/*!
 * @brief init vec4 using vec3
 *
 * @param[in]  v3   vector3
 * @param[in]  last last item
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4(vec3 v3, float last, vec4 dest) {
  dest[0] = v3[0];
  dest[1] = v3[1];
  dest[2] = v3[2];
  dest[3] = last;
}

/*!
 * @brief copy first 3 members of [a] to [dest]
 *
 * @param[in]  a    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_copy3(vec4 a, vec3 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_copy(vec4 v, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, glmm_load(v));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vld1q_f32(v));
#else
  dest[0] = v[0];
  dest[1] = v[1];
  dest[2] = v[2];
  dest[3] = v[3];
#endif
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * alignment is not required
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_ucopy(vec4 v, vec4 dest) {
  dest[0] = v[0];
  dest[1] = v[1];
  dest[2] = v[2];
  dest[3] = v[3];
}

/*!
 * @brief make vector zero
 *
 * @param[in, out]  v vector
 */
CGLM_INLINE
void
glm_vec4_zero(vec4 v) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(v, _mm_setzero_ps());
#elif defined(CGLM_NEON_FP)
  vst1q_f32(v, vdupq_n_f32(0.0f));
#else
  v[0] = 0.0f;
  v[1] = 0.0f;
  v[2] = 0.0f;
  v[3] = 0.0f;
#endif
}

/*!
 * @brief make vector one
 *
 * @param[in, out]  v vector
 */
CGLM_INLINE
void
glm_vec4_one(vec4 v) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(v, _mm_set1_ps(1.0f));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(v, vdupq_n_f32(1.0f));
#else
  v[0] = 1.0f;
  v[1] = 1.0f;
  v[2] = 1.0f;
  v[3] = 1.0f;
#endif
}

/*!
 * @brief vec4 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_vec4_dot(vec4 a, vec4 b) {
#if defined(CGLM_SIMD)
  return glmm_dot(glmm_load(a), glmm_load(b));
#else
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
#endif
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf fuction twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] v vec4
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glm_vec4_norm2(vec4 v) {
  return glm_vec4_dot(v, v);
}

/*!
 * @brief euclidean norm (magnitude), also called L2 norm
 *        this will give magnitude of vector in euclidean space
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_INLINE
float
glm_vec4_norm(vec4 v) {
#if defined(CGLM_SIMD)
  return glmm_norm(glmm_load(v));
#else
  return sqrtf(glm_vec4_dot(v, v));
#endif
}

/*!
 * @brief L1 norm of vec4
 * Also known as Manhattan Distance or Taxicab norm.
 * L1 Norm is the sum of the magnitudes of the vectors in a space.
 * It is calculated as the sum of the absolute values of the vector components.
 * In this norm, all the components of the vector are weighted equally.
 *
 * This computes:
 * L1 norm = |v[0]| + |v[1]| + |v[2]| + |v[3]|
 *
 * @param[in] v vector
 *
 * @return L1 norm
 */
CGLM_INLINE
float
glm_vec4_norm_one(vec4 v) {
#if defined(CGLM_SIMD)
  return glmm_norm_one(glmm_load(v));
#else
  vec4 t;
  glm_vec4_abs(v, t);
  return glm_vec4_hadd(t);
#endif
}

/*!
 * @brief infinity norm of vec4
 * Also known as Maximum norm.
 * Infinity Norm is the largest magnitude among each element of a vector.
 * It is calculated as the maximum of the absolute values of the vector components.
 *
 * This computes:
 * inf norm = max(|v[0]|, |v[1]|, |v[2]|, |v[3]|)
 *
 * @param[in] v vector
 *
 * @return infinity norm
 */
CGLM_INLINE
float
glm_vec4_norm_inf(vec4 v) {
#if defined(CGLM_SIMD)
  return glmm_norm_inf(glmm_load(v));
#else
  vec4 t;
  glm_vec4_abs(v, t);
  return glm_vec4_max(t);
#endif
}

/*!
 * @brief add b vector to a vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_add(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
  dest[0] = a[0] + b[0];
  dest[1] = a[1] + b[1];
  dest[2] = a[2] + b[2];
  dest[3] = a[3] + b[3];
#endif
}

/*!
 * @brief add scalar to v vector store result in dest (d = v + vec(s))
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_adds(vec4 v, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(v), _mm_set1_ps(s)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(v), vdupq_n_f32(s)));
#else
  dest[0] = v[0] + s;
  dest[1] = v[1] + s;
  dest[2] = v[2] + s;
  dest[3] = v[3] + s;
#endif
}

/*!
 * @brief subtract b vector from a vector store result in dest (d = a - b)
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_sub(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_sub_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vsubq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
  dest[0] = a[0] - b[0];
  dest[1] = a[1] - b[1];
  dest[2] = a[2] - b[2];
  dest[3] = a[3] - b[3];
#endif
}

/*!
 * @brief subtract scalar from v vector store result in dest (d = v - vec(s))
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_subs(vec4 v, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_sub_ps(glmm_load(v), _mm_set1_ps(s)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vsubq_f32(vld1q_f32(v), vdupq_n_f32(s)));
#else
  dest[0] = v[0] - s;
  dest[1] = v[1] - s;
  dest[2] = v[2] - s;
  dest[3] = v[3] - s;
#endif
}

/*!
 * @brief multiply two vector (component-wise multiplication)
 *
 * @param a    vector1
 * @param b    vector2
 * @param dest dest = (a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3])
 */
CGLM_INLINE
void
glm_vec4_mul(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_mul_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vmulq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
  dest[0] = a[0] * b[0];
  dest[1] = a[1] * b[1];
  dest[2] = a[2] * b[2];
  dest[3] = a[3] * b[3];
#endif
}

/*!
 * @brief multiply/scale vec4 vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_scale(vec4 v, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_mul_ps(glmm_load(v), _mm_set1_ps(s)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vmulq_f32(vld1q_f32(v), vdupq_n_f32(s)));
#else
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
  dest[3] = v[3] * s;
#endif
}

/*!
 * @brief make vec4 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_scale_as(vec4 v, float s, vec4 dest) {
  float norm;
  norm = glm_vec4_norm(v);

  if (norm == 0.0f) {
    glm_vec4_zero(dest);
    return;
  }

  glm_vec4_scale(v, s / norm, dest);
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]/b[0], a[1]/b[1], a[2]/b[2], a[3]/b[3])
 */
CGLM_INLINE
void
glm_vec4_div(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_div_ps(glmm_load(a), glmm_load(b)));
#else
  dest[0] = a[0] / b[0];
  dest[1] = a[1] / b[1];
  dest[2] = a[2] / b[2];
  dest[3] = a[3] / b[3];
#endif
}

/*!
 * @brief div vec4 vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_divs(vec4 v, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_div_ps(glmm_load(v), _mm_set1_ps(s)));
#else
  glm_vec4_scale(v, 1.0f / s, dest);
#endif
}

/*!
 * @brief add two vectors and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += (a + b)
 */
CGLM_INLINE
void
glm_vec4_addadd(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_add_ps(glmm_load(a),
                                         glmm_load(b))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vaddq_f32(vld1q_f32(a),
                                      vld1q_f32(b))));
#else
  dest[0] += a[0] + b[0];
  dest[1] += a[1] + b[1];
  dest[2] += a[2] + b[2];
  dest[3] += a[3] + b[3];
#endif
}

/*!
 * @brief sub two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += (a - b)
 */
CGLM_INLINE
void
glm_vec4_subadd(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_sub_ps(glmm_load(a),
                                         glmm_load(b))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vsubq_f32(vld1q_f32(a),
                                      vld1q_f32(b))));
#else
  dest[0] += a[0] - b[0];
  dest[1] += a[1] - b[1];
  dest[2] += a[2] - b[2];
  dest[3] += a[3] - b[3];
#endif
}

/*!
 * @brief mul two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += (a * b)
 */
CGLM_INLINE
void
glm_vec4_muladd(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_mul_ps(glmm_load(a),
                                         glmm_load(b))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vmulq_f32(vld1q_f32(a),
                                      vld1q_f32(b))));
#else
  dest[0] += a[0] * b[0];
  dest[1] += a[1] * b[1];
  dest[2] += a[2] * b[2];
  dest[3] += a[3] * b[3];
#endif
}

/*!
 * @brief mul vector with scalar and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest += (a * b)
 */
CGLM_INLINE
void
glm_vec4_muladds(vec4 a, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_mul_ps(glmm_load(a),
                                         _mm_set1_ps(s))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vsubq_f32(vld1q_f32(a),
                                      vdupq_n_f32(s))));
#else
  dest[0] += a[0] * s;
  dest[1] += a[1] * s;
  dest[2] += a[2] * s;
  dest[3] += a[3] * s;
#endif
}

/*!
 * @brief add max of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += max(a, b)
 */
CGLM_INLINE
void
glm_vec4_maxadd(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_max_ps(glmm_load(a),
                                         glmm_load(b))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vmaxq_f32(vld1q_f32(a),
                                      vld1q_f32(b))));
#else
  dest[0] += glm_max(a[0], b[0]);
  dest[1] += glm_max(a[1], b[1]);
  dest[2] += glm_max(a[2], b[2]);
  dest[3] += glm_max(a[3], b[3]);
#endif
}

/*!
 * @brief add min of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += min(a, b)
 */
CGLM_INLINE
void
glm_vec4_minadd(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_add_ps(glmm_load(dest),
                              _mm_min_ps(glmm_load(a),
                                         glmm_load(b))));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vaddq_f32(vld1q_f32(dest),
                            vminq_f32(vld1q_f32(a),
                                      vld1q_f32(b))));
#else
  dest[0] += glm_min(a[0], b[0]);
  dest[1] += glm_min(a[1], b[1]);
  dest[2] += glm_min(a[2], b[2]);
  dest[3] += glm_min(a[3], b[3]);
#endif
}

/*!
 * @brief negate vector components and store result in dest
 *
 * @param[in]  v     vector
 * @param[out] dest  result vector
 */
CGLM_INLINE
void
glm_vec4_negate_to(vec4 v, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_xor_ps(glmm_load(v), _mm_set1_ps(-0.0f)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, veorq_s32(vld1q_f32(v), vdupq_n_f32(-0.0f)));
#else
  dest[0] = -v[0];
  dest[1] = -v[1];
  dest[2] = -v[2];
  dest[3] = -v[3];
#endif
}

/*!
 * @brief flip sign of all vec4 members
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec4_negate(vec4 v) {
  glm_vec4_negate_to(v, v);
}

/*!
 * @brief normalize vec4 to dest
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_normalize_to(vec4 v, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  __m128 xdot, x0;
  float  dot;

  x0   = glmm_load(v);
  xdot = glmm_vdot(x0, x0);
  dot  = _mm_cvtss_f32(xdot);

  if (dot == 0.0f) {
    glmm_store(dest, _mm_setzero_ps());
    return;
  }

  glmm_store(dest, _mm_div_ps(x0, _mm_sqrt_ps(xdot)));
#else
  float norm;

  norm = glm_vec4_norm(v);

  if (norm == 0.0f) {
    glm_vec4_zero(dest);
    return;
  }

  glm_vec4_scale(v, 1.0f / norm, dest);
#endif
}

/*!
 * @brief normalize vec4 and store result in same vec
 *
 * @param[in, out] v vector
 */
CGLM_INLINE
void
glm_vec4_normalize(vec4 v) {
  glm_vec4_normalize_to(v, v);
}

/**
 * @brief distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return returns distance
 */
CGLM_INLINE
float
glm_vec4_distance(vec4 a, vec4 b) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  return glmm_norm(_mm_sub_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  return glmm_norm(vsubq_f32(glmm_load(a), glmm_load(b)));
#else
  return sqrtf(glm_pow2(a[0] - b[0])
             + glm_pow2(a[1] - b[1])
             + glm_pow2(a[2] - b[2])
             + glm_pow2(a[3] - b[3]));
#endif
}

/**
 * @brief squared distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return returns squared distance
 */
CGLM_INLINE
float
glm_vec4_distance2(vec4 a, vec4 b) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  return glmm_norm2(_mm_sub_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  return glmm_norm2(vsubq_f32(glmm_load(a), glmm_load(b)));
#else
  return glm_pow2(a[0] - b[0])
       + glm_pow2(a[1] - b[1])
       + glm_pow2(a[2] - b[2])
       + glm_pow2(a[3] - b[3]);
#endif
}

/*!
 * @brief max values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_maxv(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_max_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vmaxq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
  dest[0] = glm_max(a[0], b[0]);
  dest[1] = glm_max(a[1], b[1]);
  dest[2] = glm_max(a[2], b[2]);
  dest[3] = glm_max(a[3], b[3]);
#endif
}

/*!
 * @brief min values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_minv(vec4 a, vec4 b, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_min_ps(glmm_load(a), glmm_load(b)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vminq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
  dest[0] = glm_min(a[0], b[0]);
  dest[1] = glm_min(a[1], b[1]);
  dest[2] = glm_min(a[2], b[2]);
  dest[3] = glm_min(a[3], b[3]);
#endif
}

/*!
 * @brief clamp vector's individual members between min and max values
 *
 * @param[in, out]  v      vector
 * @param[in]       minVal minimum value
 * @param[in]       maxVal maximum value
 */
CGLM_INLINE
void
glm_vec4_clamp(vec4 v, float minVal, float maxVal) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(v, _mm_min_ps(_mm_max_ps(glmm_load(v), _mm_set1_ps(minVal)),
                           _mm_set1_ps(maxVal)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(v, vminq_f32(vmaxq_f32(vld1q_f32(v), vdupq_n_f32(minVal)),
                         vdupq_n_f32(maxVal)));
#else
  v[0] = glm_clamp(v[0], minVal, maxVal);
  v[1] = glm_clamp(v[1], minVal, maxVal);
  v[2] = glm_clamp(v[2], minVal, maxVal);
  v[3] = glm_clamp(v[3], minVal, maxVal);
#endif
}

/*!
 * @brief linear interpolation between two vectors
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount)
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec4_lerp(vec4 from, vec4 to, float t, vec4 dest) {
  vec4 s, v;

  /* from + s * (to - from) */
  glm_vec4_broadcast(t, s);
  glm_vec4_sub(to, from, v);
  glm_vec4_mul(s, v, v);
  glm_vec4_add(from, v, dest);
}

/*!
 * @brief linear interpolation between two vectors (clamped)
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount) clamped between 0 and 1
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec4_lerpc(vec4 from, vec4 to, float t, vec4 dest) {
  glm_vec4_lerp(from, to, glm_clamp_zo(t), dest);
}

/*!
 * @brief linear interpolation between two vectors
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount)
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec4_mix(vec4 from, vec4 to, float t, vec4 dest) {
  glm_vec4_lerp(from, to, t, dest);
}

/*!
 * @brief linear interpolation between two vectors (clamped)
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount) clamped between 0 and 1
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec4_mixc(vec4 from, vec4 to, float t, vec4 dest) {
  glm_vec4_lerpc(from, to, t, dest);
}

/*!
 * @brief threshold function (unidimensional)
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_step_uni(float edge, vec4 x, vec4 dest) {
  dest[0] = glm_step(edge, x[0]);
  dest[1] = glm_step(edge, x[1]);
  dest[2] = glm_step(edge, x[2]);
  dest[3] = glm_step(edge, x[3]);
}

/*!
 * @brief threshold function
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_step(vec4 edge, vec4 x, vec4 dest) {
  dest[0] = glm_step(edge[0], x[0]);
  dest[1] = glm_step(edge[1], x[1]);
  dest[2] = glm_step(edge[2], x[2]);
  dest[3] = glm_step(edge[3], x[3]);
}

/*!
 * @brief threshold function with a smooth transition (unidimensional)
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_smoothstep_uni(float edge0, float edge1, vec4 x, vec4 dest) {
  dest[0] = glm_smoothstep(edge0, edge1, x[0]);
  dest[1] = glm_smoothstep(edge0, edge1, x[1]);
  dest[2] = glm_smoothstep(edge0, edge1, x[2]);
  dest[3] = glm_smoothstep(edge0, edge1, x[3]);
}

/*!
 * @brief threshold function with a smooth transition
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_smoothstep(vec4 edge0, vec4 edge1, vec4 x, vec4 dest) {
  dest[0] = glm_smoothstep(edge0[0], edge1[0], x[0]);
  dest[1] = glm_smoothstep(edge0[1], edge1[1], x[1]);
  dest[2] = glm_smoothstep(edge0[2], edge1[2], x[2]);
  dest[3] = glm_smoothstep(edge0[3], edge1[3], x[3]);
}

/*!
 * @brief smooth Hermite interpolation between two vectors
 *
 * formula:  t^2 * (3 - 2*t)
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   t       interpolant (amount)
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_smoothinterp(vec4 from, vec4 to, float t, vec4 dest) {
  vec4 s, v;
    
  /* from + smoothstep * (to - from) */
  glm_vec4_broadcast(glm_smooth(t), s);
  glm_vec4_sub(to, from, v);
  glm_vec4_mul(s, v, v);
  glm_vec4_add(from, v, dest);
}

/*!
 * @brief smooth Hermite interpolation between two vectors (clamped)
 *
 * formula:  t^2 * (3 - 2*t)
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   t       interpolant (amount) clamped between 0 and 1
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_smoothinterpc(vec4 from, vec4 to, float t, vec4 dest) {
  glm_vec4_smoothinterp(from, to, glm_clamp_zo(t), dest);
}

/*!
 * @brief helper to fill vec4 as [S^3, S^2, S, 1]
 *
 * @param[in]   s    parameter
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec4_cubic(float s, vec4 dest) {
  float ss;

  ss = s * s;

  dest[0] = ss * s;
  dest[1] = ss;
  dest[2] = s;
  dest[3] = 1.0f;
}

/*!
 * @brief swizzle vector components
 *
 * you can use existin masks e.g. GLM_XXXX, GLM_WZYX
 *
 * @param[in]  v    source
 * @param[in]  mask mask
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_swizzle(vec4 v, int mask, vec4 dest) {
  vec4 t;

  t[0] = v[(mask & (3 << 0))];
  t[1] = v[(mask & (3 << 2)) >> 2];
  t[2] = v[(mask & (3 << 4)) >> 4];
  t[3] = v[(mask & (3 << 6)) >> 6];

  glm_vec4_copy(t, dest);
}

#endif /* cglm_vec4_h */
