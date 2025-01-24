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

#include "../cglm.h"

/* DEPRECATED! use _diag */
#define glmc_aabb2d_size(aabb) glmc_aabb2d_diag(aabb)

CGLM_EXPORT
void
glmc_aabb2d_zero(vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_copy(vec2 aabb[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_transform(vec2 aabb[2], mat3 m, vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_merge(vec2 aabb1[2], vec2 aabb2[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_crop(vec2 aabb[2], vec2 cropAabb[2], vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_crop_until(vec2 aabb[2],
                     vec2 cropAabb[2],
                     vec2 clampAabb[2],
                     vec2 dest[2]);

CGLM_EXPORT
void
glmc_aabb2d_invalidate(vec2 aabb[2]);

CGLM_EXPORT
bool
glmc_aabb2d_isvalid(vec2 aabb[2]);

CGLM_EXPORT
float
glmc_aabb2d_diag(vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_sizev(vec2 aabb[2], vec2 dest);

CGLM_EXPORT
float
glmc_aabb2d_radius(vec2 aabb[2]);

CGLM_EXPORT
void
glmc_aabb2d_center(vec2 aabb[2], vec2 dest);

CGLM_EXPORT
bool
glmc_aabb2d_aabb(vec2 aabb[2], vec2 other[2]);

CGLM_EXPORT
bool
glmc_aabb2d_point(vec2 aabb[2], vec2 point);

CGLM_EXPORT
bool
glmc_aabb2d_contains(vec2 aabb[2], vec2 other[2]);

CGLM_EXPORT
bool
glmc_aabb2d_circle(vec2 aabb[2], vec3 s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_aabb2d_h */
