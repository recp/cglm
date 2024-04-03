/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT4X3_ZERO_INIT
   GLMS_MAT4X3_ZERO

 Functions:
   CGLM_INLINE mat4x3s glms_mat4x3_zero(void);
   CGLM_INLINE mat4x3s glms_mat4x3_make(const float * __restrict src);
   CGLM_INLINE mat3s   glms_mat4x3_mul(mat4x3s m1, mat3x4s m2);
   CGLM_INLINE vec3s   glms_mat4x3_mulv(mat4x3s m, vec4s v);
   CGLM_INLINE mat3x4s glms_mat4x3_transpose(mat4x3s m);
   CGLM_INLINE mat4x3s glms_mat4x3_scale(mat4x3s m, float s);
 */

#ifndef cglms_mat4x3_h
#define cglms_mat4x3_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat4x3.h"

/* api definition */
#define glms_mat4x3_(NAME) CGLM_STRUCTAPI(mat4x3, NAME)

#define GLMS_MAT4X3_ZERO_INIT {GLM_MAT4X3_ZERO_INIT}

/* for C only */
#define GLMS_MAT4X3_ZERO ((mat4x3s)GLMS_MAT4X3_ZERO_INIT)

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(zero)(void) {
  mat4x3s r;
  glm_mat4x3_zero(r.raw);
  return r;
}

/*!
 * @brief Create mat4x3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(make)(const float * __restrict src) {
  mat4x3s r;
  glm_mat4x3_make(src, r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * @code
 * r = glms_mat4x3_mul(mat4x3s, mat3x4s);
 * @endcode
 *
 * @param[in]  m1   left matrix (mat4x3s)
 * @param[in]  m2   right matrix (mat3x4s)
 * @returns destination matrix (mat3s)
 */
CGLM_INLINE
mat3s
glms_mat4x3_(mul)(mat4x3s m1, mat3x4s m2) {
  mat3s r;
  glm_mat4x3_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*!
 * @brief multiply matrix with column vector and store in dest vector
 *
 * @param[in]  m    matrix (left)
 * @param[in]  v    vector (right, column vector)
 * @returns destination vector (vec3s)
 */
CGLM_INLINE
vec3s
glms_mat4x3_(mulv)(mat4x3s m, vec4s v) {
  vec3s r;
  glm_mat4x3_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief transpose matrix and store in dest
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
mat3x4s
glms_mat4x3_(transpose)(mat4x3s m) {
  mat3x4s r;
  glm_mat4x3_transpose(m.raw, r.raw);
  return r;
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in, out] m matrix
 * @param[in]    s scalar
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(scale)(mat4x3s m, float s) {
  glm_mat4x3_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat4x3_h */
