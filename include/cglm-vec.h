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

#ifndef cglm_vec_h
#define cglm_vec_h

#include "cglm-common.h"
#include "cglm-vec-ext.h"
#include "arch/simd/cglm-intrin.h"
#include "cglm-util.h"

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  a    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec_copy(vec3 a, vec3 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
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
 * @param[in]  a    source
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
 * @brief vec3 dot product
 *
 * @param[in] a
 * @param[in] b
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_vec_dot(vec3 a, vec3 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/*!
 * @brief vec4 dot product
 *
 * @param[in] a
 * @param[in] b
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_vec4_dot(vec4 a, vec4 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

/*!
 * @brief vec3 cross product
 *
 * @param[in]  a source 1
 * @param[in]  b source 2
 * @param[out] d destination
 */
CGLM_INLINE
void
glm_vec_cross(vec3 a, vec3 b, vec3 d) {
  /* (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1) */
  d[0] = a[1] * b[2] - a[2] * b[1];
  d[1] = a[2] * b[0] - a[0] * b[2];
  d[2] = a[0] * b[1] - a[1] * b[0];
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call 
 * sqrtf fuction twice but with this func we can avoid func call, maybe this is 
 * not good name for this func
 *
 * @param[in] vec vec
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glm_vec_norm2(vec3 v) {
  return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

/*!
 * @brief norm (magnitude) of vec3
 *
 * @param[in] vec
 *
 * @return norm
 */
CGLM_INLINE
float
glm_vec_norm(vec3 vec) {
  return sqrtf(glm_vec_norm2(vec));
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf fuction twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] vec vec4
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
 * @param[in] vec
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
 * @param[in]  v1
 * @param[in]  v2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec_add(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] + v2[0];
  dest[1] = v1[1] + v2[1];
  dest[2] = v1[2] + v2[2];
}

/*!
 * @brief add v2 vector to v1 vector store result in dest
 *
 * @param[in]  v1
 * @param[in]  v2
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
 * @param[in]  v1
 * @param[in]  v2
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec_sub(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] - v2[0];
  dest[1] = v1[1] - v2[1];
  dest[2] = v1[2] - v2[2];
}

/*!
 * @brief subtract v2 vector from v1 vector store result in dest
 *
 * @param[in]  v1
 * @param[in]  v2
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
 * @brief multiply vec3 vector with scalar
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec_scale(vec3 v, float s, vec3 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
}

/*!
 * @brief flip sign of all vec3 members
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec_flipsign(vec3 v) {
  v[0] = -v[0];
  v[1] = -v[1];
  v[2] = -v[2];
}

/*!
 * @brief flip sign of all vec4 members
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
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
 * @brief multiply vec4 vector with scalar
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
 * @brief normalize vec3 and store result in same vec
 *
 * @param[in, out] v vector
 */
CGLM_INLINE
void
glm_vec_normalize(vec3 v) {
  float norm;

  norm = glm_vec_norm(v);

  if (norm == 0.0f) {
    v[0] = v[1] = v[2] = 0.0f;
    return;
  }

  glm_vec_scale(v, 1.0f / norm, v);
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
 * @brief normalize vec3 to dest
 *
 * @param[in]  vec  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec_normalize_to(vec3 vec, vec3 dest) {
  float norm;

  norm = glm_vec_norm(vec);

  if (norm == 0.0f) {
    dest[0] = dest[1] = dest[2] = 0.0f;
    return;
  }

  glm_vec_scale(vec, 1.0f / norm, dest);
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

/*!
 * @brief angle betwen two vector
 *
 * @return angle as radians
 */
CGLM_INLINE
float
glm_vec_angle(vec3 v1, vec3 v2) {
  float norm;
  
  /* maybe compiler generate approximation instruction (rcp) */
  norm = 1.0f / (glm_vec_norm(v1) * glm_vec_norm(v2));
  return acosf(glm_vec_dot(v1, v2) * norm);
}

CGLM_INLINE
void
glm_quatv(versor q,
          float  angle,
          vec3   v);

/*!
 * @brief rotate vec3 around axis by angle using Rodrigues' rotation formula
 *
 * @param[in, out] v     vector
 * @param[in]      axis  axis vector (must be unit vector)
 * @param[in]      angle angle by radians
 */
CGLM_INLINE
void
glm_vec_rotate(vec3 v, float angle, vec3 axis) {
  versor q;
  vec3   v1, v2, v3;
  float  c, s;

  c = cosf(angle);
  s = sinf(angle);

  /* Right Hand, Rodrigues' rotation formula:
        v = v*cos(t) + (kxv)sin(t) + k*(k.v)(1 - cos(t))
   */

  /* quaternion */
  glm_quatv(q, angle, v);

  glm_vec_scale(v, c, v1);

  glm_vec_cross(axis, v, v2);
  glm_vec_scale(v2, s, v2);

  glm_vec_scale(axis,
                glm_vec_dot(axis, v) * (1.0f - c),
                v3);

  glm_vec_add(v1, v2, v1);
  glm_vec_add(v1, v3, v);
}

/*!
 * @brief apply rotation matrix to vector
 *
 * @param[in]  m    affine matrix or rot matrix
 * @param[in]  v    vector
 * @param[out] dest rotated vector
 */
CGLM_INLINE
void
glm_vec_rotate_m4(mat4 m, vec3 v, vec3 dest) {
  vec3 res, x, y, z;

  glm_vec_normalize_to(m[0], x);
  glm_vec_normalize_to(m[1], y);
  glm_vec_normalize_to(m[2], z);

  res[0] = x[0] * v[0] + y[0] * v[1] + z[0] * v[2];
  res[1] = x[1] * v[0] + y[1] * v[1] + z[1] * v[2];
  res[2] = x[2] * v[0] + y[2] * v[1] + z[2] * v[2];

  glm_vec_copy(res, dest);
}

/*!
 * @brief project a vector onto b vector
 *
 * @param[in]  a
 * @param[in]  b
 * @param[out] dest projected vector
 */
CGLM_INLINE
void
glm_vec_proj(vec3 a, vec3 b, vec3 dest) {
  glm_vec_scale(b,
                glm_vec_dot(a, b) / glm_vec_norm2(b),
                dest);
}


/**
 * @brief find center point of two vector
 *
 * @param[in]  v1
 * @param[in]  v2
 * @param[out] dest center point
 */
CGLM_INLINE
void
glm_vec_center(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_add(v1, v2, dest);
  glm_vec_scale(dest, 0.5f, dest);
}

CGLM_INLINE
float
glm_vec_distance(vec3 v1, vec3 v2) {
  return sqrtf(glm_pow2(v2[0] - v1[0])
               + glm_pow2(v2[1] - v1[1])
               + glm_pow2(v2[2] - v1[2]));
}

CGLM_INLINE
float
glm_vec4_distance(vec4 v1, vec4 v2) {
  return sqrtf(glm_pow2(v2[0] - v1[0])
               + glm_pow2(v2[1] - v1[1])
               + glm_pow2(v2[2] - v1[2])
               + glm_pow2(v2[3] - v1[3]));
}

#endif /* cglm_vec_h */
