/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_quat_h
#define cglmc_quat_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_quat_identity(versor q);

CGLM_EXPORT
void
glmc_quat_identity_array(versor * const __restrict q, size_t count);

CGLM_EXPORT
void
glmc_quat_init(versor q, float x, float y, float z, float w);

CGLM_EXPORT
void
glmc_quat(versor q, float angle, float x, float y, float z);

CGLM_EXPORT
void
glmc_quatv(versor q, float angle, const vec3 axis);

CGLM_EXPORT
void
glmc_quat_copy(const versor q, versor dest);

CGLM_EXPORT
float
glmc_quat_norm(const versor q);

CGLM_EXPORT
void
glmc_quat_normalize_to(const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_normalize(versor q);

CGLM_EXPORT
float
glmc_quat_dot(const versor p, const versor q);

CGLM_EXPORT
void
glmc_quat_conjugate(const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_inv(const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_add(const versor p, const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_sub(const versor p, const versor q, versor dest);

CGLM_EXPORT
float
glmc_quat_real(const versor q);

CGLM_EXPORT
void
glmc_quat_imag(const versor q, vec3 dest);

CGLM_EXPORT
void
glmc_quat_imagn(const versor q, vec3 dest);

CGLM_EXPORT
float
glmc_quat_imaglen(const versor q);

CGLM_EXPORT
float
glmc_quat_angle(const versor q);

CGLM_EXPORT
void
glmc_quat_axis(const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_mul(const versor p, const versor q, versor dest);

CGLM_EXPORT
void
glmc_quat_mat4(const versor q, mat4 dest);

CGLM_EXPORT
void
glmc_quat_mat4t(const versor q, mat4 dest);

CGLM_EXPORT
void
glmc_quat_mat3(const versor q, mat3 dest);

CGLM_EXPORT
void
glmc_quat_mat3t(const versor q, mat3 dest);

CGLM_EXPORT
void
glmc_quat_lerp(const versor from, const versor to, float t, versor dest);

CGLM_EXPORT
void
glmc_quat_slerp(const versor q, const versor r, float t, versor dest);

CGLM_EXPORT
void
glmc_quat_look(const vec3 eye, const versor ori, mat4 dest);

CGLM_EXPORT
void
glmc_quat_for(const vec3 dir, const vec3 fwd, const vec3 up, versor dest);

CGLM_EXPORT
void
glmc_quat_forp(const vec3 from,
               const vec3 to,
               const vec3 fwd,
               const vec3 up,
               versor     dest);

CGLM_EXPORT
void
glmc_quat_rotatev(const versor from, const vec3 to, vec3 dest);

CGLM_EXPORT
void
glmc_quat_rotate(const mat4 m, const versor q, mat4 dest);

CGLM_EXPORT
void
glmc_quat_rotate_at(mat4 model, const versor q, const vec3 pivot);

CGLM_EXPORT
void
glmc_quat_rotate_atm(mat4 m, const versor q, const vec3 pivot);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_quat_h */
