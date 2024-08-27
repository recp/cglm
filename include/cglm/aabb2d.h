/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_aabb2d_h
#define cglm_aabb2d_h

#include "common.h"
#include "vec2.h"
#include "util.h"

/* DEPRECATED! use _diag */
#define glm_aabb2d_size(aabb)         glm_aabb2d_diag(aabb)

/*!
 * @brief make [aabb] zero
 *
 * @param[in, out]  aabb aabb
 */
CGLM_INLINE
void
glm_aabb2d_zero(vec2 aabb[2]) {
  glm_vec2_zero(aabb[0]);
  glm_vec2_zero(aabb[1]);
}

/*!
 * @brief copy all members of [aabb] to [dest]
 *
 * @param[in]  aabb source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_aabb2d_copy(vec2 aabb[2], vec2 dest[2]) {
  glm_vec2_copy(aabb[0], dest[0]);
  glm_vec2_copy(aabb[1], dest[1]);
}

/*!
 * @brief apply transform to Axis-Aligned Bounding aabb
 *
 * @param[in]  aabb  bounding aabb
 * @param[in]  m    transform matrix
 * @param[out] dest transformed bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_transform(vec2 aabb[2], mat3 m, vec2 dest[2]) {
  vec2 v[2], xa, xb, ya, yb;

  glm_vec2_scale(m[0], aabb[0][0], xa);
  glm_vec2_scale(m[0], aabb[1][0], xb);

  glm_vec2_scale(m[1], aabb[0][1], ya);
  glm_vec2_scale(m[1], aabb[1][1], yb);

  /* translation + min(xa, xb) + min(ya, yb) */
  glm_vec2(m[2], v[0]);
  glm_vec2_minadd(xa, xb, v[0]);
  glm_vec2_minadd(ya, yb, v[0]);

  /* translation + max(xa, xb) + max(ya, yb) */
  glm_vec2(m[2], v[1]);
  glm_vec2_maxadd(xa, xb, v[1]);
  glm_vec2_maxadd(ya, yb, v[1]);

  glm_vec2_copy(v[0], dest[0]);
  glm_vec2_copy(v[1], dest[1]);
}

/*!
 * @brief merges two AABB bounding aabb and creates new one
 *
 * two aabb must be in same space, if one of aabb is in different space then
 * you should consider to convert it's space by glm_aabb_space
 *
 * @param[in]  aabb1 bounding aabb 1
 * @param[in]  aabb2 bounding aabb 2
 * @param[out] dest merged bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_merge(vec2 aabb1[2], vec2 aabb2[2], vec2 dest[2]) {
  dest[0][0] = glm_min(aabb1[0][0], aabb2[0][0]);
  dest[0][1] = glm_min(aabb1[0][1], aabb2[0][1]);

  dest[1][0] = glm_max(aabb1[1][0], aabb2[1][0]);
  dest[1][1] = glm_max(aabb1[1][1], aabb2[1][1]);
}

/*!
 * @brief crops a bounding aabb with another one.
 *
 * this could be useful for getting a baabb which fits with view frustum and
 * object bounding aabbes. In this case you crop view frustum aabb with objects
 * aabb
 *
 * @param[in]  aabb     bounding aabb 1
 * @param[in]  cropAabb crop aabb
 * @param[out] dest     cropped bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_crop(vec2 aabb[2], vec2 cropAabb[2], vec2 dest[2]) {
  dest[0][0] = glm_max(aabb[0][0], cropAabb[0][0]);
  dest[0][1] = glm_max(aabb[0][1], cropAabb[0][1]);

  dest[1][0] = glm_min(aabb[1][0], cropAabb[1][0]);
  dest[1][1] = glm_min(aabb[1][1], cropAabb[1][1]);
}

/*!
 * @brief crops a bounding aabb with another one.
 *
 * this could be useful for getting a baabb which fits with view frustum and
 * object bounding aabbes. In this case you crop view frustum aabb with objects
 * aabb
 *
 * @param[in]  aabb      bounding aabb
 * @param[in]  cropAabb  crop aabb
 * @param[in]  clampAabb minimum aabb
 * @param[out] dest      cropped bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_crop_until(vec2 aabb[2],
                      vec2 cropAabb[2],
                      vec2 clampAabb[2],
                      vec2 dest[2]) {
  glm_aabb2d_crop(aabb, cropAabb, dest);
  glm_aabb2d_merge(clampAabb, dest, dest);
}

/*!
 * @brief invalidate AABB min and max values
 *
 * @param[in, out]  aabb bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_invalidate(vec2 aabb[2]) {
  glm_vec2_fill(aabb[0], FLT_MAX);
  glm_vec2_fill(aabb[1], -FLT_MAX);
}

/*!
 * @brief check if AABB is valid or not
 *
 * @param[in]  aabb bounding aabb
 */
