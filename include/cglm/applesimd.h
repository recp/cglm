/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_applesimd_h
#define cglm_applesimd_h
#if defined(__APPLE__)                                                        \
    && defined(SIMD_COMPILER_HAS_REQUIRED_FEATURES)                           \
    && defined(SIMD_BASE)                                                     \
    && defined(SIMD_TYPES)                                                    \
    && defined(SIMD_VECTOR_TYPES)

#include "common.h"
#include "struct.h"

/*!
 * @brief converts mat4 to Apple's simd type simd_float4x4
 * @return simd_float4x4
 */
CGLM_INLINE
simd_float4x4
glm_mat4_applesimd(mat4 m) {
  simd_float4x4 t;

  t.columns[0][0] = m[0][0];
  t.columns[0][1] = m[0][1];
  t.columns[0][2] = m[0][2];
  t.columns[0][3] = m[0][3];

  t.columns[1][0] = m[1][0];
  t.columns[1][1] = m[1][1];
  t.columns[1][2] = m[1][2];
  t.columns[1][3] = m[1][3];

  t.columns[2][0] = m[2][0];
  t.columns[2][1] = m[2][1];
  t.columns[2][2] = m[2][2];
  t.columns[2][3] = m[2][3];

  t.columns[3][0] = m[3][0];
  t.columns[3][1] = m[3][1];
  t.columns[3][2] = m[3][2];
  t.columns[3][3] = m[3][3];

  return t;
}

/*!
* @brief converts mat3 to Apple's simd type simd_float3x3
* @return simd_float3x3
*/
CGLM_INLINE
simd_float3x3
glm_mat3_applesimd(mat3 m) {
  simd_float3x3 t;

  t.columns[0][0] = m[0][0];
  t.columns[0][1] = m[0][1];
  t.columns[0][2] = m[0][2];

  t.columns[1][0] = m[1][0];
  t.columns[1][1] = m[1][1];
  t.columns[1][2] = m[1][2];

  t.columns[2][0] = m[2][0];
  t.columns[2][1] = m[2][1];
  t.columns[2][2] = m[2][2];

  return t;
}

/*!
* @brief converts vec4 to Apple's simd type simd_float4
* @return simd_float4
*/
CGLM_INLINE
simd_float4
glm_vec4_applesimd(vec4 v) {
  return (simd_float4){v[0], v[1], v[2], v[3]};
}

/*!
* @brief converts vec3 to Apple's simd type simd_float3
* @return simd_float3
*/
CGLM_INLINE
simd_float3
glm_vec3_applesimd(vec3 v) {
  return (simd_float3){v[0], v[1], v[2]};
}

/*!
 * @brief generic function to convert cglm types to Apple's simd types
 *
 * Example usage:
 *   simd_float4x4 m = applesimd(mat4_value);
 *   simd_float3   v = applesimd(vec3_value);
 *
 * @param x cglm type (mat4, mat3, vec4, vec3)
 * @return corresponding Apple simd type
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#  define applesimd(x) _Generic((x),                    \
                         mat4:  glm_mat4_applesimd,     \
                         mat3:  glm_mat3_applesimd,     \
                         vec4:  glm_vec4_applesimd,     \
                         vec3:  glm_vec3_applesimd      \
                       )((x))
#endif

#ifdef cglm_types_struct_h
CGLM_INLINE simd_float4x4 glms_mat4_(applesimd)(mat4s m) { return glm_mat4_applesimd(m.raw); }
CGLM_INLINE simd_float3x3 glms_mat3_(applesimd)(mat3s m) { return glm_mat3_applesimd(m.raw); }
CGLM_INLINE simd_float4   glms_vec4_(applesimd)(vec4s v) { return glm_vec4_applesimd(v.raw); }
CGLM_INLINE simd_float3   glms_vec3_(applesimd)(vec3s v) { return glm_vec3_applesimd(v.raw); }

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#  undef applesimd
#  define applesimd(x) _Generic((x),                       \
                         mat4:  glm_mat4_applesimd,        \
                         mat3:  glm_mat3_applesimd,        \
                         vec4:  glm_vec4_applesimd,        \
                         vec3:  glm_vec3_applesimd,        \
                         mat4s: glms_mat4_(applesimd),     \
                         mat3s: glms_mat3_(applesimd),     \
                         vec4s: glms_vec4_(applesimd),     \
                         vec3s: glms_vec3_(applesimd)      \
                       )((x))
#endif
#endif

#endif
#endif /* cglm_applesimd_h */
