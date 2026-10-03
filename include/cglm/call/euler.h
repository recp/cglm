/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_euler_h
#define cglmc_euler_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_euler_angles(CGLM_CONST mat4 m, vec3 dest);

CGLM_EXPORT
void
glmc_euler(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xyz(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_zyx(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_zxy(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xzy(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_yzx(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_yxz(const vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_by_order(const vec3 angles, glm_euler_seq axis, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xyz_quat(const vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_xzy_quat(const vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_yxz_quat(const vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_yzx_quat(const vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_zxy_quat(const vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_zyx_quat(const vec3 angles, versor dest);


#ifdef __cplusplus
}
#endif
#endif /* cglmc_euler_h */
