/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ortho_rh_zo_h
#define cglmc_ortho_rh_zo_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../../cglm.h"

CGLM_EXPORT
void
glmc_ortho_rh_zo(float left,    float right,
                 float bottom,  float top,
                 float nearZ,   float farZ,
                 mat4  dest);

CGLM_EXPORT
void
glmc_ortho_aabb_rh_zo(vec3 box[2], mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_p_rh_zo(vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_pz_rh_zo(vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default_rh_zo(float aspect, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default_s_rh_zo(float aspect, float size, mat4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ortho_rh_zo_h */
