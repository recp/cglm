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
* @return v
*/
CGLM_INLINE
simd_float3
glm_vec3_applesimd(vec3 v) {
  return (simd_float3){v[0], v[1], v[2]};
}

#endif
#endif /* cglm_applesimd_h */
