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

typedef union ivec3s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    int x;
    int y;
    int z;
  };
#endif
  ivec3 raw;
} ivec3s;

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

typedef union CGLM_ALIGN_IF(16) versors {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };

  struct {
    vec3s imag;
    float real;
  };
#endif
  vec4 raw;
} versors;

typedef union mat3s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
  };
#endif
  vec3s col[3];
  mat3 raw;
} mat3s;

typedef union CGLM_ALIGN_MAT mat4s {
#ifndef CGLM_NO_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
#endif
  vec4s col[4];
  mat4 raw;
} mat4s;

#endif /* cglm_types_struct_h */
