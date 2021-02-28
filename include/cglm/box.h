/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_box_h
#define cglm_box_h

#include "common.h"
#include "vec3.h"
#include "vec4.h"
#include "util.h"

/*!
 * @brief apply transform to Axis-Aligned Bounding Box
 *
 * @param[in]  box  bounding box
 * @param[in]  m    transform matrix
 * @param[out] dest transformed bounding box
 */
CGLM_INLINE
void
glm_aabb_transform(vec3 box[2], mat4 m, vec3 dest[2]) {
  vec3 v[2], xa, xb, ya, yb, za, zb;

  glm_vec3_scale(m[0], box[0][0], xa);
  glm_vec3_scale(m[0], box[1][0], xb);

  glm_vec3_scale(m[1], box[0][1], ya);
  glm_vec3_scale(m[1], box[1][1], yb);

  glm_vec3_scale(m[2], box[0][2], za);
  glm_vec3_scale(m[2], box[1][2], zb);

  /* translation + min(xa, xb) + min(ya, yb) + min(za, zb) */
  glm_vec3(m[3], v[0]);
  glm_vec3_minadd(xa, xb, v[0]);
  glm_vec3_minadd(ya, yb, v[0]);
  glm_vec3_minadd(za, zb, v[0]);

  /* translation + max(xa, xb) + max(ya, yb) + max(za, zb) */
  glm_vec3(m[3], v[1]);
  glm_vec3_maxadd(xa, xb, v[1]);
  glm_vec3_maxadd(ya, yb, v[1]);
  glm_vec3_maxadd(za, zb, v[1]);

  glm_vec3_copy(v[0], dest[0]);
  glm_vec3_copy(v[1], dest[1]);
}

/*!
 * @brief merges two AABB bounding box and creates new one
 *
 * two box must be in same space, if one of box is in different space then
 * you should consider to convert it's space by glm_box_space
 *
 * @param[in]  box1 bounding box 1
 * @param[in]  box2 bounding box 2
 * @param[out] dest merged bounding box
 */
CGLM_INLINE
void
glm_aabb_merge(vec3 box1[2], vec3 box2[2], vec3 dest[2]) {
  dest[0][0] = glm_min(box1[0][0], box2[0][0]);
  dest[0][1] = glm_min(box1[0][1], box2[0][1]);
  dest[0][2] = glm_min(box1[0][2], box2[0][2]);

  dest[1][0] = glm_max(box1[1][0], box2[1][0]);
  dest[1][1] = glm_max(box1[1][1], box2[1][1]);
  dest[1][2] = glm_max(box1[1][2], box2[1][2]);
}

/*!
 * @brief crops a bounding box with another one.
 *
 * this could be useful for gettng a bbox which fits with view frustum and
 * object bounding boxes. In this case you crop view frustum box with objects
 * box
 *
 * @param[in]  box     bounding box 1
 * @param[in]  cropBox crop box
 * @param[out] dest    cropped bounding box
 */
CGLM_INLINE
void
glm_aabb_crop(vec3 box[2], vec3 cropBox[2], vec3 dest[2]) {
  dest[0][0] = glm_max(box[0][0], cropBox[0][0]);
  dest[0][1] = glm_max(box[0][1], cropBox[0][1]);
  dest[0][2] = glm_max(box[0][2], cropBox[0][2]);

  dest[1][0] = glm_min(box[1][0], cropBox[1][0]);
  dest[1][1] = glm_min(box[1][1], cropBox[1][1]);
  dest[1][2] = glm_min(box[1][2], cropBox[1][2]);
}

/*!
 * @brief crops a bounding box with another one.
 *
 * this could be useful for gettng a bbox which fits with view frustum and
 * object bounding boxes. In this case you crop view frustum box with objects
 * box
 *
 * @param[in]  box      bounding box
 * @param[in]  cropBox  crop box
 * @param[in]  clampBox miniumum box
 * @param[out] dest     cropped bounding box
 */
CGLM_INLINE
void
glm_aabb_crop_until(vec3 box[2],
                    vec3 cropBox[2],
                    vec3 clampBox[2],
                    vec3 dest[2]) {
  glm_aabb_crop(box, cropBox, dest);
  glm_aabb_merge(clampBox, dest, dest);
}

