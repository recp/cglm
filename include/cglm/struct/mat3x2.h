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
   CGLM_INLINE mat3x2s glms_mat3x2_make(const float * __restrict src);
   CGLM_INLINE mat2s   glms_mat3x2_mul(mat3x2s m1, mat2x3s m2);
   CGLM_INLINE vec2s   glms_mat3x2_mulv(mat3x2s m, vec3s v);
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
 * @brief Zero out the mat3x2s (dest).
 *
 * @return[out] dest constructed mat3x2s from raw pointer
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(zero)(void) {
  mat3x2s dest;
  glm_mat3x2_zero(dest.raw);
  return dest;
}

/*!
 * @brief Create mat3x2s (dest) from pointer (src).
 *
 * @param[in]   src  pointer to an array of floats
 * @return[out] dest constructed mat3x2s from raw pointer
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(make)(const float * __restrict src) {
  mat3x2s dest;
  glm_mat3x2_make(src, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x2s (m1) by mat2x3s (m2) and store in mat2s (dest).
 *
 * @code
 * r = glms_mat3x2_mul(mat3x2s, mat2x3s);
 * @endcode
 *
 * @param[in]   m1   mat3x2s (left)
 * @param[in]   m2   mat2x3s (right)
 * @return[out] dest constructed mat2s from raw pointers
 */
CGLM_INLINE
mat2s
glms_mat3x2_(mul)(mat3x2s m1, mat2x3s m2) {
  mat2s dest;
  glm_mat3x2_mul(m1.raw, m2.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x2s (m) by vec3s (v) and store in vec2s (dest).
 *
 * @param[in]   m    mat3x2s (left)
 * @param[in]   v    vec3s (right, column vector)
 * @return[out] dest constructed vec2s from raw pointers
 */
CGLM_INLINE
vec2s
glms_mat3x2_(mulv)(mat3x2s m, vec3s v) {
  vec2s dest;
  glm_mat3x2_mulv(m.raw, v.raw, dest.raw);
  return dest;
}

/*!
 * @brief Transpose mat3x2s (m) and store in mat2x3s (dest).
 *
 * @param[in]   m    mat3x2s (left)
 * @return[out] dest constructed mat2x3s from raw pointers
 */
CGLM_INLINE
mat2x3s
glms_mat3x2_(transpose)(mat3x2s m) {
  mat2x3s dest;
  glm_mat3x2_transpose(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x2s (m) by scalar constant (s).
 *
 * @param[in, out] m mat3x2s (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(scale)(mat3x2s m, float s) {
  glm_mat3x2_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat3x2_h */
