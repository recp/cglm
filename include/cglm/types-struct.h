/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_struct_h
#define cglm_types_struct_h

#include "types.h"

/*
 * Anonymous structs are available since C11, but we'd like to be compatible
 * with C99 and C89 too. So let's figure out if we should be using them or not.
 * It's simply a convenience feature, you can e.g. build the library with
 * anonymous structs and your application without them and they'll still be
 * compatible, cglm doesn't use the anonymous structs internally.
 */
#ifndef CGLM_USE_ANONYMOUS_STRUCT
   /* If the user doesn't explicitly specify if they want anonymous structs or
    * not, then we'll try to intuit an appropriate choice. */
#  if defined(CGLM_NO_ANONYMOUS_STRUCT)
     /* The user has defined CGLM_NO_ANONYMOUS_STRUCT. This used to be the
      * only #define governing the use of anonymous structs, so for backward
      * compatibility, we still honor that choice and disable them. */
#    define CGLM_USE_ANONYMOUS_STRUCT 0
     /* Disable anonymous structs if strict ANSI mode is enabled for C89 or C99 */
#  elif defined(__STRICT_ANSI__) && \
        (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 201112L))
     /* __STRICT_ANSI__ is defined and we're in C89
      * or C99 mode (C11 or later not detected) */
#    define CGLM_USE_ANONYMOUS_STRUCT 0
#  elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) || \
        (defined(__cplusplus)      && __cplusplus >= 201103L)
     /* We're compiling for C11 or this is the MSVC compiler. In either
      * case, anonymous structs are available, so use them. */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
     /* GCC 4.6 and onwards support anonymous structs as an extension */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  elif defined(__clang__) && __clang_major__ >= 3
     /* Clang 3.0 and onwards support anonymous structs as an extension */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  elif defined(_MSC_VER) && (_MSC_VER >= 1900) /*  Visual Studio 2015 */
     /* We can support anonymous structs
      * since Visual Studio 2015 or 2017 (1910) maybe? */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  else
     /* Otherwise, we're presumably building for C99 or C89 and can't rely
      * on anonymous structs being available. Turn them off. */
#    define CGLM_USE_ANONYMOUS_STRUCT 0
#  endif
#endif

typedef union vec2s {
  vec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
  };
  
  struct {
    float r;
    float i;
  };
  
  struct {
    float u;
    float v;
  };
  
  struct {
    float s;
    float t;
  };
#endif
} vec2s;

typedef union vec3s {
  vec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
  };
  
  struct {
    float r;
    float g;
    float b;
  };
#endif
} vec3s;

typedef union ivec2s {
  ivec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int x;
    int y;
  };
  
  struct {
    int r;
    int i;
  };
  
  struct {
    int u;
    int v;
  };
  
  struct {
    int s;
    int t;
  };
#endif
} ivec2s;

typedef union ivec3s {
  ivec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int x;
    int y;
    int z;
  };
  
  struct {
    int r;
    int g;
    int b;
  };
#endif
} ivec3s;

typedef union ivec4s {
  ivec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int x;
    int y;
    int z;
    int w;
  };
  
  struct {
    int r;
    int g;
    int b;
    int a;
  };
#endif
} ivec4s;

typedef union CGLM_ALIGN_IF(16) vec4s {
  vec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };
  
  struct {
    float r;
    float g;
    float b;
    float a;
  };
#endif
} vec4s;

typedef union CGLM_ALIGN_IF(16) versors {
  vec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
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
} versors;

typedef union mat2s {
  mat2  raw;
  vec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
  };
#endif
} mat2s;

typedef union mat2x3s {
  mat2x3 raw;
  vec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
  };
#endif
} mat2x3s;

typedef union mat2x4s {
  mat2x4 raw;
  vec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
  };
#endif
} mat2x4s;

typedef union mat3s {
  mat3  raw;
  vec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
  };
#endif
} mat3s;

typedef union mat3x2s {
  mat3x2 raw;
  vec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
    float m20, m21;
  };
#endif
} mat3x2s;

typedef union mat3x4s {
  mat3x4 raw;
  vec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
  };
#endif
} mat3x4s;

typedef union CGLM_ALIGN_MAT mat4s {
  mat4  raw;
  vec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
#endif
} mat4s;

typedef union mat4x2s {
  mat4x2 raw;
  vec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
    float m20, m21;
    float m30, m31;
  };
#endif
} mat4x2s;

typedef union mat4x3s {
  mat4x3 raw;
  vec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    float m30, m31, m32;
  };
#endif
} mat4x3s;

#endif /* cglm_types_struct_h */
