/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_aabb2ds_h
#define cglms_aabb2ds_h

#include "../common.h"
#include "../types-struct.h"
#include "../aabb2d.h"
#include "vec2.h"
#include "vec4.h"
#include "mat4.h"

/* api definition */
#define glms_aabb2d_(NAME) CGLM_STRUCTAPI(aabb2d, NAME)

/*!
 * @brief apply transform to Axis-Aligned Bounding Box
 *
 * @param[in]  aabb  bounding box
 * @param[in]  m    transform matrix
 * @param[out] dest transformed bounding box
 */
CGLM_INLINE
void
glms_aabb2d_(transform)(vec2s aabb[2], mat3s m, vec2s dest[2]) {
  vec2 rawAabb[2];
  vec2 rawDest[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  glm_aabb2d_transform(rawAabb, m.raw, rawDest);
  glms_vec2_(pack)(dest, rawDest, 2);
}

/*!
 * @brief merges two AABB bounding box and creates new one
 *
 * two box must be in same space, if one of box is in different space then
 * you should consider to convert it's space by glm_box_space
 *
 * @param[in]  aabb1 bounding box 1
 * @param[in]  aabb2 bounding box 2
 * @param[out] dest merged bounding box
 */
CGLM_INLINE
void
glms_aabb2d_(merge)(vec2s aabb1[2], vec2s aabb2[2], vec2s dest[2]) {
  vec2 rawAabb1[2];
  vec2 rawAabb2[2];
  vec2 rawDest[2];

  glms_vec2_(unpack)(rawAabb1, aabb1, 2);
  glms_vec2_(unpack)(rawAabb2, aabb2, 2);
  glm_aabb2d_merge(rawAabb1, rawAabb2, rawDest);
  glms_vec2_(pack)(dest, rawDest, 2);
}

/*!
 * @brief crops a bounding box with another one.
 *
 * this could be useful for gettng a bbox which fits with view frustum and
 * object bounding boxes. In this case you crop view frustum box with objects
 * box
 *
 * @param[in]  aabb     bounding box 1
 * @param[in]  cropAabb crop box
 * @param[out] dest    cropped bounding box
 */
CGLM_INLINE
void
glms_aabb2d_(crop)(vec2s aabb[2], vec2s cropAabb[2], vec2s dest[2]) {
  vec2 rawAabb[2];
  vec2 rawCropAabb[2];
  vec2 rawDest[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  glms_vec2_(unpack)(rawCropAabb, cropAabb, 2);
  glm_aabb2d_crop(rawAabb, rawCropAabb, rawDest);
  glms_vec2_(pack)(dest, rawDest, 2);
}

/*!
 * @brief crops a bounding box with another one.
 *
 * this could be useful for gettng a bbox which fits with view frustum and
 * object bounding boxes. In this case you crop view frustum box with objects
 * box
 *
 * @param[in]  aabb      bounding box
 * @param[in]  cropAabb  crop box
 * @param[in]  clampAabb minimum box
 * @param[out] dest     cropped bounding box
 */
CGLM_INLINE
void
glms_aabb2d_(crop_until)(vec2s aabb[2],
                       vec2s cropAabb[2],
                       vec2s clampAabb[2],
                       vec2s dest[2]) {
  glms_aabb2d_(crop)(aabb, cropAabb, dest);
  glms_aabb2d_(merge)(clampAabb, dest, dest);
}

/*!
 * @brief invalidate AABB min and max values
 *
 * @param[in, out]  aabb bounding box
 */
CGLM_INLINE
void
glms_aabb2d_(invalidate)(vec2s box[2]) {
  box[0] = glms_vec2_(fill)(FLT_MAX);
  box[1] = glms_vec2_(fill)(-FLT_MAX);
}

/*!
 * @brief check if AABB is valid or not
 *
 * @param[in]  aabb bounding box
 */
CGLM_INLINE
bool
glms_aabb2d_(isvalid)(vec2s aabb[2]) {
  vec2 rawAabb[2];
  glms_vec2_(unpack)(rawAabb, aabb, 2);
  return glm_aabb2d_isvalid(rawAabb);
}

/*!
 * @brief distance between of min and max
 *
 * @param[in]  aabb bounding box
 */
CGLM_INLINE
float
glms_aabb2d_(size)(vec2s aabb[2]) {
  return glm_vec2_distance(aabb[0].raw, aabb[1].raw);
}

/*!
 * @brief radius of sphere which surrounds AABB
 *
 * @param[in]  aabb bounding box
 */
CGLM_INLINE
float
glms_aabb2d_(radius)(vec2s aabb[2]) {
  return glms_aabb2d_(size)(aabb) * 0.5f;
}

/*!
 * @brief computes center point of AABB
 *
 * @param[in]   aabb  bounding box
 * @returns center of bounding box
 */
CGLM_INLINE
vec2s
glms_aabb2d_(center)(vec2s aabb[2]) {
  return glms_vec2_(center)(aabb[0], aabb[1]);
}

/*!
 * @brief check if two AABB intersects
 *
 * @param[in]   aabb   bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glms_aabb2d_(aabb)(vec2s aabb[2], vec2s other[2]) {
  vec2 rawAabb[2];
  vec2 rawOther[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  glms_vec2_(unpack)(rawOther, other, 2);
  return glm_aabb2d_aabb(rawAabb, rawOther);
}

/*!
 * @brief check if AABB intersects with a circle
 *
 * https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
 * Solid Box - Solid Sphere test.
 *
 * @param[in]   aabb   solid bounding box
 * @param[in]   s      solid sphere
 */
CGLM_INLINE
bool
glms_aabb2d_(circle)(vec2s aabb[2], vec3s c) {
  vec2 rawAabb[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  return glm_aabb2d_circle(rawAabb, c.raw);
}

/*!
 * @brief check if point is inside of AABB
 *
 * @param[in]   aabb   bounding box
 * @param[in]   point  point
 */
CGLM_INLINE
bool
glms_aabb2d_(point)(vec2s aabb[2], vec2s point) {
  vec2 rawAabb[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  return glm_aabb2d_point(rawAabb, point.raw);
}

/*!
 * @brief check if AABB contains other AABB
 *
 * @param[in]   box    bounding box
 * @param[in]   other  other bounding box
 */
CGLM_INLINE
bool
glms_aabb2d_(contains)(vec2s aabb[2], vec2s other[2]) {
  vec2 rawAabb[2];
  vec2 rawOther[2];

  glms_vec2_(unpack)(rawAabb, aabb, 2);
  glms_vec2_(unpack)(rawOther, other, 2);
  return glm_aabb2d_contains(rawAabb, rawOther);
}

#endif /* cglms_aabb2ds_h */

