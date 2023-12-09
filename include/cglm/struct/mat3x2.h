/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT3X2_ZERO_INIT
   GLMS_MAT3X2_ZERO

 Functions:
   CGLM_INLINE mat3x2s glms_mat3x2_zero(void);
   CGLM_INLINE mat3x2s glms_mat3x2_make(float * __restrict src);
   CGLM_INLINE mat3s   glms_mat3x2_mul(mat3x2s m1, mat2x3s m2);
   CGLM_INLINE vec3s   glms_mat3x2_mulv(mat3x2s m, vec2s v);
   CGLM_INLINE mat2x3s glms_mat3x2_transpose(mat3x2s m);
   CGLM_INLINE mat3x2s glms_mat3x2_scale(mat3x2s m, float s);
 */

#ifndef cglms_mat3x2_h
#define cglms_mat3x2_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3x2.h"

/* api definition */
#define glms_mat3x2_(NAME) CGLM_STRUCTAPI(mat3x2, NAME)

#define GLMS_MAT3X2_ZERO_INIT {GLM_MAT3X2_ZERO_INIT}

/* for C only */
#define GLMS_MAT3X2_ZERO ((mat3x2s)GLMS_MAT3X2_ZERO_INIT)

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(zero)(void) {
  mat3x2s r;
  glm_mat3x2_zero(r.raw);
  return r;
}

/*!
 * @brief Create mat3x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(make)(float * __restrict src) {
  mat3x2s r;
  glm_mat3x2_make(src, r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * @code
 * r = glms_mat3x2_mul(mat3x2s, mat2x3s);
 * @endcode
 *
 * @param[in]  m1   left matrix (mat3x2s)
 * @param[in]  m2   right matrix (mat2x3s)
 * @returns destination matrix (mat3s)
 */
CGLM_INLINE
mat3s
glms_mat3x2_(mul)(mat3x2s m1, mat2x3s m2) {
  mat3s r;
  glm_mat3x2_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*!
 * @brief multiply matrix with column vector and store in dest vector
 *
 * @param[in]  m    matrix (left)
 * @param[in]  v    vector (right, column vector)
 * @param[out] dest result vector
 */
CGLM_INLINE
vec3s
glms_mat3x2_(mulv)(mat3x2s m, vec2s v) {
  vec3s r;
  glm_mat3x2_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief transpose matrix and store in dest
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
mat2x3s
glms_mat3x2_(transpose)(mat3x2s m) {
  mat2x3s r;
  glm_mat3x2_transpose(m.raw, r.raw);
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
mat3x2s
glms_mat3x2_(scale)(mat3x2s m, float s) {
  glm_mat3x2_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat3x2_h */
