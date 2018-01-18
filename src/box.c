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
glmc_aabb_transform(vec3 box[2], mat4 m, vec3 dest[2]) {
  glm_aabb_transform(box, m, dest);
}

CGLM_EXPORT
void
glmc_aabb_merge(vec3 box1[2], vec3 box2[2], vec3 dest[2]) {
  glm_aabb_merge(box1, box2, dest);
}

CGLM_EXPORT
void
glmc_aabb_crop(vec3 box[2], vec3 cropBox[2], vec3 dest[2]) {
  glm_aabb_crop(box, cropBox, dest);
}

CGLM_EXPORT
void
glmc_aabb_crop_until(vec3 box[2],
                     vec3 cropBox[2],
                     vec3 clampBox[2],
                     vec3 dest[2]) {
  glm_aabb_crop_until(box, cropBox, clampBox, dest);
}
