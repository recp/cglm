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
 * @brief Zero out the mat4x3s (dest).
 *
 * @return[out] dest constructed mat4x3s from raw pointer
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(zero)(void) {
  mat4x3s dest;
  glm_mat4x3_zero(dest.raw);
  return dest;
}

/*!
 * @brief Create mat4x3s (dest) from pointer (src).
 *
 * @param[in]   src  pointer to an array of floats
 * @return[out] dest constructed mat4x3s from raw pointer
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(make)(const float * __restrict src) {
  mat4x3s dest;
  glm_mat4x3_make(src, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat4x3s (m1) by mat3x4s (m2) and store in mat3s (dest).
 *
 * @code
 * r = glms_mat4x3_mul(mat4x3s, mat3x4s);
 * @endcode
 *
 * @param[in]   m1   mat4x3s (left)
 * @param[in]   m2   mat3x4s (right)
 * @return[out] dest constructed mat3s from raw pointers
 */
CGLM_INLINE
mat3s
glms_mat4x3_(mul)(mat4x3s m1, mat3x4s m2) {
  mat3s dest;
  glm_mat4x3_mul(m1.raw, m2.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat4x3s (m) by vec4s (v) and store in vec3s (dest).
 *
 * @param[in]   m    mat4x3s (left)
 * @param[in]   v    vec4s (right, column vector)
 * @return[out] dest constructed vec3s from raw pointers
 */
CGLM_INLINE
vec3s
glms_mat4x3_(mulv)(mat4x3s m, vec4s v) {
  vec3s dest;
  glm_mat4x3_mulv(m.raw, v.raw, dest.raw);
  return dest;
}

/*!
 * @brief Transpose mat4x3s (m) and store in mat3x4s (dest).
 *
 * @param[in]   m    mat4x3s (left)
 * @return[out] dest constructed mat3x4s from raw pointers
 */
CGLM_INLINE
mat3x4s
glms_mat4x3_(transpose)(mat4x3s m) {
  mat3x4s dest;
  glm_mat4x3_transpose(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat4x3s (m) by scalar constant (s).
 *
 * @param[in, out] m mat4x3s (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
mat4x3s
glms_mat4x3_(scale)(mat4x3s m, float s) {
  glm_mat4x3_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat4x3_h */
