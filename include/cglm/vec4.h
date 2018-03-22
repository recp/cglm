/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * vec3 functions dont have suffix e.g glm_vec_dot (not glm_vec3_dot)
 * all functions without suffix are vec3 functions
 */

/*
 Macros:
   glm_vec4_dup3(v, dest)
   glm_vec4_dup(v, dest)
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
   CGLM_INLINE float glm_vec4_dot(vec4 a, vec4 b);
   CGLM_INLINE float glm_vec4_norm2(vec4 v);
   CGLM_INLINE float glm_vec4_norm(vec4 vec);
   CGLM_INLINE void  glm_vec4_add(vec4 v1, vec4 v2, vec4 dest);
   CGLM_INLINE void  glm_vec4_sub(vec4 v1, vec4 v2, vec4 dest);
   CGLM_INLINE void  glm_vec4_scale(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_scale_as(vec4 v, float s, vec4 dest);
   CGLM_INLINE void  glm_vec4_flipsign(vec4 v);
   CGLM_INLINE void  glm_vec4_inv(vec4 v);
   CGLM_INLINE void  glm_vec4_inv_to(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_normalize(vec4 v);
   CGLM_INLINE void  glm_vec4_normalize_to(vec4 vec, vec4 dest);
   CGLM_INLINE float glm_vec4_distance(vec4 v1, vec4 v2);
   CGLM_INLINE void  glm_vec4_maxv(vec4 v1, vec4 v2, vec4 dest);
   CGLM_INLINE void  glm_vec4_minv(vec4 v1, vec4 v2, vec4 dest);
   CGLM_INLINE void  glm_vec4_clamp(vec4 v, float minVal, float maxVal);
 */

#ifndef cglm_vec4_h
#define cglm_vec4_h

#include "common.h"
#include "vec4-ext.h"
#include "util.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glm_vec4_dup3(v, dest) glm_vec4_copy3(v, dest)
#define glm_vec4_dup(v, dest)  glm_vec4_copy(v, dest)

#define GLM_VEC4_ONE_INIT   {1.0f, 1.0f, 1.0f, 1.0f}
#define GLM_VEC4_BLACK_INIT {0.0f, 0.0f, 0.0f, 1.0f}
#define GLM_VEC4_ZERO_INIT  {0.0f, 0.0f, 0.0f, 0.0f}

#define GLM_VEC4_ONE        ((vec4)GLM_VEC4_ONE_INIT)
#define GLM_VEC4_BLACK      ((vec4)GLM_VEC4_BLACK_INIT)
#define GLM_VEC4_ZERO       ((vec4)GLM_VEC4_ZERO_INIT)

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
  _mm_store_ps(dest, _mm_load_ps(v));
#else
  dest[0] = v[0];
  dest[1] = v[1];
  dest[2] = v[2];
  dest[3] = v[3];
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
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
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
  return v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3];
}

/*!
 * @brief norm (magnitude) of vec4
 *
 * @param[in] vec vector
 *
 * @return norm
 */
CGLM_INLINE
float
glm_vec4_norm(vec4 vec) {
  return sqrtf(glm_vec4_norm2(vec));
}

/*!
 * @brief add v2 vector to v1 vector store result in dest
 *
 * @param[in]  v1 vector1
 * @param[in]  v2 vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_add(vec4 v1, vec4 v2, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest,
               _mm_add_ps(_mm_load_ps(v1),
                          _mm_load_ps(v2)));
#else
  dest[0] = v1[0] + v2[0];
  dest[1] = v1[1] + v2[1];
  dest[2] = v1[2] + v2[2];
  dest[3] = v1[3] + v2[3];
#endif
}

/*!
 * @brief subtract v2 vector from v1 vector store result in dest
 *
 * @param[in]  v1 vector1
 * @param[in]  v2 vector2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_sub(vec4 v1, vec4 v2, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest,
               _mm_sub_ps(_mm_load_ps(v1),
                          _mm_load_ps(v2)));
#else
  dest[0] = v1[0] - v2[0];
  dest[1] = v1[1] - v2[1];
  dest[2] = v1[2] - v2[2];
  dest[3] = v1[3] - v2[3];
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
  _mm_store_ps(dest,
               _mm_mul_ps(_mm_load_ps(v),
                          _mm_set1_ps(s)));
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

  if (norm == 0) {
    glm_vec4_copy(v, dest);
    return;
  }

  glm_vec4_scale(v, s / norm, dest);
}

/*!
 * @brief flip sign of all vec4 members
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec4_flipsign(vec4 v) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(v, _mm_xor_ps(_mm_load_ps(v),
                             _mm_set1_ps(-0.0f)));
#else
  v[0] = -v[0];
  v[1] = -v[1];
  v[2] = -v[2];
  v[3] = -v[3];
#endif
}

/*!
 * @brief make vector as inverse/opposite of itself
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec4_inv(vec4 v) {
  glm_vec4_flipsign(v);
}

/*!
 * @brief inverse/opposite vector
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_inv_to(vec4 v, vec4 dest) {
  glm_vec4_copy(v, dest);
  glm_vec4_flipsign(dest);
}

/*!
 * @brief normalize vec4 and store result in same vec
 *
 * @param[in, out] v vector
 */
CGLM_INLINE
void
glm_vec4_normalize(vec4 v) {
  float norm;

  norm = glm_vec4_norm(v);

  if (norm == 0.0f) {
    v[0] = v[1] = v[2] = v[3] = 0.0f;
    return;
  }

  glm_vec4_scale(v, 1.0f / norm, v);
}

/*!
 * @brief normalize vec4 to dest
 *
 * @param[in]  vec  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_normalize_to(vec4 vec, vec4 dest) {
  float norm;

  norm = glm_vec4_norm(vec);

  if (norm == 0.0f) {
    dest[0] = dest[1] = dest[2] = dest[3] = 0.0f;
    return;
  }

  glm_vec4_scale(vec, 1.0f / norm, dest);
}

/**
 * @brief distance between two vectors
 *
 * @param[in] v1 vector1
 * @param[in] v2 vector2
 * @return returns distance
 */
CGLM_INLINE
float
glm_vec4_distance(vec4 v1, vec4 v2) {
  return sqrtf(glm_pow2(v2[0] - v1[0])
             + glm_pow2(v2[1] - v1[1])
             + glm_pow2(v2[2] - v1[2])
             + glm_pow2(v2[3] - v1[3]));
}

/*!
 * @brief max values of vectors
 *
 * @param[in]  v1   vector1
 * @param[in]  v2   vector2
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_maxv(vec4 v1, vec4 v2, vec4 dest) {
  dest[0] = glm_max(v1[0], v2[0]);
  dest[1] = glm_max(v1[1], v2[1]);
  dest[2] = glm_max(v1[2], v2[2]);
  dest[3] = glm_max(v1[3], v2[3]);
}

/*!
 * @brief min values of vectors
 *
 * @param[in]  v1   vector1
 * @param[in]  v2   vector2
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec4_minv(vec4 v1, vec4 v2, vec4 dest) {
  dest[0] = glm_min(v1[0], v2[0]);
  dest[1] = glm_min(v1[1], v2[1]);
  dest[2] = glm_min(v1[2], v2[2]);
  dest[3] = glm_min(v1[3], v2[3]);
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
  v[0] = glm_clamp(v[0], minVal, maxVal);
  v[1] = glm_clamp(v[1], minVal, maxVal);
  v[2] = glm_clamp(v[2], minVal, maxVal);
  v[3] = glm_clamp(v[3], minVal, maxVal);
}

#endif /* cglm_vec4_h */
