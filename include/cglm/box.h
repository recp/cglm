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
  vec3 v[2], xa, xb, ya, yb, za, zb, tmp;

  glm_vec_scale(m[0], box[0][0], xa);
  glm_vec_scale(m[0], box[1][0], xb);

  glm_vec_scale(m[1], box[0][1], ya);
  glm_vec_scale(m[1], box[1][1], yb);

  glm_vec_scale(m[2], box[0][2], za);
  glm_vec_scale(m[2], box[1][2], zb);

  /* min(xa, xb) + min(ya, yb) + min(za, zb) + translation */
  glm_vec_minv(xa, xb, v[0]);
  glm_vec_minv(ya, yb, tmp);
  glm_vec_add(v[0], tmp, v[0]);
  glm_vec_minv(za, zb, tmp);
  glm_vec_add(v[0], tmp, v[0]);
  glm_vec_add(v[0], m[3], v[0]);

  /* max(xa, xb) + max(ya, yb) + max(za, zb) + translation */
  glm_vec_maxv(xa, xb, v[1]);
  glm_vec_maxv(ya, yb, tmp);
  glm_vec_add(v[1], tmp, v[1]);
  glm_vec_maxv(za, zb, tmp);
  glm_vec_add(v[1], tmp, v[1]);
  glm_vec_add(v[1], m[3], v[1]);

  glm_vec_copy(v[0], dest[0]);
  glm_vec_copy(v[1], dest[1]);
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

#endif /* cglm_box_h */
