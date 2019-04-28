/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_curve_h
#define cglmc_curve_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
float
glmc_smc(float s, const mat4 m, const vec4 c);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_curve_h */
