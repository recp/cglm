/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT2X3_ZERO_INIT
   GLMS_MAT2X3_ZERO

 Functions:
   CGLM_INLINE mat2x3s glms_mat2x3_zero(void);
   CGLM_INLINE mat2x3s glms_mat2x3_make(float * __restrict src);
   CGLM_INLINE mat2s   glms_mat2x3_mul(mat2x3s m1, mat3x2s m2);
   CGLM_INLINE vec2s   glms_mat2x3_mulv(mat2x3s m, vec3s v);
   CGLM_INLINE mat3x2s glms_mat2x3_transpose(mat2x3s m);
   CGLM_INLINE mat2x3s glms_mat2x3_scale(mat2x3s m, float s);
 */

#ifndef cglms_mat2x3_h
#define cglms_mat2x3_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat2x3.h"

/* api definition */
#define glms_mat2x3_(NAME) CGLM_STRUCTAPI(mat2x3, NAME)

#define GLMS_MAT2X3_ZERO_INIT {GLM_MAT2X3_ZERO_INIT}

/* for C only */
#define GLMS_MAT2X3_ZERO ((mat2x3s)GLMS_MAT2X3_ZERO_INIT)

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(zero)(void) {
  mat2x3s r;
  glm_mat2x3_zero(r.raw);
  return r;
}

/*!
 * @brief Create mat2x3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(make)(float * __restrict src) {
  mat2x3s r;
  glm_mat2x3_make(src, r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * @code
 * r = glms_mat2x3_mul(mat2x3s, mat3x2s);
 * @endcode
 *
 * @param[in]  m1   left matrix (mat2x3s)
 * @param[in]  m2   right matrix (mat3x2s)
 * @returns destination matrix (mat2s)
 */
CGLM_INLINE
mat2s
glms_mat2x3_(mul)(mat2x3s m1, mat3x2s m2) {
  mat2s r;
  glm_mat2x3_mul(m1.raw, m2.raw, r.raw);
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
vec2s
glms_mat2x3_(mulv)(mat2x3s m, vec3s v) {
  vec2s r;
  glm_mat2x3_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief transpose matrix and store in dest
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
mat3x2s
glms_mat2x3_(transpose)(mat2x3s m) {
  mat3x2s r;
  glm_mat2x3_transpose(m.raw, r.raw);
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
mat2x3s
glms_mat2x3_(scale)(mat2x3s m, float s) {
  glm_mat2x3_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat2x3_h */
