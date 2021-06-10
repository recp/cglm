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
glmc_quat_identity_array(versor * __restrict q, size_t count) {
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
glmc_quatv(versor q, float angle, vec3 axis) {
  glm_quatv(q, angle, axis);
}

CGLM_EXPORT
void
glmc_quat_copy(versor q, versor dest) {
  glm_quat_copy(q, dest);
}

CGLM_EXPORT
void
glmc_quat_from_vecs(vec3 a, vec3 b, versor dest) {
  glm_quat_from_vecs(a, b, dest);
}

CGLM_EXPORT
float
glmc_quat_norm(versor q) {
  return glm_quat_norm(q);
}

CGLM_EXPORT
void
glmc_quat_normalize_to(versor q, versor dest) {
  glm_quat_normalize_to(q, dest);
}

CGLM_EXPORT
void
glmc_quat_normalize(versor q) {
  glm_quat_normalize(q);
}

CGLM_EXPORT
float
glmc_quat_dot(versor p, versor q) {
  return glm_quat_dot(p, q);
}

CGLM_EXPORT
void
glmc_quat_conjugate(versor q, versor dest) {
  glm_quat_conjugate(q, dest);
}

CGLM_EXPORT
void
glmc_quat_inv(versor q, versor dest) {
  glm_quat_inv(q, dest);
}

CGLM_EXPORT
void
glmc_quat_add(versor p, versor q, versor dest) {
  glm_quat_add(p, q, dest);
}

CGLM_EXPORT
void
glmc_quat_sub(versor p, versor q, versor dest) {
  glm_quat_sub(p, q, dest);
}

CGLM_EXPORT
float
glmc_quat_real(versor q) {
  return glm_quat_real(q);
}

CGLM_EXPORT
void
glmc_quat_imag(versor q, vec3 dest) {
  glm_quat_imag(q, dest);
}

CGLM_EXPORT
void
glmc_quat_imagn(versor q, vec3 dest) {
  glm_quat_imagn(q, dest);
}

CGLM_EXPORT
float
glmc_quat_imaglen(versor q) {
  return glm_quat_imaglen(q);
}

CGLM_EXPORT
float
glmc_quat_angle(versor q) {
  return glm_quat_angle(q);
}

CGLM_EXPORT
void
glmc_quat_axis(versor q, vec3 dest) {
  glm_quat_axis(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mul(versor p, versor q, versor dest) {
  glm_quat_mul(p, q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat4(versor q, mat4 dest) {
  glm_quat_mat4(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat4t(versor q, mat4 dest) {
  glm_quat_mat4t(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat3(versor q, mat3 dest) {
  glm_quat_mat3(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat3t(versor q, mat3 dest) {
  glm_quat_mat3t(q, dest);
}

CGLM_EXPORT
void
glmc_quat_lerp(versor from, versor to, float t, versor dest) {
  glm_quat_lerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_lerpc(versor from, versor to, float t, versor dest) {
  glm_quat_lerpc(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_nlerp(versor from, versor to, float t, versor dest) {
  glm_quat_nlerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_slerp(versor from, versor to, float t, versor dest) {
  glm_quat_slerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_quat_look(vec3 eye, versor ori, mat4 dest) {
  glm_quat_look(eye, ori, dest);
}

CGLM_EXPORT
void
glmc_quat_for(vec3 dir, vec3 up, versor dest) {
  glm_quat_for(dir, up, dest);
}

CGLM_EXPORT
void
glmc_quat_forp(vec3 from, vec3 to, vec3 up, versor dest) {
  glm_quat_forp(from, to, up, dest);
}

CGLM_EXPORT
void
glmc_quat_rotatev(versor q, vec3 v, vec3 dest) {
  glm_quat_rotatev(q, v, dest);
}

CGLM_EXPORT
void
glmc_quat_rotate(mat4 m, versor q, mat4 dest) {
  glm_quat_rotate(m, q, dest);
}

CGLM_EXPORT
void
glmc_quat_rotate_at(mat4 model, versor q, vec3 pivot) {
  glm_quat_rotate_at(model, q, pivot);
}

CGLM_EXPORT
void
glmc_quat_rotate_atm(mat4 m, versor q, vec3 pivot) {
  glm_quat_rotate_atm(m, q, pivot);
}
