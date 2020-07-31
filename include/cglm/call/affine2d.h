/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_affine2d_h
#define cglmc_affine2d_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_translate2d_make(mat3 m, vec2 v);

CGLM_EXPORT
void
glmc_translate2d_to(mat3 m, vec2 v, mat3 dest);

CGLM_EXPORT
void
glmc_translate2d(mat3 m, vec2 v);

CGLM_EXPORT
void
glmc_translate2d_x(mat3 m, float to);

CGLM_EXPORT
void
glmc_translate2d_y(mat3 m, float to);

CGLM_EXPORT
void
glmc_scale2d_to(mat3 m, vec2 v, mat3 dest);

CGLM_EXPORT
void
glmc_scale2d_make(mat3 m, vec2 v);

CGLM_EXPORT
void
glmc_scale2d(mat3 m, vec2 v);

CGLM_EXPORT
void
glmc_scale2d_uni(mat3 m, float s);

CGLM_EXPORT
void
glmc_rotate2d_make(mat3 m, float angle);

CGLM_EXPORT
void
glmc_rotate2d(mat3 m, float angle);

CGLM_EXPORT
void
glmc_rotate2d_to(mat3 m, float angle, mat3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_affine2d_h */
