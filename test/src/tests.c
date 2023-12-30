/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/* test inline  */
/*---------------------------------------------------------------------------*/


#define GLM_PREFIX glm_
#define GLM(X) (glm_ ## X)

#include "test_vec2.h"
#include "test_vec3.h"
#include "test_vec4.h"
#include "test_ivec2.h"
#include "test_ivec3.h"
#include "test_ivec4.h"
#include "test_mat2.h"
#include "test_mat2x3.h"
#include "test_mat2x4.h"
#include "test_mat3.h"
#include "test_mat3x2.h"
#include "test_mat3x4.h"
#include "test_mat4.h"
#include "test_mat4x2.h"
#include "test_mat4x3.h"
#include "test_quat.h"
#include "test_project.h"
#include "test_plane.h"
#include "test_affine.h"
#include "test_affine2d.h"
#include "test_affine_mat.h"
#include "test_ray.h"
#include "test_cam.h"
#include "test_cam_lh_no.h"
#include "test_cam_lh_zo.h"
#include "test_cam_rh_no.h"
#include "test_cam_rh_zo.h"
#include "test_euler_to_quat_rh.h"
#include "test_euler_to_quat_lh.h"

#undef GLM
#undef GLM_PREFIX

/* test pre-compiled  */
/*---------------------------------------------------------------------------*/

#define GLM_PREFIX glmc_
#define GLM(X) (glmc_ ## X)

#include "test_vec2.h"
#include "test_vec3.h"
#include "test_vec4.h"
#include "test_ivec2.h"
#include "test_ivec3.h"
#include "test_ivec4.h"
#include "test_mat2.h"
#include "test_mat2x3.h"
#include "test_mat2x4.h"
#include "test_mat3.h"
#include "test_mat3x2.h"
#include "test_mat3x4.h"
#include "test_mat4.h"
#include "test_mat4x2.h"
#include "test_mat4x3.h"
#include "test_quat.h"
#include "test_project.h"
#include "test_plane.h"
#include "test_affine.h"
#include "test_affine2d.h"
#include "test_affine_mat.h"
#include "test_ray.h"
#include "test_cam.h"
#include "test_cam_lh_no.h"
#include "test_cam_lh_zo.h"
#include "test_cam_rh_no.h"
#include "test_cam_rh_zo.h"
#include "test_euler_to_quat_rh.h"
#include "test_euler_to_quat_lh.h"

#undef GLM
#undef GLM_PREFIX

/*---------------------------------------------------------------------------*/
