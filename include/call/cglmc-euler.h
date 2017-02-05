/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef glmc_euler_h
#define glmc_euler_h
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
glmc_euler_by_order(vec3 angles, glm_euler_sq axis, mat4 dest);

#ifdef __cplusplus
}
#endif
#endif /* glmc_euler_h */
