/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../../include/cglm/clipspace/persp_lh_no.h"
#include "../../include/cglm/call/clipspace/persp_lh_no.h"

CGLM_EXPORT
void
glmc_frustum_lh_no(float left,    float right,
                   float bottom,  float top,
                   float nearZ, float farZ,
                   mat4  dest) {
  glm_frustum_lh_no(left, right,
                    bottom, top,
                    nearZ, farZ,
                    dest);
}

CGLM_EXPORT
void
glmc_perspective_lh_no(float fovy,
                       float aspect,
                       float nearVal,
                       float farVal,
                       mat4 dest) {
  glm_perspective_lh_no(fovy,
                        aspect,
                        nearVal,
                        farVal,
                        dest);
}

CGLM_EXPORT
void
glmc_persp_move_far_lh_no(mat4 proj, float deltaFar) {
  glm_persp_move_far_lh_no(proj, deltaFar);
}

CGLM_EXPORT
void
glmc_persp_decomp_lh_no(mat4 proj,
                        float * __restrict nearZ, float * __restrict farZ,
                        float * __restrict top,   float * __restrict bottom,
                        float * __restrict left,  float * __restrict right) {
  glm_persp_decomp_lh_no(proj, nearZ, farZ, top, bottom, left, right);
}

CGLM_EXPORT
void
glmc_persp_decompv_lh_no(mat4 proj, float dest[6]) {
  glm_persp_decompv_lh_no(proj, dest);
}

CGLM_EXPORT
void
glmc_persp_decomp_x_lh_no(mat4 proj,
                          float * __restrict left,
                          float * __restrict right) {
  glm_persp_decomp_x_lh_no(proj, left, right);
}

CGLM_EXPORT
void
glmc_persp_decomp_y_lh_no(mat4 proj,
                          float * __restrict top,
                          float * __restrict bottom) {
  glm_persp_decomp_y_lh_no(proj, top, bottom);
}

CGLM_EXPORT
void
glmc_persp_decomp_z_lh_no(mat4 proj,
                          float * __restrict nearZ,
                          float * __restrict farZ) {
  glm_persp_decomp_z_lh_no(proj, nearZ, farZ);
}

CGLM_EXPORT
void
glmc_persp_decomp_far_lh_no(mat4 proj, float * __restrict farZ) {
  glm_persp_decomp_far_lh_no(proj, farZ);
}

CGLM_EXPORT
void
glmc_persp_decomp_near_lh_no(mat4 proj, float * __restrict nearZ) {
  glm_persp_decomp_near_lh_no(proj, nearZ);
}

CGLM_EXPORT
void
glmc_persp_sizes_lh_no(mat4 proj, float fovy, vec4 dest) {
  glm_persp_sizes_lh_no(proj, fovy, dest);
}

CGLM_EXPORT
float
glmc_persp_fovy_lh_no(mat4 proj) {
  return glm_persp_fovy_lh_no(proj);
}

CGLM_EXPORT
float
glmc_persp_aspect_lh_no(mat4 proj) {
  return glm_persp_aspect_lh_no(proj);
}
