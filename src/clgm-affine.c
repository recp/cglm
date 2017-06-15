/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm.h"
#include "../include/cglm-call.h"

CGLM_EXPORT
void
glmc_translate_to(mat4 m, vec3 v, mat4 dest) {
  glm_translate_to(m, v, dest);
}

CGLM_EXPORT
void
glmc_translate(mat4 m, vec3 v) {
  glm_translate(m, v);
}

CGLM_EXPORT
void
glmc_translate_x(mat4 m, float to) {
  glm_translate_x(m, to);
}

CGLM_EXPORT
void
glmc_translate_y(mat4 m, float to) {
  glm_translate_y(m, to);
}

CGLM_EXPORT
void
glmc_translate_z(mat4 m, float to) {
  glm_translate_z(m, to);
}

CGLM_EXPORT
void
glmc_scale_to(mat4 m, vec3 v, mat4 dest) {
  glm_scale_to(m, v, dest);
}

CGLM_EXPORT
void
glmc_scale(mat4 m, vec3 v) {
  glm_scale(m, v);
}

CGLM_EXPORT
void
glmc_scale1(mat4 m, float s) {
  glm_scale1(m, s);
}

CGLM_EXPORT
void
glmc_rotate_x(mat4 m, float rad, mat4 dest) {
  glm_rotate_x(m, rad, dest);
}

CGLM_EXPORT
void
glmc_rotate_y(mat4 m, float rad, mat4 dest) {
  glm_rotate_y(m, rad, dest);
}

CGLM_EXPORT
void
glmc_rotate_z(mat4 m, float rad, mat4 dest) {
  glm_rotate_z(m, rad, dest);
}

CGLM_EXPORT
void
glmc_rotate_ndc_make(mat4 m, float angle, vec3 axis_ndc) {
  glm_rotate_ndc_make(m, angle, axis_ndc);
}

CGLM_EXPORT
void
glmc_rotate_make(mat4 m, float angle, vec3 axis) {
  glm_rotate_make(m, angle, axis);
}

CGLM_EXPORT
void
glmc_rotate_ndc(mat4 m, float angle, vec3 axis_ndc) {
  glm_rotate_ndc(m, angle, axis_ndc);
}

CGLM_EXPORT
void
glmc_rotate(mat4 m, float angle, vec3 axis) {
  glm_rotate(m, angle, axis);
}

CGLM_EXPORT
void
glmc_decompose_scalev(mat4 m, vec3 s) {
  glm_decompose_scalev(m, s);
}

CGLM_EXPORT
void
glmc_decompose_rs(mat4 m, mat4 r, vec3 s) {
  glm_decompose_rs(m, r, s);
}

CGLM_EXPORT
void
glmc_decompose(mat4 m, vec4 t, mat4 r, vec3 s) {
  glm_decompose(m, t, r, s);
}