CGLM_INLINE
bool
glm_aabb2d_isvalid(vec2 aabb[2]) {
  return glm_vec2_max(aabb[0]) != FLT_MAX
         && glm_vec2_min(aabb[1]) != -FLT_MAX;
}

/*!
 * @brief distance between of min and max
 *
 * @param[in]  aabb bounding aabb
 */
CGLM_INLINE
float
glm_aabb2d_diag(vec2 aabb[2]) {
  return glm_vec2_distance(aabb[0], aabb[1]);
}

/*!
 * @brief size of aabb
 *
 * @param[in]  aabb bounding aabb
 * @param[out]  dest size
 */
CGLM_INLINE
void
glm_aabb2d_sizev(vec2 aabb[2], vec2 dest) {
  glm_vec2_sub(aabb[1], aabb[0], dest); 
}

/*!
 * @brief radius of sphere which surrounds AABB
 *
 * @param[in]  aabb bounding aabb
 */
CGLM_INLINE
float
glm_aabb2d_radius(vec2 aabb[2]) {
  return glm_aabb2d_diag(aabb) * 0.5f;
}

/*!
 * @brief computes center point of AABB
 *
 * @param[in]   aabb  bounding aabb
 * @param[out]  dest center of bounding aabb
 */
CGLM_INLINE
void
glm_aabb2d_center(vec2 aabb[2], vec2 dest) {
  glm_vec2_center(aabb[0], aabb[1], dest);
}

/*!
 * @brief check if two AABB intersects
 *
 * @param[in]   aabb    bounding aabb
 * @param[in]   other  other bounding aabb
 */
CGLM_INLINE
bool
glm_aabb2d_aabb(vec2 aabb[2], vec2 other[2]) {
  return (aabb[0][0] <= other[1][0] && aabb[1][0] >= other[0][0])
      && (aabb[0][1] <= other[1][1] && aabb[1][1] >= other[0][1]);
}

/*!
 * @brief check if AABB intersects with a circle
 *
 * Circle Representation in cglm: [center.x, center.y, radii]
 *
 * @param[in]   aabb   solid bounding aabb
 * @param[in]   c      solid circle
 */
CGLM_INLINE
bool
glm_aabb2d_circle(vec2 aabb[2], vec3 c) {
  float dmin;
  int   a, b;

  a = (c[0] < aabb[0][0]) + (c[0] > aabb[1][0]);
  b = (c[1] < aabb[0][1]) + (c[1] > aabb[1][1]);

  dmin  = glm_pow2((c[0] - aabb[!(a - 1)][0]) * (a != 0))
        + glm_pow2((c[1] - aabb[!(b - 1)][1]) * (b != 0));

  return dmin <= glm_pow2(c[2]);
}

/*!
 * @brief check if point is inside of AABB
 *
 * @param[in]   aabb    bounding aabb
 * @param[in]   point  point
 */
CGLM_INLINE
bool
glm_aabb2d_point(vec2 aabb[2], vec2 point) {
  return (point[0] >= aabb[0][0] && point[0] <= aabb[1][0])
      && (point[1] >= aabb[0][1] && point[1] <= aabb[1][1]);
}

/*!
 * @brief check if AABB contains other AABB
 *
 * @param[in]   aabb    bounding aabb
 * @param[in]   other  other bounding aabb
 */
CGLM_INLINE
bool
glm_aabb2d_contains(vec2 aabb[2], vec2 other[2]) {
  return (aabb[0][0] <= other[0][0] && aabb[1][0] >= other[1][0])
      && (aabb[0][1] <= other[0][1] && aabb[1][1] >= other[1][1]);
}

#endif /* cglm_aabb2d_h */
