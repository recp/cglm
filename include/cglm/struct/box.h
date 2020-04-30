/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_boxs_h
#define cglms_boxs_h

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
CGLM_DECL
void
glms_aabb_transform(vec3s box[2], mat4s m, vec3s dest[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  vec3 rawDest[2];

  glms_vec3_unpack(rawBox, box, 2);
  glm_aabb_transform(rawBox, m.raw, rawDest);
  glms_vec3_pack(dest, rawDest, 2);
}
#endif

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
CGLM_DECL
void
glms_aabb_merge(vec3s box1[2], vec3s box2[2], vec3s dest[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox1[2];
  vec3 rawBox2[2];
  vec3 rawDest[2];

  glms_vec3_unpack(rawBox1, box1, 2);
  glms_vec3_unpack(rawBox2, box2, 2);
  glm_aabb_merge(rawBox1, rawBox2, rawDest);
  glms_vec3_pack(dest, rawDest, 2);
}
#endif

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
CGLM_DECL
void
glms_aabb_crop(vec3s box[2], vec3s cropBox[2], vec3s dest[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  vec3 rawCropBox[2];
  vec3 rawDest[2];

  glms_vec3_unpack(rawBox, box, 2);
  glms_vec3_unpack(rawCropBox, cropBox, 2);
  glm_aabb_crop(rawBox, rawCropBox, rawDest);
  glms_vec3_pack(dest, rawDest, 2);
}
#endif

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
CGLM_DECL
void
glms_aabb_crop_until(vec3s box[2],
                     vec3s cropBox[2],
                     vec3s clampBox[2],
                     vec3s dest[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  glms_aabb_crop(box, cropBox, dest);
  glms_aabb_merge(clampBox, dest, dest);
}
#endif

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
CGLM_DECL
bool
glms_aabb_frustum(vec3s box[2], vec4s planes[6]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  vec4 rawPlanes[6];

  glms_vec3_unpack(rawBox, box, 2);
  glms_vec4_unpack(rawPlanes, planes, 6);
  return glm_aabb_frustum(rawBox, rawPlanes);
}
#endif

/*!
 * @brief invalidate AABB min and max values
 *
 * @param[in, out]  box bounding box
 */
CGLM_DECL
void
glms_aabb_invalidate(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  box[0] = glms_vec3_broadcast(FLT_MAX);
  box[1] = glms_vec3_broadcast(-FLT_MAX);
}
#endif

/*!
 * @brief check if AABB is valid or not
 *
 * @param[in]  box bounding box
 */
CGLM_DECL
bool
glms_aabb_isvalid(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  glms_vec3_unpack(rawBox, box, 2);
  return glm_aabb_isvalid(rawBox);
}
#endif

/*!
 * @brief distance between of min and max
 *
 * @param[in]  box bounding box
 */
CGLM_DECL
float
glms_aabb_size(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_distance(box[0].raw, box[1].raw);
}
#endif

/*!
 * @brief radius of sphere which surrounds AABB
 *
 * @param[in]  box bounding box
 */
CGLM_DECL
float
glms_aabb_radius(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glms_aabb_size(box) * 0.5f;
}
#endif

/*!
 * @brief computes center point of AABB
 *
 * @param[in]   box  bounding box
 * @returns center of bounding box
 */
CGLM_DECL
vec3s
glms_aabb_center(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glms_vec3_center(box[0], box[1]);
}
#endif

/*!
 * @brief check if two AABB intersects
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_DECL
bool
glms_aabb_aabb(vec3s box[2], vec3s other[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  vec3 rawOther[2];

  glms_vec3_unpack(rawBox, box, 2);
  glms_vec3_unpack(rawOther, other, 2);
  return glm_aabb_aabb(rawBox, rawOther);
}
#endif

/*!
 * @brief check if AABB intersects with sphere
 *
 * https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
 * Solid Box - Solid Sphere test.
 *
 * @param[in]   box    solid bounding box
 * @param[in]   s      solid sphere
 */
CGLM_DECL
bool
glms_aabb_sphere(vec3s box[2], vec4s s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];

  glms_vec3_unpack(rawBox, box, 2);
  return glm_aabb_sphere(rawBox, s.raw);
}
#endif

/*!
 * @brief check if point is inside of AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   point  point
 */
CGLM_DECL
bool
glms_aabb_point(vec3s box[2], vec3s point) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];

  glms_vec3_unpack(rawBox, box, 2);
  return glm_aabb_point(rawBox, point.raw);
}
#endif

/*!
 * @brief check if AABB contains other AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_DECL
bool
glms_aabb_contains(vec3s box[2], vec3s other[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 rawBox[2];
  vec3 rawOther[2];

  glms_vec3_unpack(rawBox, box, 2);
  glms_vec3_unpack(rawOther, other, 2);
  return glm_aabb_contains(rawBox, rawOther);
}
#endif

#endif /* cglms_boxs_h */
