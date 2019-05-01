/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE vec3s glm_mat3_mulv(mat3 m, vec3s v);
   CGLM_INLINE float glm_mat3_rmc(vec3s r, mat3 m, vec3s c);
 */

#ifndef cglm_mat3s_h
#define cglm_mat3s_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3.h"
#include "vec3.h"

/*!
 * @brief multiply mat3 with vec3 (column vector) and store in dest vector
 *
 * @param[in]  m    mat3 (left)
 * @param[in]  v    vec3 (right, column vector)
 * returns          vec3 (result, column vector)
 */
CGLM_INLINE
vec3s
glms_mat3_mulv(mat3 m, vec3s v) {
  vec3s r;
  glm_mat3_mulv(m, v.raw, r.raw);
  return r;
}

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x3 (row vector),
 * then Matrix1x3 * Vec3 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x3
 * @param[in]  m   matrix3x3
 * @param[in]  c   column vector or matrix3x1
 *
 * @return scalar value e.g. Matrix1x1
 */
CGLM_INLINE
float
glms_mat3_rmc(vec3s r, mat3 m, vec3s c) {
  return glm_mat3_rmc(r.raw, m, c.raw);
}

#endif /* cglm_mat3s_h */
