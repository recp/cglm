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
glmc_quat_identity(versor q) {
  glm_quat_identity(q);
}

CGLM_EXPORT
void
glmc_quat_identity_array(versor * const __restrict q, size_t count) {
  glm_quat_identity_array(q, count);
}

CGLM_EXPORT
void
glmc_quat_init(versor q, float x, float y, float z, float w) {
  glm_quat_init(q, x, y, z, w);
}

CGLM_EXPORT
void
glmc_quat(versor q, float angle, float x, float y, float z) {
  glm_quat(q, angle, x, y, z);
}

CGLM_EXPORT
void
glmc_quatv(versor q, float angle, const vec3 axis) {
  glm_quatv(q, angle, axis);
}

CGLM_EXPORT
void
glmc_quat_copy(const versor q, versor dest) {
  glm_quat_copy(q, dest);
}

CGLM_EXPORT
float
glmc_quat_norm(const versor q) {
  return glm_quat_norm(q);
}

CGLM_EXPORT
void
glmc_quat_normalize_to(const versor q, versor dest) {
  glm_quat_normalize_to(q, dest);
}

CGLM_EXPORT
void
glmc_quat_normalize(versor q) {
  glm_quat_norm(q);
}

CGLM_EXPORT
float
glmc_quat_dot(const versor p, const versor q) {
  return glm_quat_dot(p, q);
}

CGLM_EXPORT
void
glmc_quat_conjugate(const versor q, versor dest) {
  glm_quat_conjugate(q, dest);
}

CGLM_EXPORT
void
glmc_quat_inv(const versor q, versor dest) {
  glm_quat_inv(q, dest);
}

CGLM_EXPORT
void
glmc_quat_add(const versor p, const versor q, versor dest) {
  glm_quat_add(p, q, dest);
}

CGLM_EXPORT
void
glmc_quat_sub(const versor p, const versor q, versor dest) {
  glm_quat_sub(p, q, dest);
}

CGLM_EXPORT
float
glmc_quat_real(const versor q) {
  return glm_quat_real(q);
}

CGLM_EXPORT
void
glmc_quat_imag(const versor q, vec3 dest) {
  glm_quat_imag(q, dest);
}

CGLM_EXPORT
void
glmc_quat_imagn(const versor q, vec3 dest) {
  glm_quat_imagn(q, dest);
}

CGLM_EXPORT
float
glmc_quat_imaglen(const versor q) {
  return glm_quat_imaglen(q);
}

CGLM_EXPORT
float
glmc_quat_angle(const versor q) {
  return glm_quat_angle(q);
}

CGLM_EXPORT
void
glmc_quat_axis(const versor q, versor dest) {
  glm_quat_axis(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mul(const versor p, const versor q, versor dest) {
  glm_quat_mul(p, q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat4(const versor q, mat4 dest) {
  glm_quat_mat4(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat4t(const versor q, mat4 dest) {
  glm_quat_mat4t(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat3(const versor q, mat3 dest) {
  glm_quat_mat3(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat3t(const versor q, mat3 dest) {
  glm_quat_mat3t(q, dest);
}

CGLM_EXPORT
void
glmc_quat_lerp(const versor from, const versor to, float t, versor dest) {
  glm_quat_lerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_slerp(const versor from, const versor to, float t, versor dest) {
  glm_quat_slerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_look(const vec3 eye, const versor ori, mat4 dest) {
  glm_quat_look(eye, ori, dest);
}

CGLM_EXPORT
void
glmc_quat_for(const vec3 dir, const vec3 fwd, const vec3 up, versor dest) {
  glm_quat_for(dir, fwd, up, dest);
}

CGLM_EXPORT
void
glmc_quat_forp(const vec3 from,
               const vec3 to,
               const vec3 fwd,
               const vec3 up,
               versor     dest) {
  glm_quat_forp(from, to, fwd, up, dest);
}

CGLM_EXPORT
void
glmc_quat_rotatev(const versor q, const vec3 v, vec3 dest) {
  glm_quat_rotatev(q, v, dest);
}

CGLM_EXPORT
void
glmc_quat_rotate(const mat4 m, const versor q, mat4 dest) {
  glm_quat_rotate(m, q, dest);
}

CGLM_EXPORT
void
glmc_quat_rotate_at(mat4 model, const versor q, const vec3 pivot) {
  glm_quat_rotate_at(model, q, pivot);
}

CGLM_EXPORT
void
glmc_quat_rotate_atm(mat4 m, const versor q, const vec3 pivot) {
  glm_quat_rotate_atm(m, q, pivot);
}
