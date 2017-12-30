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
glmc_plane_normalize(vec4 plane) {
  glm_plane_normalize(plane);
}

CGLM_EXPORT
void
glmc_plane_extract(mat4 projView, vec4 dest[6]) {
  glm_plane_extract(projView, dest);
}
