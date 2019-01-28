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
glmc_bezier(float s, float p0, float c0, float c1, float p1);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_curve_h */
