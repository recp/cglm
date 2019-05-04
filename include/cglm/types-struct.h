/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_struct_h
#define cglm_types_struct_h

#include "types.h"

typedef union vec3s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
  };
#endif
  vec3 raw;
} vec3s;

typedef union CGLM_ALIGN_IF(16) vec4s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };
#endif
  vec4 raw;
} vec4s;

typedef vec4s versors;

typedef union mat3s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
  };
  struct {
    vec3s col0;
    vec3s col1;
    vec3s col2;
  };
#endif
  mat3 raw;
} mat3s;

#ifdef __AVX__
typedef union CGLM_ALIGN_IF(32) mat4s {
#else
typedef union CGLM_ALIGN_IF(16) mat4s {
#endif
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
  };
  struct {
    vec4s col0;
    vec4s col1;
    vec4s col2;
    vec4s col3;
  };
#endif
  mat4 raw;
} mat4s;

#endif /* cglm_types_struct_h */
