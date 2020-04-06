/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, ray_triangle) {
  /* Check whether a simple hit is recognized with the right distance */
  vec3  origin    = { 0.0f,  0.0f,  0.0f};
  vec3  direction = { 1.0f,  0.0f,  0.0f};
  vec3  opposite  = {-1.0f,  0.0f,  0.0f};
  vec3  v0        = { 5.0f, -1.0f,  1.0f};
  vec3  v1        = { 5.0f, -1.0f, -1.0f};
  vec3  v2        = { 5.0f,  1.0f,  0.0f};
  float d;
  bool  hit;

  hit = GLM(ray_triangle)(origin, direction, v0, v1, v2, &d);
  ASSERT(hit);
  ASSERT(fabsf(d - 5.0f) <= 0.0000009);

  /* Check whether a simple miss works */
  hit = GLM(ray_triangle)(origin, opposite, v0, v1, v2, &d);
  ASSERT(!hit);

  /* Check that we can disregard distance and pass NULL pointer instead */
  hit = GLM(ray_triangle)(origin, direction, v0, v1, v2, NULL);
  ASSERT(hit);

  TEST_SUCCESS
}
