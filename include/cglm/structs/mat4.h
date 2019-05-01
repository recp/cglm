/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * Most of functions in this header are optimized manually with SIMD
 * if available. You dont need to call/incude SIMD headers manually
 */

/*
 Functions:
   CGLM_INLINE void  glm_mat4_mulv(mat4 m, vec4 v, vec4 dest);
   CGLM_INLINE void  glm_mat4_mulv3(mat4 m, vec3 v, vec3 dest);
   CGLM_INLINE float glm_mat4_rmc(vec4 r, mat4 m, vec4 c);
 */

#ifndef cglm_mats_h
#define cglm_mats_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat4.h"
#include "vec4.h"
#include "vec3.h"

/*!
 * @brief multiply mat4 with vec4 (column vector) and store in dest vector
 *
 * @param[in]  m    mat4 (left)
 * @param[in]  v    vec4 (right, column vector)
 * returns          vec4 (result, column vector)
 */
CGLM_INLINE
vec4s
glms_mat4_mulv(mat4 m, vec4s v) {
  vec4s r;
  glm_mat4_mulv(m, v.raw, r.raw);
  return r;
}

/*!
 * @brief multiply vector with mat4
 *
 * @param[in]  m    mat4(affine transform)
 * @param[in]  v    vec3
 * @param[in]  last 4th item to make it vec4
 * returns          result vector (vec3)
 */
CGLM_INLINE
vec3s
glms_mat4_mulv3(mat4 m, vec3s v, float last) {
  vec3s r;
  glm_mat4_mulv3(m, v.raw, last, r.raw);
  return r;
}

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x4 (row vector),
 * then Matrix1x4 * Vec4 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x4
 * @param[in]  m   matrix4x4
 * @param[in]  c   column vector or matrix4x1
 *
 * @return scalar value e.g. B(s)
 */
CGLM_INLINE
float
glms_mat4_rmc(vec4s r, mat4 m, vec4s c) {
  return glm_mat4_rmc(r.raw, m, c.raw);
}

#endif /* cglm_mats_h */
