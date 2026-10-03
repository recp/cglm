/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_aabb2d_h
#define cglmc_aabb2d_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

/* DEPRECATED! use _diag */
#define glmc_aabb2d_size(aabb) glmc_aabb2d_diag(aabb)

CGLM_EXPORT
void
glmc_aabb2d_zero(vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_copy(CGLM_CONST vec2 aabb[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_transform(CGLM_CONST vec2 aabb[2], CGLM_CONST mat3 m, vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_merge(CGLM_CONST vec2 aabb1[2], CGLM_CONST vec2 aabb2[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_crop(CGLM_CONST vec2 aabb[2], CGLM_CONST vec2 cropAabb[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_crop_until(CGLM_CONST vec2 aabb[2],
                     CGLM_CONST vec2 cropAabb[2],
                     CGLM_CONST vec2 clampAabb[2],
                     vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_invalidate(vec2 aabb[2]);

CGLM_EXPORT
bool
glmc_aabb2d_isvalid(CGLM_CONST vec2 aabb[2]);

CGLM_EXPORT
float
glmc_aabb2d_diag(CGLM_CONST vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_sizev(CGLM_CONST vec2 aabb[2], vec2 dest);

CGLM_EXPORT
float
glmc_aabb2d_radius(CGLM_CONST vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_center(CGLM_CONST vec2 aabb[2], vec2 dest);

CGLM_EXPORT
bool
glmc_aabb2d_aabb(CGLM_CONST vec2 aabb[2], CGLM_CONST vec2 other[2]);

CGLM_EXPORT
bool
glmc_aabb2d_point(CGLM_CONST vec2 aabb[2], const vec2 point);

CGLM_EXPORT
bool
glmc_aabb2d_contains(CGLM_CONST vec2 aabb[2], CGLM_CONST vec2 other[2]);

CGLM_EXPORT
bool
glmc_aabb2d_circle(CGLM_CONST vec2 aabb[2], const vec3 s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_aabb2d_h */