/*!
 * @brief check if AABB intersects with frustum planes
 *
 * this could be useful for frustum culling using AABB.
 *
 * OPTIMIZATION HINT:
 *  if planes order is similar to LEFT, RIGHT, BOTTOM, TOP, NEAR, FAR
 *  then this method should run even faster because it would only use two
 *  planes if object is not inside the two planes
 *  fortunately cglm extracts planes as this order! just pass what you got!
 *
 * @param[in]  box     bounding box
 * @param[in]  planes  frustum planes
 */
CGLM_INLINE
bool
glm_aabb_frustum(vec3 box[2], vec4 planes[6]) {
  float *p, dp;
  int    i;

  for (i = 0; i < 6; i++) {
    p  = planes[i];
    dp = p[0] * box[p[0] > 0.0f][0]
       + p[1] * box[p[1] > 0.0f][1]
       + p[2] * box[p[2] > 0.0f][2];

    if (dp < -p[3])
      return false;
  }

  return true;
}

/*!
 * @brief invalidate AABB min and max values
 *
 * @param[in, out]  box bounding box
 */
CGLM_INLINE
void
glm_aabb_invalidate(vec3 box[2]) {
  glm_vec3_broadcast(FLT_MAX,  box[0]);
  glm_vec3_broadcast(-FLT_MAX, box[1]);
}

/*!
 * @brief check if AABB is valid or not
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
bool
glm_aabb_isvalid(vec3 box[2]) {
  return glm_vec3_max(box[0]) != FLT_MAX
         && glm_vec3_min(box[1]) != -FLT_MAX;
}

/*!
 * @brief distance between of min and max
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
float
glm_aabb_size(vec3 box[2]) {
  return glm_vec3_distance(box[0], box[1]);
}

/*!
 * @brief radius of sphere which surrounds AABB
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
float
glm_aabb_radius(vec3 box[2]) {
  return glm_aabb_size(box) * 0.5f;
}

/*!
 * @brief computes center point of AABB
 *
 * @param[in]   box  bounding box
 * @param[out]  dest center of bounding box
 */
CGLM_INLINE
void
glm_aabb_center(vec3 box[2], vec3 dest) {
  glm_vec3_center(box[0], box[1], dest);
}

/*!
 * @brief check if two AABB intersects
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glm_aabb_aabb(vec3 box[2], vec3 other[2]) {
  return (box[0][0] <= other[1][0] && box[1][0] >= other[0][0])
      && (box[0][1] <= other[1][1] && box[1][1] >= other[0][1])
      && (box[0][2] <= other[1][2] && box[1][2] >= other[0][2]);
}

/*!
 * @brief check if AABB intersects with sphere
 *
 * https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
 * Solid Box - Solid Sphere test.
 *
 * Sphere Representation in cglm: [center.x, center.y, center.z, radii]
 *
 * @param[in]   box    solid bounding box
 * @param[in]   s      solid sphere
 */
CGLM_INLINE
bool
glm_aabb_sphere(vec3 box[2], vec4 s) {
  float dmin;
  int   a, b, c;

  a = (s[0] < box[0][0]) + (s[0] > box[1][0]);
  b = (s[1] < box[0][1]) + (s[1] > box[1][1]);
  c = (s[2] < box[0][2]) + (s[2] > box[1][2]);

  dmin  = glm_pow2((s[0] - box[!(a - 1)][0]) * (a != 0))
        + glm_pow2((s[1] - box[!(b - 1)][1]) * (b != 0))
        + glm_pow2((s[2] - box[!(c - 1)][2]) * (c != 0));

  return dmin <= glm_pow2(s[3]);
}

/*!
 * @brief check if point is inside of AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   point  point
 */
CGLM_INLINE
bool
glm_aabb_point(vec3 box[2], vec3 point) {
  return (point[0] >= box[0][0] && point[0] <= box[1][0])
      && (point[1] >= box[0][1] && point[1] <= box[1][1])
      && (point[2] >= box[0][2] && point[2] <= box[1][2]);
}

/*!
 * @brief check if AABB contains other AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glm_aabb_contains(vec3 box[2], vec3 other[2]) {
  return (box[0][0] <= other[0][0] && box[1][0] >= other[1][0])
      && (box[0][1] <= other[0][1] && box[1][1] >= other[1][1])
      && (box[0][2] <= other[0][2] && box[1][2] >= other[1][2]);
}

#endif /* cglm_box_h */
