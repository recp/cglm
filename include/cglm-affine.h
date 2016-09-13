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
glm_translate_to(mat4 m, vec3 v, mat4 dest) {
  vec4 v1;
  vec4 v2;
  vec4 v3;
  mat4 t = GLM_MAT_IDENTITY_4F;

  glm_vec_scale4(t[0], v[0], v1);
  glm_vec_scale4(t[1], v[1], v2);
  glm_vec_scale4(t[2], v[2], v3);

  glm_vec_add4(v1, t[3], t[3]);
  glm_vec_add4(v2, t[3], t[3]);
  glm_vec_add4(v3, t[3], t[3]);

  glm__memcpy(float, dest, t, sizeof(mat4));
}

CGLM_INLINE
void
glm_translate(mat4 m, vec3 v) {
  vec4 v1;
  vec4 v2;
  vec4 v3;

  glm_vec_scale4(m[0], v[0], v1);
  glm_vec_scale4(m[1], v[1], v2);
  glm_vec_scale4(m[2], v[2], v3);

  glm_vec_add4(v1, m[3], m[3]);
  glm_vec_add4(v2, m[3], m[3]);
  glm_vec_add4(v3, m[3], m[3]);
}

CGLM_INLINE
void
glm_translate_x(mat4 m, float to) {
  vec4 v1;
  glm_vec_scale4(m[0], to, v1);
  glm_vec_add4(v1, m[3], m[3]);
}

CGLM_INLINE
void
glm_translate_y(mat4 m, float to) {
  vec4 v1;
  glm_vec_scale4(m[1], to, v1);
  glm_vec_add4(v1, m[3], m[3]);
}

CGLM_INLINE
void
glm_translate_z(mat4 m, float to) {
  vec4 v1;
  glm_vec_scale4(m[2], to, v1);
  glm_vec_add4(v1, m[3], m[3]);
}

/* scale */

CGLM_INLINE
void
glm_scale_to(mat4 m, vec3 v, mat4 dest) {
  glm_vec_scale4(m[0], v[0], dest[0]);
  glm_vec_scale4(m[1], v[1], dest[1]);
  glm_vec_scale4(m[2], v[2], dest[2]);

  glm_vec_dup4(m[3], dest[3]);
}

CGLM_INLINE
void
glm_scale(mat4 m, vec3 v) {
  glm_scale_to(m, v, m);
}

CGLM_INLINE
void
glm_scale1(mat4 m, float s) {
  glm_scale_to(m, (vec3){s, s, s}, m);
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
