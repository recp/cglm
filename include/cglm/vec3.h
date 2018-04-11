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
   glm_vec_dup(v, dest)
   GLM_VEC3_ONE_INIT
   GLM_VEC3_ZERO_INIT
   GLM_VEC3_ONE
   GLM_VEC3_ZERO
   GLM_YUP
   GLM_ZUP
   GLM_XUP

 Functions:
   CGLM_INLINE void  glm_vec3(vec4 v4, vec3 dest);
   CGLM_INLINE void  glm_vec_copy(vec3 a, vec3 dest);
   CGLM_INLINE float glm_vec_dot(vec3 a, vec3 b);
   CGLM_INLINE void  glm_vec_cross(vec3 a, vec3 b, vec3 d);
   CGLM_INLINE float glm_vec_norm2(vec3 v);
   CGLM_INLINE float glm_vec_norm(vec3 vec);
   CGLM_INLINE void  glm_vec_add(vec3 v1, vec3 v2, vec3 dest);
   CGLM_INLINE void  glm_vec_sub(vec3 v1, vec3 v2, vec3 dest);
   CGLM_INLINE void  glm_vec_scale(vec3 v, float s, vec3 dest);
   CGLM_INLINE void  glm_vec_scale_as(vec3 v, float s, vec3 dest);
   CGLM_INLINE void  glm_vec_flipsign(vec3 v);
   CGLM_INLINE void  glm_vec_inv(vec3 v);
   CGLM_INLINE void  glm_vec_inv_to(vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec_normalize(vec3 v);
   CGLM_INLINE void  glm_vec_normalize_to(vec3 vec, vec3 dest);
   CGLM_INLINE float glm_vec_distance(vec3 v1, vec3 v2);
   CGLM_INLINE float glm_vec_angle(vec3 v1, vec3 v2);
   CGLM_INLINE void  glm_vec_rotate(vec3 v, float angle, vec3 axis);
   CGLM_INLINE void  glm_vec_rotate_m4(mat4 m, vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec_proj(vec3 a, vec3 b, vec3 dest);
   CGLM_INLINE void  glm_vec_center(vec3 v1, vec3 v2, vec3 dest);
   CGLM_INLINE void  glm_vec_maxv(vec3 v1, vec3 v2, vec3 dest);
   CGLM_INLINE void  glm_vec_minv(vec3 v1, vec3 v2, vec3 dest);
   CGLM_INLINE void  glm_vec_ortho(vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec_clamp(vec3 v, float minVal, float maxVal);

 Convenient:
   CGLM_INLINE void  glm_cross(vec3 a, vec3 b, vec3 d);
   CGLM_INLINE float glm_dot(vec3 a, vec3 b);
   CGLM_INLINE void  glm_normalize(vec3 v);
   CGLM_INLINE void  glm_normalize_to(vec3 v, vec3 dest);
 */

#ifndef cglm_vec3_h
#define cglm_vec3_h

#include "common.h"
#include "vec3-ext.h"
#include "util.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glm_vec_dup(v, dest) glm_vec_copy(v, dest)

#define GLM_VEC3_ONE_INIT   {1.0f, 1.0f, 1.0f}
#define GLM_VEC3_ZERO_INIT  {0.0f, 0.0f, 0.0f}

#define GLM_VEC3_ONE  ((vec3)GLM_VEC3_ONE_INIT)
#define GLM_VEC3_ZERO ((vec3)GLM_VEC3_ZERO_INIT)

#define GLM_YUP  ((vec3){0.0f, 1.0f, 0.0f})
#define GLM_ZUP  ((vec3){0.0f, 0.0f, 1.0f})
#define GLM_XUP  ((vec3){1.0f, 0.0f, 0.0f})

/*!
 * @brief init vec3 using vec4
 *
 * @param[in]  v4   vector4
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec3(vec4 v4, vec3 dest) {
  dest[0] = v4[0];
  dest[1] = v4[1];
  dest[2] = v4[2];
}

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
 * @brief vec3 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_vec_dot(vec3 a, vec3 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
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
 * @param[in] v vector
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glm_vec_norm2(vec3 v) {
  return glm_vec_dot(v, v);
}

/*!
 * @brief norm (magnitude) of vec3
 *
 * @param[in] vec vector
 *
 * @return norm
 */
CGLM_INLINE
float
glm_vec_norm(vec3 vec) {
  return sqrtf(glm_vec_norm2(vec));
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
glm_vec_add(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] + v2[0];
  dest[1] = v1[1] + v2[1];
  dest[2] = v1[2] + v2[2];
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
glm_vec_sub(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] - v2[0];
  dest[1] = v1[1] - v2[1];
  dest[2] = v1[2] - v2[2];
}

/*!
 * @brief multiply/scale vec3 vector with scalar: result = v * s
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
 * @brief make vec3 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec_scale_as(vec3 v, float s, vec3 dest) {
  float norm;
  norm = glm_vec_norm(v);

  if (norm == 0) {
    glm_vec_copy(v, dest);
    return;
  }

  glm_vec_scale(v, s / norm, dest);
}

/*!
 * @brief flip sign of all vec3 members
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec_flipsign(vec3 v) {
  v[0] = -v[0];
  v[1] = -v[1];
  v[2] = -v[2];
}

/*!
 * @brief flip sign of all vec3 members and store result in dest
 *
 * @param[in]   v     vector
 * @param[out]  dest  result vector
 */
CGLM_INLINE
void
glm_vec_flipsign_to(vec3 v, vec3 dest) {
  dest[0] = -v[0];
  dest[1] = -v[1];
  dest[2] = -v[2];
}

/*!
 * @brief make vector as inverse/opposite of itself
 *
 * @param[in, out]  v  vector
 */
CGLM_INLINE
void
glm_vec_inv(vec3 v) {
  glm_vec_flipsign(v);
}

/*!
 * @brief inverse/opposite vector
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_vec_inv_to(vec3 v, vec3 dest) {
  glm_vec_copy(v, dest);
  glm_vec_flipsign(dest);
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
 * @brief angle betwen two vector
 *
 * @param[in] v1  vector1
 * @param[in] v2  vector2
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
  vec3   v1, v2, k;
  float  c, s;

  c = cosf(angle);
  s = sinf(angle);

  glm_vec_normalize_to(axis, k);

  /* Right Hand, Rodrigues' rotation formula:
        v = v*cos(t) + (kxv)sin(t) + k*(k.v)(1 - cos(t))
   */
  glm_vec_scale(v, c, v1);

  glm_vec_cross(k, v, v2);
  glm_vec_scale(v2, s, v2);

  glm_vec_add(v1, v2, v1);

  glm_vec_scale(k, glm_vec_dot(k, v) * (1.0f - c), v2);
  glm_vec_add(v1, v2, v);
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
 * @param[in]  a vector1
 * @param[in]  b vector2
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
 * @param[in]  v1 vector1
 * @param[in]  v2 vector2
 * @param[out] dest center point
 */
CGLM_INLINE
void
glm_vec_center(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_add(v1, v2, dest);
  glm_vec_scale(dest, 0.5f, dest);
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
glm_vec_distance(vec3 v1, vec3 v2) {
  return sqrtf(glm_pow2(v2[0] - v1[0])
             + glm_pow2(v2[1] - v1[1])
             + glm_pow2(v2[2] - v1[2]));
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
glm_vec_maxv(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = glm_max(v1[0], v2[0]);
  dest[1] = glm_max(v1[1], v2[1]);
  dest[2] = glm_max(v1[2], v2[2]);
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
glm_vec_minv(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = glm_min(v1[0], v2[0]);
  dest[1] = glm_min(v1[1], v2[1]);
  dest[2] = glm_min(v1[2], v2[2]);
}

/*!
 * @brief possible orthogonal/perpendicular vector
 *
 * @param[in]  v    vector
 * @param[out] dest orthogonal/perpendicular vector
 */
CGLM_INLINE
void
glm_vec_ortho(vec3 v, vec3 dest) {
  dest[0] = v[1] - v[2];
  dest[1] = v[2] - v[0];
  dest[2] = v[0] - v[1];
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
glm_vec_clamp(vec3 v, float minVal, float maxVal) {
  v[0] = glm_clamp(v[0], minVal, maxVal);
  v[1] = glm_clamp(v[1], minVal, maxVal);
  v[2] = glm_clamp(v[2], minVal, maxVal);
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
glm_vec_lerp(vec3 from, vec3 to, float t, vec3 dest) {
  vec3 s, v;

  /* from + s * (to - from) */
  glm_vec_broadcast(glm_clamp(t, 0.0f, 1.0f), s);
  glm_vec_sub(to, from, v);
  glm_vec_mulv(s, v, v);
  glm_vec_add(from, v, dest);
}

/*!
 * @brief vec3 cross product
 *
 * this is just convenient wrapper
 *
 * @param[in]  a source 1
 * @param[in]  b source 2
 * @param[out] d destination
 */
CGLM_INLINE
void
glm_cross(vec3 a, vec3 b, vec3 d) {
  glm_vec_cross(a, b, d);
}

/*!
 * @brief vec3 dot product
 *
 * this is just convenient wrapper
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glm_dot(vec3 a, vec3 b) {
  return glm_vec_dot(a, b);
}

/*!
 * @brief normalize vec3 and store result in same vec
 *
 * this is just convenient wrapper
 *
 * @param[in, out] v vector
 */
CGLM_INLINE
void
glm_normalize(vec3 v) {
  glm_vec_normalize(v);
}

/*!
 * @brief normalize vec3 to dest
 *
 * this is just convenient wrapper
 *
 * @param[in]  v    source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_normalize_to(vec3 v, vec3 dest) {
  glm_vec_normalize_to(v, dest);
}

#endif /* cglm_vec3_h */
