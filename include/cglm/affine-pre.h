/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_pre_h
#define cglm_affine_pre_h

/*
 Functions:
   CGLM_INLINE void glm_translate_to(mat4 m, vec3 v, mat4 dest);
   CGLM_INLINE void glm_translate(mat4 m, vec3 v);
   CGLM_INLINE void glm_translate_x(mat4 m, float to);
   CGLM_INLINE void glm_translate_y(mat4 m, float to);
   CGLM_INLINE void glm_translate_z(mat4 m, float to);
   CGLM_INLINE void glm_rotate_x(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotate_y(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotate_z(mat4 m, float angle, mat4 dest);
   CGLM_INLINE void glm_rotate(mat4 m, float angle, vec3 axis);
   CGLM_INLINE void glm_rotate_at(mat4 m, vec3 pivot, float angle, vec3 axis);
   CGLM_INLINE void glm_rotate_atm(mat4 m, vec3 pivot, float angle, vec3 axis);
   CGLM_INLINE void glm_spin(mat4 m, float angle, vec3 axis);
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
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  translate vector [x, y, z]
 */
CGLM_INLINE
void
glm_translate(mat4 m, vec3 v) {
#if defined(CGLM_SIMD)
  glmm_128 m0, m1, m2, m3;

  m0 = glmm_load(m[0]);
  m1 = glmm_load(m[1]);
  m2 = glmm_load(m[2]);
  m3 = glmm_load(m[3]);

  glmm_store(m[3],
             glmm_fmadd(m0, glmm_set1(v[0]),
                        glmm_fmadd(m1, glmm_set1(v[1]),
                                   glmm_fmadd(m2, glmm_set1(v[2]), m3))));
#else
  glm_vec4_muladds(m[0], v[0], m[3]);
  glm_vec4_muladds(m[1], v[1], m[3]);
  glm_vec4_muladds(m[2], v[2], m[3]);
#endif
}

/*!
 * @brief translate existing transform matrix by v vector
 *        and store result in dest
 *
 * source matrix will remain same
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    translate vector [x, y, z]
 * @param[out] dest translated matrix
 */
CGLM_INLINE
void
glm_translate_to(mat4 m, vec3 v, mat4 dest) {
  glm_mat4_copy(m, dest);
  glm_translate(dest, v);
}

/*!
 * @brief translate existing transform matrix by x factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       x  x factor
 */
CGLM_INLINE
void
glm_translate_x(mat4 m, float x) {
#if defined(CGLM_SIMD)
  glmm_store(m[3], glmm_fmadd(glmm_load(m[0]), glmm_set1(x), glmm_load(m[3])));
#else
  vec4 v1;
  glm_vec4_scale(m[0], x, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

/*!
 * @brief translate existing transform matrix by y factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       y  y factor
 */
CGLM_INLINE
void
glm_translate_y(mat4 m, float y) {
#if defined(CGLM_SIMD)
  glmm_store(m[3], glmm_fmadd(glmm_load(m[1]), glmm_set1(y), glmm_load(m[3])));
#else
  vec4 v1;
  glm_vec4_scale(m[1], y, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

/*!
 * @brief translate existing transform matrix by z factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       z  z factor
 */
CGLM_INLINE
void
glm_translate_z(mat4 m, float z) {
#if defined(CGLM_SIMD)
  glmm_store(m[3], glmm_fmadd(glmm_load(m[2]), glmm_set1(z), glmm_load(m[3])));
#else
  vec4 v1;
  glm_vec4_scale(m[2], z, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

/*!
 * @brief rotate existing transform matrix around X axis by angle
 *        and store result in dest
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotate_x(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[1][1] =  c;
  t[1][2] =  s;
  t[2][1] = -s;
  t[2][2] =  c;

  glm_mul_rot(m, t, dest);
}

/*!
 * @brief rotate existing transform matrix around Y axis by angle
 *        and store result in dest
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotate_y(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[0][0] =  c;
  t[0][2] = -s;
  t[2][0] =  s;
  t[2][2] =  c;

  glm_mul_rot(m, t, dest);
}

/*!
 * @brief rotate existing transform matrix around Z axis by angle
 *        and store result in dest
 *
 * @param[in]   m      affine transfrom
 * @param[in]   angle  angle (radians)
 * @param[out]  dest   rotated matrix
 */
CGLM_INLINE
void
glm_rotate_z(mat4 m, float angle, mat4 dest) {
  CGLM_ALIGN_MAT mat4 t = GLM_MAT4_IDENTITY_INIT;
  float c, s;

  c = cosf(angle);
  s = sinf(angle);

  t[0][0] =  c;
  t[0][1] =  s;
  t[1][0] = -s;
  t[1][1] =  c;

  glm_mul_rot(m, t, dest);
}

/*!
 * @brief rotate existing transform matrix around given axis by angle
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_rotate(mat4 m, float angle, vec3 axis) {
  CGLM_ALIGN_MAT mat4 rot;
  glm_rotate_make(rot, angle, axis);
  glm_mul_rot(m, rot, m);
}

/*!
 * @brief rotate existing transform
 *        around given axis by angle at given pivot point (rotation center)
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       pivot  rotation center
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_rotate_at(mat4 m, vec3 pivot, float angle, vec3 axis) {
  CGLM_ALIGN(8) vec3 pivotInv;

  glm_vec3_negate_to(pivot, pivotInv);

  glm_translate(m, pivot);
  glm_rotate(m, angle, axis);
  glm_translate(m, pivotInv);
}

/*!
 * @brief creates NEW rotation matrix by angle and axis at given point
 *
 * this creates rotation matrix, it assumes you don't have a matrix
 *
 * this should work faster than glm_rotate_at because it reduces
 * one glm_translate.
 *
 * @param[out] m      affine transfrom
 * @param[in]  pivot  rotation center
 * @param[in]  angle  angle (radians)
 * @param[in]  axis   axis
 */
CGLM_INLINE
void
glm_rotate_atm(mat4 m, vec3 pivot, float angle, vec3 axis) {
  CGLM_ALIGN(8) vec3 pivotInv;

  glm_vec3_negate_to(pivot, pivotInv);

  glm_translate_make(m, pivot);
  glm_rotate(m, angle, axis);
  glm_translate(m, pivotInv);
}

/*!
 * @brief rotate existing transform matrix around given axis by angle around self (doesn't affected by position)
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 * @param[in]       axis   axis
 */
CGLM_INLINE
void
glm_spin(mat4 m, float angle, vec3 axis) {
  CGLM_ALIGN_MAT mat4 rot;
  glm_rotate_atm(rot, m[3], angle, axis);
  glm_mat4_mul(m, rot, m);
}

#endif /* cglm_affine_pre_h */
