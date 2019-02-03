/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_bezier_h
#define cglmc_bezier_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
float
glmc_bezier(float s, float p0, float c0, float c1, float p1);

CGLM_EXPORT
float
glmc_hermite(float s, float p0, float t0, float t1, float p1);

CGLM_EXPORT
float
glmc_decasteljau(float prm, float p0, float c0, float c1, float p1);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_bezier_h */
