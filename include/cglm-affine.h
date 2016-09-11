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
glm_tmove_z(mat4 m, float to) {
  m[3][2] = to;
}

#endif /* cglm_affine_h */
