/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT4X2_ZERO_INIT
   GLMS_MAT4X2_ZERO

 Functions:
   CGLM_INLINE mat4x2s glms_mat4x2_zero(void);
   CGLM_INLINE mat4x2s glms_mat4x2_make(float * __restrict src);
   CGLM_INLINE mat4s   glms_mat4x2_mul(mat4x2s m1, mat2x4s m2);
   CGLM_INLINE vec4s   glms_mat4x2_mulv(mat4x2s m, vec2s v);
   CGLM_INLINE mat2x4s glms_mat4x2_transpose(mat4x2s m);
   CGLM_INLINE mat4x2s glms_mat4x2_scale(mat4x2s m, float s);
 */

#ifndef cglms_mat4x2_h
#define cglms_mat4x2_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat4x2.h"

/* api definition */
#define glms_mat4x2_(NAME) CGLM_STRUCTAPI(mat4x2, NAME)

#define GLMS_MAT4X2_ZERO_INIT {GLM_MAT4X2_ZERO_INIT}

/* for C only */
#define GLMS_MAT4X2_ZERO ((mat4x2s)GLMS_MAT4X2_ZERO_INIT)


/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
mat4x2s
glms_mat4x2_(zero)(void) {
  mat4x2s r;
  glm_mat4x2_zero(r.raw);
  return r;
}

/*!
 * @brief Create mat4x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat4x2s
glms_mat4x2_(make)(float * __restrict src) {
  mat4x2s r;
  glm_mat4x2_make(src, r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * @code
 * r = glms_mat4x2_mul(mat4x2s, mat2x4s);
 * @endcode
 *
 * @param[in]  m1   left matrix (mat4x2s)
 * @param[in]  m2   right matrix (mat2x4s)
 * @returns destination matrix (mat4s)
 */
CGLM_INLINE
mat4s
glms_mat4x2_(mul)(mat4x2s m1, mat2x4s m2) {
  mat4s r;
  glm_mat4x2_mul(m1.raw, m2.raw, r.raw);
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
vec4s
glms_mat4x2_(mulv)(mat4x2s m, vec2s v) {
  vec4s r;
  glm_mat4x2_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief transpose matrix and store in dest
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
mat2x4s
glms_mat4x2_(transpose)(mat4x2s m) {
  mat2x4s r;
  glm_mat4x2_transpose(m.raw, r.raw);
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
mat4x2s
glms_mat4x2_(scale)(mat4x2s m, float s) {
  glm_mat4x2_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat4x2_h */
