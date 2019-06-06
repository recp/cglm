/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
void
glmc_translate_make(mat4 m, vec3 v) {
  glm_translate_make(m, v);
}

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
glmc_scale_make(mat4 m, vec3 v) {
  glm_scale_make(m, v);
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
glmc_scale_uni(mat4 m, float s) {
  glm_scale_uni(m, s);
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
glmc_rotate_make(mat4 m, float angle, vec3 axis) {
  glm_rotate_make(m, angle, axis);
}

CGLM_EXPORT
void
glmc_rotate(mat4 m, float angle, vec3 axis) {
  glm_rotate(m, angle, axis);
}

CGLM_EXPORT
void
glmc_rotate_at(mat4 m, vec3 pivot, float angle, vec3 axis) {
  glm_rotate_at(m, pivot, angle, axis);
}

CGLM_EXPORT
void
glmc_rotate_atm(mat4 m, vec3 pivot, float angle, vec3 axis) {
  glm_rotate_atm(m, pivot, angle, axis);
}

CGLM_EXPORT
void
glmc_decompose_scalev(mat4 m, vec3 s) {
  glm_decompose_scalev(m, s);
}

CGLM_EXPORT
bool
glmc_uniscaled(mat4 m) {
  return glm_uniscaled(m);
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

CGLM_EXPORT
void
glmc_mul(mat4 m1, mat4 m2, mat4 dest) {
  glm_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mul_rot(mat4 m1, mat4 m2, mat4 dest) {
  glm_mul_rot(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_inv_tr(mat4 mat) {
  glm_inv_tr(mat);
}
