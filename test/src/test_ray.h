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

TEST_IMPL(GLM_PREFIX, ray_sphere) {
  vec4  sphere = {5.0f, 0.0f, 0.0f, 1.0f}; /* Sphere: center at (5, 0, 0) with radius 1 */
  float t1, t2;
  bool  hit;

  /* Case 1: Ray misses the sphere */
  hit = GLM(ray_sphere)((vec3){10.0f, 3.0f, 0.0f}, (vec3){1.0f, 0.0f, 0.0f}, sphere, &t1, &t2);
  ASSERT(!hit); /* Expect no intersection */

  /* Case 2: Ray starts inside the sphere */
  hit = GLM(ray_sphere)((vec3){5.0f, 0.5f, 0.0f}, (vec3){1.0f, 0.0f, 0.0f}, sphere, &t1, &t2);
  ASSERT(hit); /* Expect an intersection */
  ASSERT(t1 < 0 && t2 > 0); /* Ray exits at t2 */

  /* Case 3: Ray intersects the sphere from outside */
  hit = GLM(ray_sphere)((vec3){0.0f, 0.0f, 0.0f}, (vec3){1.0f, 0.0f, 0.0f}, sphere, &t1, &t2);
  ASSERT(hit); /* Expect an intersection */
  ASSERT(t1 > 0 && t2 > 0); /* Intersections at t1 and t2 */

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ray_at) {
  vec3 origin    = {0.0f, 0.0f, 0.0f};
  vec3 direction = {1.0f, 1.0f, 1.0f};  /* Diagonal direction */
  float distance = sqrtf(3.0f);         /* Distance along the ray; sqrt(3) for unit length due to direction normalization */
  vec3 result;

  /* Normalize the direction to ensure accurate distance measurement */
  glm_vec3_normalize(direction);

  GLM(ray_at)(origin, direction, distance, result);
  ASSERT(fabsf(result[0] - 1.0f) <= 0.0000009);  /* Expecting to be 1 unit along the x-axis */
  ASSERT(fabsf(result[1] - 1.0f) <= 0.0000009);  /* Expecting to be 1 unit along the y-axis */
  ASSERT(fabsf(result[2] - 1.0f) <= 0.0000009);  /* Expecting to be 1 unit along the z-axis */

  TEST_SUCCESS
}
