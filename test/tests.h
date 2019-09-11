/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef tests_h
#define tests_h

#include "include/common.h"

/*
 * To register a test:
 *   1. use TEST_DECLARE() to forward declare test
 *   2. use TEST_ENTRY() to add test to list
 */

/* mat4 */
TEST_DECLARE(mat4_identity)
TEST_DECLARE(mat4_mul)
TEST_DECLARE(mat4_all)

TEST_DECLARE(affine)

/* mat3 */
TEST_DECLARE(mat3_identity)
TEST_DECLARE(mat3_mul)
TEST_DECLARE(mat3_inv)

/* camera */
TEST_DECLARE(camera_lookat)
TEST_DECLARE(camera_decomp)

/* project */
TEST_DECLARE(project)

/* utils */
TEST_DECLARE(clamp)

/* euler */
TEST_DECLARE(euler)

/* quat */
TEST_DECLARE(quat)

/* bezier */
TEST_DECLARE(bezier)

/* vec3 */
TEST_DECLARE(vec3)

/* vec4 */
TEST_DECLARE(vec4)

/*****************************************************************************/

TEST_LIST {
  /* mat4 */
  TEST_ENTRY(mat4_identity)
  TEST_ENTRY(mat4_mul)
  TEST_ENTRY(mat4_all)
  
  TEST_ENTRY(affine)
  
  /* mat3 */
  TEST_ENTRY(mat3_identity)
  TEST_ENTRY(mat3_mul)
  TEST_ENTRY(mat3_inv)
  
  /* camera */
  TEST_ENTRY(camera_lookat)
  TEST_ENTRY(camera_decomp)
  
  /* project */
  TEST_ENTRY(project)
  
  /* utils */
  TEST_ENTRY(clamp)
  
  /* euler */
  TEST_ENTRY(euler)
  
  /* quat */
  TEST_ENTRY(quat)
  
  /* bezier */
  TEST_ENTRY(bezier)

  /* vec3 */
  TEST_ENTRY(vec3)

  /* vec4 */
  TEST_ENTRY(vec4)
};

#endif /* tests_h */
