/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
void
glmc_frustum_planes(mat4 m, vec4 dest[6]) {
  glm_frustum_planes(m, dest);
}

CGLM_EXPORT
void
glmc_frustum_corners(mat4 invMat, vec4 dest[8]) {
  glm_frustum_corners(invMat, dest);
}

CGLM_EXPORT
void
glmc_frustum_center(vec4 corners[8], vec4 dest) {
  glm_frustum_center(corners, dest);
}

CGLM_EXPORT
void
glmc_frustum_box(vec4 corners[8], mat4 m, vec3 box[2]) {
  glm_frustum_box(corners, m, box);
}

CGLM_EXPORT
void
glmc_frustum_corners_at(vec4  corners[8],
                        float splitDist,
                        float farDist,
                        vec4  planeCorners[4]) {
  glm_frustum_corners_at(corners, splitDist, farDist, planeCorners);
}
