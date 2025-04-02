/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT2X4_ZERO_INIT
   GLMS_MAT2X4_ZERO

 Functions:
   CGLM_INLINE mat2x4s glms_mat2x4_zero(void);
   CGLM_INLINE mat2x4s glms_mat2x4_make(const float * __restrict src);
   CGLM_INLINE mat2s   glms_mat2x4_mul(mat2x4s m1, mat4x2s m2);
   CGLM_INLINE vec4s   glms_mat2x4_mulv(mat2x4s m, vec2s v);
   CGLM_INLINE mat4x2s glms_mat2x4_transpose(mat2x4s m);
   CGLM_INLINE mat2x4s glms_mat2x4_scale(mat2x4s m, float s);
 */

#ifndef cglms_mat2x4_h
#define cglms_mat2x4_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat2x4.h"

/* api definition */
#define glms_mat2x4_(NAME) CGLM_STRUCTAPI(mat2x4, NAME)

#define GLMS_MAT2X4_ZERO_INIT {GLM_MAT2X4_ZERO_INIT}

/* for C only */
#define GLMS_MAT2X4_ZERO ((mat2x4s)GLMS_MAT2X4_ZERO_INIT)

/*!
 * @brief Zero out the mat2x4s (dest).
 *
 * @return[out] dest constructed mat2x4s from raw pointer
 */
CGLM_INLINE
mat2x4s
glms_mat2x4_(zero)(void) {
  mat2x4s dest;
  glm_mat2x4_zero(dest.raw);
  return dest;
}

/*!
 * @brief Create mat2x4s (dest) from pointer (src).
 *
 * @param[in]   src  pointer to an array of floats
 * @return[out] dest constructed mat2x4s from raw pointer
 */
CGLM_INLINE
mat2x4s
glms_mat2x4_(make)(const float * __restrict src) {
  mat2x4s dest;
  glm_mat2x4_make(src, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x4s (m1) by mat4x2s (m2) and store in mat4s (dest).
 *
 * @code
 * r = glms_mat2x4_mul(mat2x4s, mat4x2s);
 * @endcode
 *
 * @param[in]   m1   mat2x4s (left)
 * @param[in]   m2   mat4x2s (right)
 * @return[out] dest constructed mat4s from raw pointers
 */
CGLM_INLINE
mat4s
glms_mat2x4_(mul)(mat2x4s m1, mat4x2s m2) {
  mat4s dest;
  glm_mat2x4_mul(m1.raw, m2.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x4s (m) by vec2s (v) and store in vec4s (dest).
 *
 * @param[in]   m    mat2x4s (left)
 * @param[in]   v    vec2s (right, column vector)
 * @return[out] dest constructed vec4s from raw pointers
 */
CGLM_INLINE
vec4s
glms_mat2x4_(mulv)(mat2x4s m, vec2s v) {
  vec4s dest;
  glm_mat2x4_mulv(m.raw, v.raw, dest.raw);
  return dest;
}

/*!
 * @brief Transpose mat2x4s (m) and store in mat4x2s (dest).
 *
 * @param[in]   m    mat2x4s (left)
 * @return[out] dest constructed mat4x2s from raw pointers
 */
CGLM_INLINE
mat4x2s
glms_mat2x4_(transpose)(mat2x4s m) {
  mat4x2s dest;
  glm_mat2x4_transpose(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief Multiply mat2x4s (m) by scalar constant (s).
 *
 * @param[in, out] m mat2x4s (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
mat2x4s
glms_mat2x4_(scale)(mat2x4s m, float s) {
  glm_mat2x4_scale(m.raw, s);
  return m;
}

#endif /* cglms_mat2x4_h */
