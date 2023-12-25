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

#include "../cglm.h"

CGLM_EXPORT
void
glmc_euler_angles(mat4 m, vec3 dest);

CGLM_EXPORT
void
glmc_euler(vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xyz(vec3 angles,  mat4 dest);

CGLM_EXPORT
void
glmc_euler_zyx(vec3 angles,  mat4 dest);

CGLM_EXPORT
void
glmc_euler_zxy(vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xzy(vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_yzx(vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_yxz(vec3 angles, mat4 dest);

CGLM_EXPORT
void
glmc_euler_by_order(vec3 angles, glm_euler_seq axis, mat4 dest);

CGLM_EXPORT
void
glmc_euler_xyz_quat(vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_xzy_quat(vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_yxz_quat(vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_yzx_quat(vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_zxy_quat(vec3 angles, versor dest);

CGLM_EXPORT
void
glmc_euler_zyx_quat(vec3 angles, versor dest);


#ifdef __cplusplus
}
#endif
#endif /* cglmc_euler_h */
