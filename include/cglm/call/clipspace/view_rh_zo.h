/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_view_rh_zo_h
#define cglmc_view_rh_zo_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../../cglm.h"

CGLM_EXPORT
void
glmc_lookat_rh_zo(vec3 eye, vec3 center, vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look_rh_zo(vec3 eye, vec3 dir, vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look_anyup_rh_zo(vec3 eye, vec3 dir, mat4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_view_rh_zo_h */
