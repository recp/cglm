/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_persp_rh_no_h
#define cglmc_persp_rh_no_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../../cglm.h"

CGLM_EXPORT
void
glmc_frustum_rh_no(float left,    float right,
                   float bottom,  float top,
                   float nearZ,   float farZ,
                   mat4  dest);

CGLM_EXPORT
void
glmc_perspective_rh_no(float fovy,
                       float aspect,
                       float nearVal,
                       float farVal,
                       mat4 dest);

CGLM_EXPORT
void
glmc_persp_move_far_rh_no(mat4 proj, float deltaFar);

CGLM_EXPORT
void
glmc_persp_decomp_rh_no(mat4 proj,
                        float * __restrict nearZ, float * __restrict farZ,
                        float * __restrict top,   float * __restrict bottom,
                        float * __restrict left,  float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decompv_rh_no(mat4 proj, float dest[6]);

CGLM_EXPORT
void
glmc_persp_decomp_x_rh_no(mat4 proj,
                          float * __restrict left,
                          float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decomp_y_rh_no(mat4 proj,
                          float * __restrict top,
                          float * __restrict bottom);

CGLM_EXPORT
void
glmc_persp_decomp_z_rh_no(mat4 proj,
                          float * __restrict nearZ,
                          float * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_far_rh_no(mat4 proj, float * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_near_rh_no(mat4 proj, float * __restrict nearZ);

CGLM_EXPORT
void
glmc_persp_sizes_rh_no(mat4 proj, float fovy, vec4 dest);

CGLM_EXPORT
float
glmc_persp_fovy_rh_no(mat4 proj);

CGLM_EXPORT
float
glmc_persp_aspect_rh_no(mat4 proj);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_persp_rh_no_h */
