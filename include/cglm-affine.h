/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_h
#define cglm_affine_h

#include "cglm.h"

CGLM_INLINE
void
glm_translate(mat4 m, vec3 v, mat4 dest) {
  dest[3][0] = m[3][0] + v[0];
  dest[3][1] = m[3][1] + v[1];
  dest[3][2] = m[3][2] + v[2];
}

CGLM_INLINE
void
glm_translate_self(mat4 m, vec3 v) {
  m[3][0] += v[0];
  m[3][1] += v[1];
  m[3][2] += v[2];
}

CGLM_INLINE
void
glm_translate_x(mat4 m, float to) {
  m[3][0] += to;
}

CGLM_INLINE
void
glm_translate_y(mat4 m, float to) {
  m[3][1] += to;
}

CGLM_INLINE
void
glm_translate_z(mat4 m, float to) {
  m[3][2] += to;
}

/* move */

CGLM_INLINE
void
glm_move(mat4 m, vec3 v) {
  m[3][0] = v[0];
  m[3][1] = v[1];
  m[3][2] = v[2];
}

CGLM_INLINE
void
glm_move_x(mat4 m, float to) {
  m[3][0] = to;
}

CGLM_INLINE
void
glm_move_y(mat4 m, float to) {
  m[3][1] = to;
}

CGLM_INLINE
void
glm_move_z(mat4 m, float to) {
  m[3][2] = to;
}

/* scale */

CGLM_INLINE
void
glm_scale(mat4 m, vec3 v, mat4 dest) {
  dest[0][0] = m[0][0] * v[0];
  dest[1][1] = m[1][1] * v[1];
  dest[2][2] = m[2][2] * v[2];
}

CGLM_INLINE
void
glm_scale_self(mat4 m, vec3 v) {
  m[0][0] *= v[0];
  m[1][1] *= v[1];
  m[2][2] *= v[2];
}

CGLM_INLINE
void
glm_scale1_self(mat4 m, float s) {
  m[0][0] *= s;
  m[1][1] *= s;
  m[2][2] *= s;
}

CGLM_INLINE
void
glm_rotate_x(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT_IDENTITY_4F;

  cosVal = cos(rad);
  sinVal = sin(rad);

  t[1][1] =  cosVal;
  t[1][2] =  sinVal;
  t[2][1] = -sinVal;
  t[2][2] =  cosVal;

  glm_mat_mul4(t, m, dest);
}

CGLM_INLINE
void
glm_rotate_y(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT_IDENTITY_4F;

  cosVal = cos(rad);
  sinVal = sin(rad);

  t[0][0] =  cosVal;
  t[0][2] = -sinVal;
  t[2][0] =  sinVal;
  t[2][2] =  cosVal;

  glm_mat_mul4(t, m, dest);
}

CGLM_INLINE
void
glm_rotate_z(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT_IDENTITY_4F;

  cosVal = cos(rad);
  sinVal = sin(rad);

  t[0][0] =  cosVal;
  t[0][1] =  sinVal;
  t[1][0] = -sinVal;
  t[1][1] =  cosVal;

  glm_mat_mul4(t, m, dest);
}

#endif /* cglm_affine_h */
