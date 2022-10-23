/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_post_h
#define cglm_affine_post_h

/*
 Functions:
   CGLM_INLINE void glm_translated_to(mat4 m, vec3 v, mat4 dest);
   CGLM_INLINE void glm_translated(mat4 m, vec3 v);
   CGLM_INLINE void glm_translated_x(mat4 m, float to);
   CGLM_INLINE void glm_translated_y(mat4 m, float to);
   CGLM_INLINE void glm_translated_z(mat4 m, float to);
   CGLM_INLINE void glm_rotated_x(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotated_y(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotated_z(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotated(mat4 m, float angle, vec3 axis);
   CGLM_INLINE void glm_rotated_at(mat4 m, vec3 pivot, float angle, vec3 axis);
   CGLM_INLINE void glm_spinned(mat4 m, float angle, vec3 axis);
 */

#include "common.h"
#include "util.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "affine-mat.h"

/*!
 * @brief translate existing transform matrix by v vector
 *        and stores result in same matrix
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  translate vector [x, y, z]
 */
CGLM_INLINE
void
glm_translated(mat4 m, vec3 v) {
  glm_vec3_add(m[3], v, m[3]);
}

/*!
 * @brief translate existing transform matrix by v vector
 *        and store result in dest
 *
 * source matrix will remain same
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    translate vector [x, y, z]
 * @param[out] dest translated matrix
 */
CGLM_INLINE
void
glm_translated_to(mat4 m, vec3 v, mat4 dest) {
  glm_mat4_copy(m, dest);
  glm_translated(dest, v);
}

/*!
 * @brief translate existing transform matrix by x factor
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       x  x factor
 */
CGLM_INLINE
void
glm_translated_x(mat4 m, float x) {
  m[3][0] += x;
}

/*!
 * @brief translate existing transform matrix by y factor
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       y  y factor
 */
CGLM_INLINE
void
glm_translated_y(mat4 m, float y) {
  m[3][1] += y;
}

/*!
 * @brief translate existing transform matrix by z factor
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       z  z factor
 */
CGLM_INLINE
void
glm_translated_z(mat4 m, float z) {
  m[3][2] += z;
}

/*!
 * @brief rotate existing transform matrix around X axis by angle
 *        and store result in dest
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotated_x(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[1][1] =  c;
  t[1][2] =  s;
  t[2][1] = -s;
  t[2][2] =  c;

  glm_mul_rot(t, m, dest);
}

/*!
 * @brief rotate existing transform matrix around Y axis by angle
 *        and store result in dest
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotated_y(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[0][0] =  c;
  t[0][2] = -s;
  t[2][0] =  s;
  t[2][2] =  c;

  glm_mul_rot(t, m, dest);
}

/*!
 * @brief rotate existing transform matrix around Z axis by angle
 *        and store result in dest
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotated_z(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[0][0] =  c;
  t[0][1] =  s;
  t[1][0] = -s;
  t[1][1] =  c;

  glm_mul_rot(t, m, dest);
}

/*!
 * @brief rotate existing transform matrix around given axis by angle
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_rotated(mat4 m, float angle, vec3 axis) {
  CGLM_ALIGN_MAT mat4 rot;
  glm_rotate_make(rot, angle, axis);
  glm_mul_rot(rot, m, m);
}

/*!
 * @brief rotate existing transform
 *        around given axis by angle at given pivot point (rotation center)
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       pivot  rotation center
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_rotated_at(mat4 m, vec3 pivot, float angle, vec3 axis) {
  CGLM_ALIGN(8) vec3 pivotInv;

  glm_vec3_negate_to(pivot, pivotInv);

  glm_translated(m, pivot);
  glm_rotated(m, angle, axis);
  glm_translated(m, pivotInv);
}

/*!
 * @brief rotate existing transform matrix around given axis by angle around self (doesn't affected by position)
 *
 *  this is POST transform, applies to existing transform as last transfrom
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_spinned(mat4 m, float angle, vec3 axis) {
  CGLM_ALIGN_MAT mat4 rot;
  glm_rotate_atm(rot, m[3], angle, axis);
  glm_mat4_mul(rot, m, m);
}

#endif /* cglm_affine_post_h */
