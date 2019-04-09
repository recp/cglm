/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_struct_h
#define cglm_types_struct_h

#include "types.h"

typedef union CGLM_ALIGN_IF(16) vec3s {
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

#endif /* cglm_types_struct_h */
