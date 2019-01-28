/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
float
glmc_bezier(float s, float p0, float c0, float c1, float p1) {
  return glm_bezier(s, p0, c0, c1, p1);
}

CGLM_EXPORT
float
glmc_decasteljau(float prm, float p0, float c0, float c1, float p1) {
  return glm_decasteljau(prm, p0, c0, c1, p1);
}

CGLM_EXPORT
float
glmc_bezier_solve(float prm, float p0, float c0, float c1, float p1) {
  return glm_bezier_solve(prm, p0, c0, c1, p1);
}
