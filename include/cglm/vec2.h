/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_VEC2_ONE_INIT
   GLM_VEC2_ZERO_INIT
   GLM_VEC2_ONE
   GLM_VEC2_ZERO

 Functions:
   CGLM_INLINE void  glm_vec2(float * __restrict v, vec2 dest)
   CGLM_INLINE void  glm_vec2_copy(vec2 a, vec2 dest)
   CGLM_INLINE void  glm_vec2_zero(vec2 v)
   CGLM_INLINE void  glm_vec2_one(vec2 v)
   CGLM_INLINE float glm_vec2_dot(vec2 a, vec2 b)
   CGLM_INLINE float glm_vec2_cross(vec2 a, vec2 b)
   CGLM_INLINE float glm_vec2_norm2(vec2 v)
   CGLM_INLINE float glm_vec2_norm(vec2 vec)
   CGLM_INLINE void  glm_vec2_add(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_adds(vec2 v, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_sub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_subs(vec2 v, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_mul(vec2 a, vec2 b, vec2 d)
   CGLM_INLINE void  glm_vec2_scale(vec2 v, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_scale_as(vec2 v, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_div(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_divs(vec2 v, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_addadd(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_subadd(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_muladd(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_muladds(vec2 a, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_maxadd(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_minadd(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_subsub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_addsub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_mulsub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_mulsubs(vec2 a, float s, vec2 dest)
   CGLM_INLINE void  glm_vec2_maxsub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_minsub(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_negate_to(vec2 v, vec2 dest)
   CGLM_INLINE void  glm_vec2_negate(vec2 v)
   CGLM_INLINE void  glm_vec2_normalize(vec2 v)
   CGLM_INLINE void  glm_vec2_normalize_to(vec2 vec, vec2 dest)
   CGLM_INLINE void  glm_vec2_rotate(vec2 v, float angle, vec2 dest)
   CGLM_INLINE void  glm_vec2_center(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE float glm_vec2_distance2(vec2 a, vec2 b)
   CGLM_INLINE float glm_vec2_distance(vec2 a, vec2 b)
   CGLM_INLINE void  glm_vec2_maxv(vec2 v1, vec2 v2, vec2 dest)
   CGLM_INLINE void  glm_vec2_minv(vec2 v1, vec2 v2, vec2 dest)
   CGLM_INLINE void  glm_vec2_clamp(vec2 v, float minVal, float maxVal)
   CGLM_INLINE void  glm_vec2_swizzle(vec2 v, int mask, vec2 dest)
   CGLM_INLINE void  glm_vec2_lerp(vec2 from, vec2 to, float t, vec2 dest)
   CGLM_INLINE void  glm_vec2_step(vec2 edge, vec2 x, vec2 dest)
   CGLM_INLINE void  glm_vec2_make(float * restrict src, vec2 dest)
   CGLM_INLINE void  glm_vec2_reflect(vec2 v, vec2 n, vec2 dest)
   CGLM_INLINE void  glm_vec2_refract(vec2 v, vec2 n, float eta, vec2 dest)
 */

#ifndef cglm_vec2_h
#define cglm_vec2_h

#include "common.h"
#include "util.h"
#include "vec2-ext.h"

#define GLM_VEC2_ONE_INIT   {1.0f, 1.0f}
#define GLM_VEC2_ZERO_INIT  {0.0f, 0.0f}

#define GLM_VEC2_ONE  ((vec2)GLM_VEC2_ONE_INIT)
#define GLM_VEC2_ZERO ((vec2)GLM_VEC2_ZERO_INIT)

/*!
 * @brief init vec2 using another vector
 *
 * @param[in]  v    a vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec2(float * __restrict v, vec2 dest) {
  dest[0] = v[0];
  dest[1] = v[1];
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  a    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec2_copy(vec2 a, vec2 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
}

/*!
 * @brief make vector zero
 *
 * @param[in, out]  v vector
 */
CGLM_INLINE
void
glm_vec2_zero(vec2 v) {
  v[0] = v[1] = 0.0f;
}

/*!
 * @brief make vector one
 *
 * @param[in, out]  v vector
 */
CGLM_INLINE
void
glm_vec2_one(vec2 v) {
  v[0] = v[1] = 1.0f;
}

/*!
 * @brief vec2 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_vec2_dot(vec2 a, vec2 b) {
  return a[0] * b[0] + a[1] * b[1];
}

/*!
 * @brief vec2 cross product
 *
 * REF: http://allenchou.net/2013/07/cross-product-of-2d-vectors/
 *
 * @param[in]  a vector1
 * @param[in]  b vector2
 *
 * @return Z component of cross product
 */
CGLM_INLINE
float
glm_vec2_cross(vec2 a, vec2 b) {
  /* just calculate the z-component */
  return a[0] * b[1] - a[1] * b[0];
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf function twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] v vector
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glm_vec2_norm2(vec2 v) {
  return glm_vec2_dot(v, v);
}

/*!
 * @brief norm (magnitude) of vec2
 *
 * @param[in] vec vector
 *
 * @return norm
 */
CGLM_INLINE
float
glm_vec2_norm(vec2 vec) {
  return sqrtf(glm_vec2_norm2(vec));
}

/*!
 * @brief add a vector to b vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_add(vec2 a, vec2 b, vec2 dest) {
  dest[0] = a[0] + b[0];
  dest[1] = a[1] + b[1];
}

/*!
 * @brief add scalar to v vector store result in dest (d = v + s)
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_adds(vec2 v, float s, vec2 dest) {
  dest[0] = v[0] + s;
  dest[1] = v[1] + s;
}

/*!
 * @brief subtract b vector from a vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_sub(vec2 a, vec2 b, vec2 dest) {
  dest[0] = a[0] - b[0];
  dest[1] = a[1] - b[1];
}

/*!
 * @brief subtract scalar from v vector store result in dest (d = v - s)
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_subs(vec2 v, float s, vec2 dest) {
  dest[0] = v[0] - s;
  dest[1] = v[1] - s;
}

/*!
 * @brief multiply two vectors (component-wise multiplication)
 *
 * @param a    v1
 * @param b    v2
 * @param dest v3 = (a[0] * b[0], a[1] * b[1])
 */
CGLM_INLINE
void
glm_vec2_mul(vec2 a, vec2 b, vec2 dest) {
  dest[0] = a[0] * b[0];
  dest[1] = a[1] * b[1];
}

/*!
 * @brief multiply/scale vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_scale(vec2 v, float s, vec2 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
}

/*!
 * @brief scale as vector specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_scale_as(vec2 v, float s, vec2 dest) {
  float norm;
  norm = glm_vec2_norm(v);

  if (CGLM_UNLIKELY(norm < FLT_EPSILON)) {
    glm_vec2_zero(dest);
    return;
  }

  glm_vec2_scale(v, s / norm, dest);
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]/b[0], a[1]/b[1])
 */
CGLM_INLINE
void
glm_vec2_div(vec2 a, vec2 b, vec2 dest) {
  dest[0] = a[0] / b[0];
  dest[1] = a[1] / b[1];
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest result = (a[0]/s, a[1]/s)
 */
CGLM_INLINE
void
glm_vec2_divs(vec2 v, float s, vec2 dest) {
  dest[0] = v[0] / s;
  dest[1] = v[1] / s;
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
glm_vec2_addadd(vec2 a, vec2 b, vec2 dest) {
  dest[0] += a[0] + b[0];
  dest[1] += a[1] + b[1];
}

/*!
 * @brief sub two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += (a + b)
 */
CGLM_INLINE
void
glm_vec2_subadd(vec2 a, vec2 b, vec2 dest) {
  dest[0] += a[0] - b[0];
  dest[1] += a[1] - b[1];
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
glm_vec2_muladd(vec2 a, vec2 b, vec2 dest) {
  dest[0] += a[0] * b[0];
  dest[1] += a[1] * b[1];
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
glm_vec2_muladds(vec2 a, float s, vec2 dest) {
  dest[0] += a[0] * s;
  dest[1] += a[1] * s;
}

/*!
 * @brief add max of two vectors to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += max(a, b)
 */
CGLM_INLINE
void
glm_vec2_maxadd(vec2 a, vec2 b, vec2 dest) {
  dest[0] += glm_max(a[0], b[0]);
  dest[1] += glm_max(a[1], b[1]);
}

/*!
 * @brief add min of two vectors to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest += min(a, b)
 */
CGLM_INLINE
void
glm_vec2_minadd(vec2 a, vec2 b, vec2 dest) {
  dest[0] += glm_min(a[0], b[0]);
  dest[1] += glm_min(a[1], b[1]);
}

/*!
 * @brief sub two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest -= (a - b)
 */
CGLM_INLINE
void
glm_vec2_subsub(vec2 a, vec2 b, vec2 dest) {
  dest[0] -= a[0] - b[0];
  dest[1] -= a[1] - b[1];
}

/*!
 * @brief add two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest -= (a + b)
 */
CGLM_INLINE
void
glm_vec2_addsub(vec2 a, vec2 b, vec2 dest) {
  dest[0] -= a[0] + b[0];
  dest[1] -= a[1] + b[1];
}

/*!
 * @brief mul two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest -= (a * b)
 */
CGLM_INLINE
void
glm_vec2_mulsub(vec2 a, vec2 b, vec2 dest) {
  dest[0] -= a[0] * b[0];
  dest[1] -= a[1] * b[1];
}

/*!
 * @brief mul vector with scalar and sub result to sum
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest -= (a * b)
 */
CGLM_INLINE
void
glm_vec2_mulsubs(vec2 a, float s, vec2 dest) {
  dest[0] -= a[0] * s;
  dest[1] -= a[1] * s;
}

/*!
 * @brief sub max of two vectors to result/dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest -= max(a, b)
 */
CGLM_INLINE
void
glm_vec2_maxsub(vec2 a, vec2 b, vec2 dest) {
  dest[0] -= glm_max(a[0], b[0]);
  dest[1] -= glm_max(a[1], b[1]);
}

/*!
 * @brief sub min of two vectors to result/dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest dest -= min(a, b)
 */
CGLM_INLINE
void
glm_vec2_minsub(vec2 a, vec2 b, vec2 dest) {
  dest[0] -= glm_min(a[0], b[0]);
  dest[1] -= glm_min(a[1], b[1]);
}

/*!
 * @brief negate vector components and store result in dest
 *
 * @param[in]   v     vector
 * @param[out]  dest  result vector
 */
CGLM_INLINE
void
glm_vec2_negate_to(vec2 v, vec2 dest) {
  dest[0] = -v[0];
  dest[1] = -v[1];
}

/*!
 * @brief negate vector components
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec2_negate(vec2 v) {
  glm_vec2_negate_to(v, v);
}

/*!
 * @brief normalize vector and store result in same vec
 *
 * @param[in, out] v vector
 */
CGLM_INLINE
void
glm_vec2_normalize(vec2 v) {
  float norm;

  norm = glm_vec2_norm(v);

  if (CGLM_UNLIKELY(norm < FLT_EPSILON)) {
    v[0] = v[1] = 0.0f;
    return;
  }

  glm_vec2_scale(v, 1.0f / norm, v);
}

/*!
 * @brief normalize vector to dest
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec2_normalize_to(vec2 v, vec2 dest) {
  float norm;

  norm = glm_vec2_norm(v);

  if (CGLM_UNLIKELY(norm < FLT_EPSILON)) {
    glm_vec2_zero(dest);
    return;
  }

  glm_vec2_scale(v, 1.0f / norm, dest);
}

/*!
 * @brief rotate vec2 around origin by angle (CCW: counterclockwise)
 *
 * Formula:
 *   𝑥2 = cos(a)𝑥1 − sin(a)𝑦1
 *   𝑦2 = sin(a)𝑥1 + cos(a)𝑦1
 *
 * @param[in]  v     vector to rotate
 * @param[in]  angle angle by radians
 * @param[out] dest  destination vector
 */
CGLM_INLINE
void
glm_vec2_rotate(vec2 v, float angle, vec2 dest) {
  float c, s, x1, y1;

  c  = cosf(angle);
  s  = sinf(angle);

  x1 = v[0];
  y1 = v[1];

  dest[0] = c * x1 - s * y1;
  dest[1] = s * x1 + c * y1;
}

/**
 * @brief find center point of two vector
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @param[out] dest center point
 */
CGLM_INLINE
void
glm_vec2_center(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_add(a, b, dest);
  glm_vec2_scale(dest, 0.5f, dest);
}

/**
 * @brief squared distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return returns squared distance (distance * distance)
 */
CGLM_INLINE
float
glm_vec2_distance2(vec2 a, vec2 b) {
  return glm_pow2(b[0] - a[0]) + glm_pow2(b[1] - a[1]);
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
glm_vec2_distance(vec2 a, vec2 b) {
  return sqrtf(glm_vec2_distance2(a, b));
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
glm_vec2_maxv(vec2 a, vec2 b, vec2 dest) {
  dest[0] = glm_max(a[0], b[0]);
  dest[1] = glm_max(a[1], b[1]);
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
glm_vec2_minv(vec2 a, vec2 b, vec2 dest) {
  dest[0] = glm_min(a[0], b[0]);
  dest[1] = glm_min(a[1], b[1]);
}

/*!
 * @brief clamp vector's individual members between min and max values
 *
 * @param[in, out]  v      vector
 * @param[in]       minval minimum value
 * @param[in]       maxval maximum value
 */
CGLM_INLINE
void
glm_vec2_clamp(vec2 v, float minval, float maxval) {
  v[0] = glm_clamp(v[0], minval, maxval);
  v[1] = glm_clamp(v[1], minval, maxval);
}

/*!
 * @brief swizzle vector components
 *
 * @param[in]  v    source
 * @param[in]  mask mask
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec2_swizzle(vec2 v, int mask, vec2 dest) {
  vec2 t;

  t[0] = v[(mask & (3 << 0))];
  t[1] = v[(mask & (3 << 2)) >> 2];

  glm_vec2_copy(t, dest);
}

/*!
 * @brief linear interpolation between two vector
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount) clamped between 0 and 1
 * @param[out]  dest destination
 */
CGLM_INLINE
void
glm_vec2_lerp(vec2 from, vec2 to, float t, vec2 dest) {
  vec2 s, v;

  /* from + s * (to - from) */
  glm_vec2_fill(s, glm_clamp_zo(t));
  glm_vec2_sub(to, from, v);
  glm_vec2_mul(s, v, v);
  glm_vec2_add(from, v, dest);
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
glm_vec2_step(vec2 edge, vec2 x, vec2 dest) {
  dest[0] = glm_step(edge[0], x[0]);
  dest[1] = glm_step(edge[1], x[1]);
}

/*!
 * @brief Create two dimensional vector from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_make(const float * __restrict src, vec2 dest) {
  dest[0] = src[0]; dest[1] = src[1];
}

/*!
 * @brief reflection vector using an incident ray and a surface normal
 *
 * @param[in]  v    incident vector
 * @param[in]  n    normalized normal vector
 * @param[out] dest destination vector for the reflection result
 */
CGLM_INLINE
void
glm_vec2_reflect(vec2 v, vec2 n, vec2 dest) {
  vec2 temp;
  glm_vec2_scale(n, 2.0f * glm_vec2_dot(v, n), temp);
  glm_vec2_sub(v, temp, dest);
}

/*!
 * @brief computes refraction vector for an incident vector and a surface normal.
 *
 * calculates the refraction vector based on Snell's law. If total internal reflection
 * occurs (angle too great given eta), dest is set to zero and returns false.
 * Otherwise, computes refraction vector, stores it in dest, and returns true.
 *
 * @param[in]  v    normalized incident vector
 * @param[in]  n    normalized normal vector
 * @param[in]  eta  ratio of indices of refraction (incident/transmitted)
 * @param[out] dest refraction vector if refraction occurs; zero vector otherwise
 *
 * @returns true if refraction occurs; false if total internal reflection occurs.
 */
CGLM_INLINE
bool
glm_vec2_refract(vec2 v, vec2 n, float eta, vec2 dest) {
  float ndi, eni, k;

  ndi = glm_vec2_dot(n, v);
  eni = eta * ndi;
  k   = 1.0f - eta * eta + eni * eni;

  if (k < 0.0f) {
    glm_vec2_zero(dest);
    return false;
  }

  glm_vec2_scale(v, eta, dest);
  glm_vec2_mulsubs(n, eni + sqrtf(k), dest);
  return true;
}

#endif /* cglm_vec2_h */
