/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ease_h
#define cglmc_ease_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
float
glmc_ease_linear(float t);

CGLM_EXPORT
float
glmc_ease_sine_in(float t);

CGLM_EXPORT
float
glmc_ease_sine_out(float t);

CGLM_EXPORT
float
glmc_ease_sine_inout(float t);

CGLM_EXPORT
float
glmc_ease_quad_in(float t);

CGLM_EXPORT
float
glmc_ease_quad_out(float t);

CGLM_EXPORT
float
glmc_ease_quad_inout(float t);

CGLM_EXPORT
float
glmc_ease_cubic_in(float t);

CGLM_EXPORT
float
glmc_ease_cubic_out(float t);

CGLM_EXPORT
float
glmc_ease_cubic_inout(float t);

CGLM_EXPORT
float
glmc_ease_quart_in(float t);

CGLM_EXPORT
float
glmc_ease_quart_out(float t);

CGLM_EXPORT
float
glmc_ease_quart_inout(float t);

CGLM_EXPORT
float
glmc_ease_quint_in(float t);

CGLM_EXPORT
float
glmc_ease_quint_out(float t);

CGLM_EXPORT
float
glmc_ease_quint_inout(float t);

CGLM_EXPORT
float
glmc_ease_exp_in(float t);

CGLM_EXPORT
float
glmc_ease_exp_out(float t);

CGLM_EXPORT
float
glmc_ease_exp_inout(float t);

CGLM_EXPORT
float
glmc_ease_circ_in(float t);

CGLM_EXPORT
float
glmc_ease_circ_out(float t);

CGLM_EXPORT
float
glmc_ease_circ_inout(float t);

CGLM_EXPORT
float
glmc_ease_back_in(float t);

CGLM_EXPORT
float
glmc_ease_back_out(float t);

CGLM_EXPORT
float
glmc_ease_back_inout(float t);

CGLM_EXPORT
float
glmc_ease_elast_in(float t);

CGLM_EXPORT
float
glmc_ease_elast_out(float t);

CGLM_EXPORT
float
glmc_ease_elast_inout(float t);

CGLM_EXPORT
float
glmc_ease_bounce_out(float t);

CGLM_EXPORT
float
glmc_ease_bounce_in(float t);

CGLM_EXPORT
float
glmc_ease_bounce_inout(float t);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ease_h */
