/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT3X4_ZERO_INIT
   GLMS_MAT3X4_ZERO

 Functions:
   CGLM_INLINE mat3x4s glms_mat3x4_zero(void);
   CGLM_INLINE mat3x4s glms_mat3x4_make(const float * __restrict src);
   CGLM_INLINE mat4s   glms_mat3x4_mul(mat3x4s m1, mat4x3s m2);
   CGLM_INLINE vec4s   glms_mat3x4_mulv(mat3x4s m, vec3s v);
   CGLM_INLINE mat4x3s glms_mat3x4_transpose(mat3x4s m);
   CGLM_INLINE mat3x4s glms_mat3x4_scale(mat3x4s m, float s);
 */

#ifndef cglms_mat3x4_h
#define cglms_mat3x4_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3x4.h"

/* api definition */
#define glms_mat3x4_(NAME) CGLM_STRUCTAPI(mat3x4, NAME)

#define GLMS_MAT3X4_ZERO_INIT {GLM_MAT3X4_ZERO_INIT}

/* for C only */
#define GLMS_MAT3X4_ZERO ((mat3x4s)GLMS_MAT3X4_ZERO_INIT)

/*!
 * @brief Zero out the mat3x4s (dest).
 *
 * @return[out] dest constructed mat3x4s from raw pointer
 */
CGLM_INLINE
mat3x4s
glms_mat3x4_(zero)(void) {
  mat3x4s dest;
  glm_mat3x4_zero(dest.raw);
  return dest;
}

/*!
 * @brief Create mat3x4s (dest) from pointer (src).
 *
 * @param[in]   src  pointer to an array of floats
 * @return[out] dest constructed mat3x4s from raw pointer
 */
CGLM_INLINE
mat3x4s
glms_mat3x4_(make)(const float * __restrict src) {
  mat3x4s dest;
  glm_mat3x4_make(src, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x4s (m1) by mat4x3s (m2) and store in mat4s (dest).
 *
 * @code
 * r = glms_mat3x4_mul(mat3x4s, mat4x3s);
 * @endcode
 *
 * @param[in]   m1   mat3x4s (left)
 * @param[in]   m2   mat4x3s (right)
 * @return[out] dest constructed mat4s from raw pointers
 */
CGLM_INLINE
mat4s
glms_mat3x4_(mul)(mat3x4s m1, mat4x3s m2) {
  mat4s dest;
  glm_mat3x4_mul(m1.raw, m2.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x4s (m) by vec3s (v) and store in vec4s (dest).
 *
 * @param[in]   m    mat3x4s (left)
 * @param[in]   v    vec3s (right, column vector)
 * @return[out] dest constructed vec4s from raw pointers
 */
CGLM_INLINE
vec4s
glms_mat3x4_(mulv)(mat3x4s m, vec3s v) {
  vec4s dest;
  glm_mat3x4_mulv(m.raw, v.raw, dest.raw);
  return dest;
}

/*!
 * @brief Transpose mat3x4s (m) and store in mat4x3s (dest).
 *
 * @param[in]   m    mat3x4s (left)
 * @return[out] dest constructed mat4x3s from raw pointers
 */
CGLM_INLINE
mat4x3s
glms_mat3x4_(transpose)(mat3x4s m) {
  mat4x3s dest;
  glm_mat3x4_transpose(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat3x4s (m) by scalar constant (s).
 *
 * @param[in, out] m mat3x4s (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
mat3x4s
glms_mat3x4_(scale)(mat3x4s m, float s) {
  glm_mat3x4_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat3x4_h */
