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
TEST_DECLARE(glm_mat4_ucopy)
TEST_DECLARE(glm_mat4_copy)
TEST_DECLARE(glm_mat4_identity)
TEST_DECLARE(glm_mat4_identity_array)
TEST_DECLARE(glm_mat4_zero)
TEST_DECLARE(glm_mat4_pick3)
TEST_DECLARE(glm_mat4_pick3t)
TEST_DECLARE(glm_mat4_ins3)
TEST_DECLARE(glm_mat4_mul)
TEST_DECLARE(glm_mat4_mulN)
TEST_DECLARE(glm_mat4_mulv)
TEST_DECLARE(glm_mat4_mulv3)
TEST_DECLARE(glm_mat4_trace)
TEST_DECLARE(glm_mat4_trace3)
TEST_DECLARE(glm_mat4_quat)
TEST_DECLARE(glm_mat4_transpose_to)
TEST_DECLARE(glm_mat4_transpose)
TEST_DECLARE(glm_mat4_scale_p)
TEST_DECLARE(glm_mat4_scale)
TEST_DECLARE(glm_mat4_det)
TEST_DECLARE(glm_mat4_inv)
TEST_DECLARE(glm_mat4_inv_fast)
TEST_DECLARE(glm_mat4_inv_precise)
TEST_DECLARE(glm_mat4_swap_col)
TEST_DECLARE(glm_mat4_swap_row)
TEST_DECLARE(glm_mat4_rmc)


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
  TEST_ENTRY(glm_mat4_ucopy)
  TEST_ENTRY(glm_mat4_copy)
  TEST_ENTRY(glm_mat4_identity)
  TEST_ENTRY(glm_mat4_identity_array)
  TEST_ENTRY(glm_mat4_zero)
  TEST_ENTRY(glm_mat4_pick3)
  TEST_ENTRY(glm_mat4_pick3t)
  TEST_ENTRY(glm_mat4_ins3)
  TEST_ENTRY(glm_mat4_mul)
  TEST_ENTRY(glm_mat4_mulN)
  TEST_ENTRY(glm_mat4_mulv)
  TEST_ENTRY(glm_mat4_mulv3)
  TEST_ENTRY(glm_mat4_trace)
  TEST_ENTRY(glm_mat4_trace3)
  TEST_ENTRY(glm_mat4_quat)
  TEST_ENTRY(glm_mat4_transpose_to)
  TEST_ENTRY(glm_mat4_transpose)
  TEST_ENTRY(glm_mat4_scale_p)
  TEST_ENTRY(glm_mat4_scale)
  TEST_ENTRY(glm_mat4_det)
  TEST_ENTRY(glm_mat4_inv)
  TEST_ENTRY(glm_mat4_inv_fast)
  TEST_ENTRY(glm_mat4_inv_precise)
  TEST_ENTRY(glm_mat4_swap_col)
  TEST_ENTRY(glm_mat4_swap_row)
  TEST_ENTRY(glm_mat4_rmc)
  
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
