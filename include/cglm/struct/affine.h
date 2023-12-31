/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE mat4s glms_translate(mat4s m, vec3s v);
   CGLM_INLINE mat4s glms_translate_x(mat4s m, float x);
   CGLM_INLINE mat4s glms_translate_y(mat4s m, float y);
   CGLM_INLINE mat4s glms_translate_z(mat4s m, float z);
   CGLM_INLINE mat4s glms_translate_make(vec3s v);
   CGLM_INLINE mat4s glms_scale_to(mat4s m, vec3s v);
   CGLM_INLINE mat4s glms_scale_make(vec3s v);
   CGLM_INLINE mat4s glms_scale(mat4s m, vec3s v);
   CGLM_INLINE mat4s glms_scale_uni(mat4s m, float s);
   CGLM_INLINE mat4s glms_rotate_x(mat4s m, float angle);
   CGLM_INLINE mat4s glms_rotate_y(mat4s m, float angle);
   CGLM_INLINE mat4s glms_rotate_z(mat4s m, float angle);
   CGLM_INLINE mat4s glms_rotate_make(float angle, vec3s axis);
   CGLM_INLINE mat4s glms_rotate(mat4s m, float angle, vec3s axis);
   CGLM_INLINE mat4s glms_rotate_at(mat4s m, vec3s pivot, float angle, vec3s axis);
   CGLM_INLINE mat4s glms_rotate_atm(vec3s pivot, float angle, vec3s axis);
   CGLM_INLINE mat4s glms_spin(mat4s m, float angle, vec3s axis);
   CGLM_INLINE vec3s glms_decompose_scalev(mat4s m);
   CGLM_INLINE bool  glms_uniscaled(mat4s m);
   CGLM_INLINE void  glms_decompose_rs(mat4s m, mat4s * r, vec3s * s);
   CGLM_INLINE void  glms_decompose(mat4s m, vec4s t, mat4s * r, vec3s * s);
 */

#ifndef cglms_affines_h
#define cglms_affines_h

#include "../common.h"
#include "../types-struct.h"
#include "../affine.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "affine-mat.h"

/*!
 * @brief creates NEW translate transform matrix by v vector
 *
 * @param[in]   v   translate vector [x, y, z]
 * @returns         affine transfrom
 */
CGLM_INLINE
mat4s
glms_translate_make(vec3s v) {
  mat4s m;
  glm_translate_make(m.raw, v.raw);
  return m;
}

/*!
 * @brief creates NEW scale matrix by v vector
 *
 * @param[in]   v  scale vector [x, y, z]
 * @returns affine transfrom
 */
CGLM_INLINE
mat4s
glms_scale_make(vec3s v) {
  mat4s m;
  glm_scale_make(m.raw, v.raw);
  return m;
}

/*!
 * @brief scales existing transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in]    m   affine transfrom
 * @param[in]    v   scale vector [x, y, z]
 * @returns          affine transfrom
 */
CGLM_INLINE
mat4s
glms_scale(mat4s m, vec3s v) {
  mat4s r;
  glm_scale_to(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief applies uniform scale to existing transform matrix v = [s, s, s]
 *        and stores result in same matrix
 *
 * @param[in]    m   affine transfrom
 * @param[in]    s   scale factor
 * @returns          affine transfrom
 */
CGLM_INLINE
mat4s
glms_scale_uni(mat4s m, float s) {
  glm_scale_uni(m.raw, s);
  return m;
}

/*!
 * @brief creates NEW rotation matrix by angle and axis
 *
 * axis will be normalized so you don't need to normalize it
 *
 * @param[in]  angle  angle (radians)
 * @param[in]  axis   axis
 * @returns           affine transfrom
 */
CGLM_INLINE
mat4s
glms_rotate_make(float angle, vec3s axis) {
  mat4s m;
  glm_rotate_make(m.raw, angle, axis.raw);
  return m;
}

/*!
 * @brief creates NEW rotation matrix by angle and axis at given point
 *
 * this creates rotation matrix, it assumes you don't have a matrix
 *
 * this should work faster than glm_rotate_at because it reduces
 * one glm_translate.
 *
 * @param[in]  pivot  rotation center
 * @param[in]  angle  angle (radians)
 * @param[in]  axis   axis
 * @returns           affine transfrom
 */
CGLM_INLINE
mat4s
glms_rotate_atm(vec3s pivot, float angle, vec3s axis) {
  mat4s m;
  glm_rotate_atm(m.raw, pivot.raw, angle, axis.raw);
  return m;
}

/*!
 * @brief decompose scale vector
 *
 * @param[in]  m  affine transform
 * @returns       scale vector (Sx, Sy, Sz)
 */
CGLM_INLINE
vec3s
glms_decompose_scalev(mat4s m) {
  vec3s r;
  glm_decompose_scalev(m.raw, r.raw);
  return r;
}

/*!
 * @brief returns true if matrix is uniform scaled. This is helpful for
 *        creating normal matrix.
 *
 * @param[in] m m
 *
 * @return boolean
 */
CGLM_INLINE
bool
glms_uniscaled(mat4s m) {
  return glm_uniscaled(m.raw);
}

/*!
 * @brief decompose rotation matrix (mat4) and scale vector [Sx, Sy, Sz]
 *        DON'T pass projected matrix here
 *
 * @param[in]  m affine transform
 * @param[out] r rotation matrix
 * @param[out] s scale matrix
 */
CGLM_INLINE
void
glms_decompose_rs(mat4s m, mat4s * __restrict r, vec3s * __restrict s) {
  glm_decompose_rs(m.raw, r->raw, s->raw);
}

/*!
 * @brief decompose affine transform, TODO: extract shear factors.
 *        DON'T pass projected matrix here
 *
 * @param[in]  m affine transfrom
 * @param[out] t translation vector
 * @param[out] r rotation matrix (mat4)
 * @param[out] s scaling vector [X, Y, Z]
 */
CGLM_INLINE
void
glms_decompose(mat4s m, vec4s * __restrict t, mat4s * __restrict r, vec3s * __restrict s) {
  glm_decompose(m.raw, t->raw, r->raw, s->raw);
}

#include "affine-pre.h"
#include "affine-post.h"

#endif /* cglms_affines_h */
