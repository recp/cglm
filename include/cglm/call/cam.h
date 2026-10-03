/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_cam_h
#define cglmc_cam_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_frustum(float left,   float right,
             float bottom, float top,
             float nearZ,  float farZ,
             mat4  dest);

CGLM_EXPORT
void
glmc_ortho(float left,   float right,
           float bottom, float top,
           float nearZ,  float farZ,
           mat4  dest);

CGLM_EXPORT
void
glmc_ortho_aabb(CGLM_CONST vec3 box[2], mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_p(CGLM_CONST vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_pz(CGLM_CONST vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default(float aspect, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default_s(float aspect, float size, mat4 dest);

CGLM_EXPORT
void
glmc_perspective(float fovy, float aspect, float nearZ, float farZ, mat4 dest);

CGLM_EXPORT
void
glmc_perspective_infinite(float fovy, float aspect, float nearZ, mat4 dest);

CGLM_EXPORT
void
glmc_persp_move_far(mat4 proj, float deltaFar);

CGLM_EXPORT
void
glmc_perspective_default(float aspect, mat4 dest);

CGLM_EXPORT
void
glmc_perspective_default_infinite(float aspect, mat4 dest);

CGLM_EXPORT
void
glmc_perspective_resize(float aspect, mat4 proj);

CGLM_EXPORT
void
glmc_lookat(const vec3 eye, const vec3 center, const vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look(const vec3 eye, const vec3 dir, const vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look_anyup(const vec3 eye, const vec3 dir, mat4 dest);

CGLM_EXPORT
void
glmc_persp_decomp(CGLM_CONST mat4 proj,
                  float * __restrict nearZ,
                  float * __restrict farZ,
                  float * __restrict top,
                  float * __restrict bottom,
                  float * __restrict left,
                  float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decompv(CGLM_CONST mat4 proj, float dest[6]);

CGLM_EXPORT
void
glmc_persp_decomp_x(CGLM_CONST mat4 proj,
                    float * __restrict left,
                    float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decomp_y(CGLM_CONST mat4 proj,
                    float * __restrict top,
                    float * __restrict bottom);

CGLM_EXPORT
void
glmc_persp_decomp_z(CGLM_CONST mat4 proj,
                    float * __restrict nearZ,
                    float * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_far(CGLM_CONST mat4 proj, float * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_near(CGLM_CONST mat4 proj, float * __restrict nearZ);

CGLM_EXPORT
float
glmc_persp_fovy(CGLM_CONST mat4 proj);

CGLM_EXPORT
float
glmc_persp_aspect(CGLM_CONST mat4 proj);

CGLM_EXPORT
void
glmc_persp_sizes(CGLM_CONST mat4 proj, float fovy, vec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_cam_h */
