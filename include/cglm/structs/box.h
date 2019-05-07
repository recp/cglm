/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_boxs_h
#define cglm_boxs_h

#include "../common.h"
#include "../types-struct.h"
#include "../box.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

/*!
 * @brief apply transform to Axis-Aligned Bounding Box
 *
 * @param[in]  box  bounding box
 * @param[in]  m    transform matrix
 * @param[out] dest transformed bounding box
 */
CGLM_INLINE
void
glms_aabb_transform(vec3s box[2], mat4s m, vec3s dest[2]) {
  vec3s v[2], xa, xb, ya, yb, za, zb;
	mat3s m3x3;

	m3x3 = glms_mat4_pick3(m);

  xa = glms_vec3_scale(m3x3.col[0], box[0].x);
  xb = glms_vec3_scale(m3x3.col[0], box[1].x);

  ya = glms_vec3_scale(m3x3.col[1], box[0].y);
  yb = glms_vec3_scale(m3x3.col[1], box[1].y);

  za = glms_vec3_scale(m3x3.col[2], box[0].z);
  zb = glms_vec3_scale(m3x3.col[2], box[1].z);

  /* translation + min(xa, xb) + min(ya, yb) + min(za, zb) */
  v[0] = m3x3.col[3];
  v[0] = glms_vec3_minadd(xa, xb);
  v[0] = glms_vec3_minadd(ya, yb);
  v[0] = glms_vec3_minadd(za, zb);

  /* translation + max(xa, xb) + max(ya, yb) + max(za, zb) */
  v[1] = m3x3.col[3];
  v[1] = glms_vec3_maxadd(xa, xb);
  v[1] = glms_vec3_maxadd(ya, yb);
  v[1] = glms_vec3_maxadd(za, zb);

  dest[0] = glms_vec3_copy(v[0]);
  dest[1] = glms_vec3_copy(v[1]);
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
glms_aabb_merge(vec3s box1[2], vec3s box2[2], vec3s dest[2]) {
  dest[0].x = glm_min(box1[0].x, box2[0].x);
  dest[0].y = glm_min(box1[0].y, box2[0].y);
  dest[0].z = glm_min(box1[0].z, box2[0].z);

  dest[1].x = glm_max(box1[1].x, box2[1].x);
  dest[1].y = glm_max(box1[1].y, box2[1].y);
  dest[1].z = glm_max(box1[1].z, box2[1].z);
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
glms_aabb_crop(vec3s box[2], vec3s cropBox[2], vec3s dest[2]) {
  dest[0].x = glm_max(box[0].x, cropBox[0].x);
  dest[0].y = glm_max(box[0].y, cropBox[0].y);
  dest[0].z = glm_max(box[0].z, cropBox[0].z);

  dest[1].x = glm_min(box[1].x, cropBox[1].x);
  dest[1].y = glm_min(box[1].y, cropBox[1].y);
  dest[1].z = glm_min(box[1].z, cropBox[1].z);
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
glms_aabb_crop_until(vec3s box[2],
                     vec3s cropBox[2],
                     vec3s clampBox[2],
                     vec3s dest[2]) {
  glms_aabb_crop(box, cropBox, dest);
  glms_aabb_merge(clampBox, dest, dest);
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
glms_aabb_frustum(vec3s box[2], vec4s planes[6]) {
	vec4s p;
  float dp;
  int    i;

  for (i = 0; i < 6; i++) {
    p  = planes[i];
    dp = p.x * box[p.x > 0.0f].x
       + p.y * box[p.y > 0.0f].y
       + p.z * box[p.z > 0.0f].z;

    if (dp < -p.w)
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
glms_aabb_invalidate(vec3s box[2]) {
  box[0] = glms_vec3_broadcast(FLT_MAX);
  box[1] = glms_vec3_broadcast(-FLT_MAX);
}

/*!
 * @brief check if AABB is valid or not
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
bool
glms_aabb_isvalid(vec3s box[2]) {
  return glms_vec3_max(box[0]) != FLT_MAX &&
         glms_vec3_min(box[1]) != -FLT_MAX;
}

/*!
 * @brief distance between of min and max
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
float
glms_aabb_size(vec3s box[2]) {
  return glms_vec3_distance(box[0], box[1]);
}

/*!
 * @brief radius of sphere which surrounds AABB
 *
 * @param[in]  box bounding box
 */
CGLM_INLINE
float
glms_aabb_radius(vec3s box[2]) {
  return glms_aabb_size(box) * 0.5f;
}

/*!
 * @brief computes center point of AABB
 *
 * @param[in]   box  bounding box
 * @param[out]  dest center of bounding box
 */
CGLM_INLINE
vec3s
glms_aabb_center(vec3s box[2]) {
  return glms_vec3_center(box[0], box[1]);
}

/*!
 * @brief check if two AABB intersects
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glms_aabb_aabb(vec3s box[2], vec3s other[2]) {
  return (box[0].x <= other[1].x && box[1].x >= other[0].x)
      && (box[0].y <= other[1].y && box[1].y >= other[0].y)
      && (box[0].z <= other[1].z && box[1].z >= other[0].z);
}

/*!
 * @brief check if AABB intersects with sphere
 *
 * https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
 * Solid Box - Solid Sphere test.
 *
 * @param[in]   box    solid bounding box
 * @param[in]   s      solid sphere
 */
CGLM_INLINE
bool
glms_aabb_sphere(vec3s box[2], vec4 s) {
  float dmin;
  int   a, b, c;

  a = s[0] >= box[0].x;
  b = s[1] >= box[0].y;
  c = s[2] >= box[0].z;

  dmin  = glm_pow2(s[0] - box[a].x)
        + glm_pow2(s[1] - box[b].y)
        + glm_pow2(s[2] - box[c].z);

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
glms_aabb_point(vec3s box[2], vec3s point) {
  return (point.x >= box[0].x && point.x <= box[1].x)
      && (point.y >= box[0].y && point.y <= box[1].y)
      && (point.z >= box[0].z && point.z <= box[1].z);
}

/*!
 * @brief check if AABB contains other AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glms_aabb_contains(vec3s box[2], vec3s other[2]) {
  return (box[0].x <= other[0].x && box[1].x >= other[1].x)
      && (box[0].y <= other[0].y && box[1].y >= other[1].y)
      && (box[0].z <= other[0].z && box[1].z >= other[1].z);
}

#endif /* cglm_boxs_h */
