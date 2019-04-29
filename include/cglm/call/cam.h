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

#include "../cglm.h"

CGLM_EXPORT
void
glmc_frustum(float left,
             float right,
             float bottom,
             float top,
             float nearVal,
             float farVal,
             mat4  dest);

CGLM_EXPORT
void
glmc_ortho(float left,
           float right,
           float bottom,
           float top,
           float nearVal,
           float farVal,
           mat4  dest);

CGLM_EXPORT
void
glmc_ortho_aabb(const vec3 box[2], mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_p(const vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_aabb_pz(const vec3 box[2], float padding, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default(float aspect, mat4 dest);

CGLM_EXPORT
void
glmc_ortho_default_s(float aspect, float size, mat4 dest);

CGLM_EXPORT
void
glmc_perspective(float fovy,
                 float aspect,
                 float nearVal,
                 float farVal,
                 mat4  dest);

CGLM_EXPORT
void
glmc_persp_move_far(mat4 proj, float deltaFar);

CGLM_EXPORT
void
glmc_perspective_default(float aspect, mat4 dest);

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
glmc_persp_decomp(const mat4 proj,
                  float * __restrict nearVal,
                  float * __restrict farVal,
                  float * __restrict top,
                  float * __restrict bottom,
                  float * __restrict left,
                  float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decompv(const mat4 proj, float dest[6]);

CGLM_EXPORT
void
glmc_persp_decomp_x(const mat4 proj,
                    float * __restrict left,
                    float * __restrict right);

CGLM_EXPORT
void
glmc_persp_decomp_y(const mat4 proj,
                    float * __restrict top,
                    float * __restrict bottom);

CGLM_EXPORT
void
glmc_persp_decomp_z(const mat4 proj,
                    float * __restrict nearVal,
                    float * __restrict farVal);

CGLM_EXPORT
void
glmc_persp_decomp_far(const mat4 proj, float * __restrict farVal);

CGLM_EXPORT
void
glmc_persp_decomp_near(const mat4 proj, float * __restrict nearVal);

CGLM_EXPORT
float
glmc_persp_fovy(const mat4 proj);

CGLM_EXPORT
float
glmc_persp_aspect(const mat4 proj);

CGLM_EXPORT
void
glmc_persp_sizes(const mat4 proj, float fovy, vec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_cam_h */
