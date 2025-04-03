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
   CGLM_INLINE mat2x3s glms_mat2x3_make(const float * __restrict src);
   CGLM_INLINE mat2s   glms_mat2x3_mul(mat2x3s m1, mat3x2s m2);
   CGLM_INLINE vec3s   glms_mat2x3_mulv(mat2x3s m, vec2s v);
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
 * @brief Zero out the mat2x3s (dest).
 *
 * @return[out] dest constructed mat2x3s from raw pointer
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(zero)(void) {
  mat2x3s dest;
  glm_mat2x3_zero(dest.raw);
  return dest;
}

/*!
 * @brief Create mat2x3s (dest) from pointer (src).
 *
 * @param[in]   src  pointer to an array of floats
 * @return[out] dest constructed mat2x3s from raw pointer
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(make)(const float * __restrict src) {
  mat2x3s dest;
  glm_mat2x3_make(src, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x3s (m1) by mat3x2s (m2) and store in mat3s (dest).
 *
 * @code
 * r = glms_mat2x3_mul(mat2x3s, mat3x2s);
 * @endcode
 *
 * @param[in]   m1   mat2x3s (left)
 * @param[in]   m2   mat3x2s (right)
 * @return[out] dest constructed mat3s from raw pointers
 */
CGLM_INLINE
mat3s
glms_mat2x3_(mul)(mat2x3s m1, mat3x2s m2) {
  mat3s dest;
  glm_mat2x3_mul(m1.raw, m2.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x3s (m) by vec2s (v) and store in vec3s (dest).
 *
 * @param[in]   m    mat2x3s (left)
 * @param[in]   v    vec2s (right, column vector)
 * @return[out] dest constructed vec3s from raw pointers
 */
CGLM_INLINE
vec3s
glms_mat2x3_(mulv)(mat2x3s m, vec2s v) {
  vec3s dest;
  glm_mat2x3_mulv(m.raw, v.raw, dest.raw);
  return dest;
}

/*!
 * @brief Transpose mat2x3s (m) and store in mat3x2s (dest).
 *
 * @param[in]   m    mat2x3s (left)
 * @return[out] dest constructed mat3x2s from raw pointers
 */
CGLM_INLINE
mat3x2s
glms_mat2x3_(transpose)(mat2x3s m) {
  mat3x2s dest;
  glm_mat2x3_transpose(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x3s (m) by scalar constant (s).
 *
 * @param[in, out] m mat2x3 (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(scale)(mat2x3s m, float s) {
  glm_mat2x3_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat2x3_h */
