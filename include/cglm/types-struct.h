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

/*----------------------------------------------*
 *     single-precision floating-point types    *
 *----------------------------------------------*/
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


/*----------------------------------------------*
 *             8-bit integer types              *
 *----------------------------------------------*/
typedef union ubvec2s {
  ubvec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t x;
    uint8_t y;
  };
  
  struct {
    uint8_t r;
    uint8_t i;
  };
  
  struct {
    uint8_t u;
    uint8_t v;
  };
  
  struct {
    uint8_t s;
    uint8_t t;
  };
#endif
} ubvec2s;

typedef union ubvec3s {
  ubvec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t x;
    uint8_t y;
    uint8_t z;
  };
  
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  };
#endif
} ubvec3s;

typedef union ubvec4s {
  ubvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t w;
  };
  
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  };
#endif
} ubvec4s;

typedef union CGLM_ALIGN_IF(16) ubversors {
  ubvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t w;
  };

  struct {
    ubvec3s imag;
    uint8_t real;
  };
#endif
} ubversors;

typedef union ubmat2s {
  ubmat2  raw;
  ubvec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
  };
#endif
} ubmat2s;

typedef union ubmat2x3s {
  ubmat2x3 raw;
  ubvec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
  };
#endif
} ubmat2x3s;

typedef union ubmat2x4s {
  ubmat2x4 raw;
  ubvec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
  };
#endif
} ubmat2x4s;

typedef union ubmat3s {
  ubmat3  raw;
  ubvec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
    uint8_t m20, m21, m22;
  };
#endif
} ubmat3s;

typedef union ubmat3x2s {
  ubmat3x2 raw;
  ubvec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
    uint8_t m20, m21;
  };
#endif
} ubmat3x2s;

typedef union ubmat3x4s {
  ubmat3x4 raw;
  ubvec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
    uint8_t m20, m21, m22, m23;
  };
#endif
} ubmat3x4s;

typedef union CGLM_ALIGN_MAT ubmat4s {
  ubmat4  raw;
  ubvec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
    uint8_t m20, m21, m22, m23;
    uint8_t m30, m31, m32, m33;
  };
#endif
} ubmat4s;

typedef union ubmat4x2s {
  ubmat4x2 raw;
  ubvec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
    uint8_t m20, m21;
    uint8_t m30, m31;
  };
#endif
} ubmat4x2s;

typedef union ubmat4x3s {
  ubmat4x3 raw;
  ubvec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
    uint8_t m20, m21, m22;
    uint8_t m30, m31, m32;
  };
#endif
} ubmat4x3s;

typedef union bvec2s {
  bvec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t x;
    int8_t y;
  };
  
  struct {
    int8_t r;
    int8_t i;
  };
  
  struct {
    int8_t u;
    int8_t v;
  };
  
  struct {
    int8_t s;
    int8_t t;
  };
#endif
} bvec2s;

typedef union bvec3s {
  bvec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t x;
    int8_t y;
    int8_t z;
  };
  
  struct {
    int8_t r;
    int8_t g;
    int8_t b;
  };
#endif
} bvec3s;

typedef union bvec4s {
  bvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t x;
    int8_t y;
    int8_t z;
    int8_t w;
  };
  
  struct {
    int8_t r;
    int8_t g;
    int8_t b;
    int8_t a;
  };
#endif
} bvec4s;

typedef union CGLM_ALIGN_IF(16) bversors {
  bvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t x;
    int8_t y;
    int8_t z;
    int8_t w;
  };

  struct {
    bvec3s imag;
    int8_t real;
  };
#endif
} bversors;

typedef union bmat2s {
  bmat2  raw;
  bvec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
  };
#endif
} bmat2s;

typedef union bmat2x3s {
  bmat2x3 raw;
  bvec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
  };
#endif
} bmat2x3s;

typedef union bmat2x4s {
  bmat2x4 raw;
  bvec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
  };
#endif
} bmat2x4s;

typedef union bmat3s {
  bmat3  raw;
  bvec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
    int8_t m20, m21, m22;
  };
#endif
} bmat3s;

typedef union bmat3x2s {
  bmat3x2 raw;
  bvec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
    int8_t m20, m21;
  };
#endif
} bmat3x2s;

typedef union bmat3x4s {
  bmat3x4 raw;
  bvec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
    int8_t m20, m21, m22, m23;
  };
#endif
} bmat3x4s;

typedef union CGLM_ALIGN_MAT bmat4s {
  bmat4  raw;
  bvec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
    int8_t m20, m21, m22, m23;
    int8_t m30, m31, m32, m33;
  };
#endif
} bmat4s;

typedef union bmat4x2s {
  bmat4x2 raw;
  bvec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
    int8_t m20, m21;
    int8_t m30, m31;
  };
#endif
} bmat4x2s;

typedef union bmat4x3s {
  bmat4x3 raw;
  bvec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
    int8_t m20, m21, m22;
    int8_t m30, m31, m32;
  };
#endif
} bmat4x3s;

/*----------------------------------------------*
 *           16-bit integer types               *
 *----------------------------------------------*/
typedef union uhvec2s {
  uhvec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t x;
    uint16_t y;
  };
  
  struct {
    uint16_t r;
    uint16_t i;
  };
  
  struct {
    uint16_t u;
    uint16_t v;
  };
  
  struct {
    uint16_t s;
    uint16_t t;
  };
#endif
} uhvec2s;

typedef union uhvec3s {
  uhvec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
  };
  
  struct {
    uint16_t r;
    uint16_t g;
    uint16_t b;
  };
#endif
} uhvec3s;

typedef union uhvec4s {
  uhvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint16_t w;
  };
  
  struct {
    uint16_t r;
    uint16_t g;
    uint16_t b;
    uint16_t a;
  };
#endif
} uhvec4s;

typedef union CGLM_ALIGN_IF(16) uhversors {
  uhvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint16_t w;
  };

  struct {
    uhvec3s imag;
    uint16_t real;
  };
#endif
} uhversors;

typedef union uhmat2s {
  uhmat2  raw;
  uhvec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
  };
#endif
} uhmat2s;

typedef union uhmat2x3s {
  uhmat2x3 raw;
  uhvec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
  };
#endif
} uhmat2x3s;

typedef union uhmat2x4s {
  uhmat2x4 raw;
  uhvec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
  };
#endif
} uhmat2x4s;

typedef union uhmat3s {
  uhmat3  raw;
  uhvec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
    uint16_t m20, m21, m22;
  };
#endif
} uhmat3s;

typedef union uhmat3x2s {
  uhmat3x2 raw;
  uhvec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
    uint16_t m20, m21;
  };
#endif
} uhmat3x2s;

typedef union uhmat3x4s {
  uhmat3x4 raw;
  uhvec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
    uint16_t m20, m21, m22, m23;
  };
#endif
} uhmat3x4s;

typedef union CGLM_ALIGN_MAT uhmat4s {
  uhmat4  raw;
  uhvec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
    uint16_t m20, m21, m22, m23;
    uint16_t m30, m31, m32, m33;
  };
#endif
} uhmat4s;

typedef union uhmat4x2s {
  uhmat4x2 raw;
  uhvec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
    uint16_t m20, m21;
    uint16_t m30, m31;
  };
#endif
} uhmat4x2s;

typedef union uhmat4x3s {
  uhmat4x3 raw;
  uhvec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
    uint16_t m20, m21, m22;
    uint16_t m30, m31, m32;
  };
#endif
} uhmat4x3s;

typedef union hvec2s {
  hvec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t x;
    int16_t y;
  };
  
  struct {
    int16_t r;
    int16_t i;
  };
  
  struct {
    int16_t u;
    int16_t v;
  };
  
  struct {
    int16_t s;
    int16_t t;
  };
#endif
} hvec2s;

typedef union hvec3s {
  hvec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t x;
    int16_t y;
    int16_t z;
  };
  
  struct {
    int16_t r;
    int16_t g;
    int16_t b;
  };
#endif
} hvec3s;

typedef union hvec4s {
  hvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t w;
  };
  
  struct {
    int16_t r;
    int16_t g;
    int16_t b;
    int16_t a;
  };
#endif
} hvec4s;

typedef union CGLM_ALIGN_IF(16) hversors {
  hvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t w;
  };

  struct {
    hvec3s imag;
    int16_t real;
  };
#endif
} hversors;

typedef union hmat2s {
  hmat2  raw;
  hvec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
  };
#endif
} hmat2s;

typedef union hmat2x3s {
  hmat2x3 raw;
  hvec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
  };
#endif
} hmat2x3s;

typedef union hmat2x4s {
  hmat2x4 raw;
  hvec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
  };
#endif
} hmat2x4s;

typedef union hmat3s {
  hmat3  raw;
  hvec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
    int16_t m20, m21, m22;
  };
#endif
} hmat3s;

typedef union hmat3x2s {
  hmat3x2 raw;
  hvec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
    int16_t m20, m21;
  };
#endif
} hmat3x2s;

typedef union hmat3x4s {
  hmat3x4 raw;
  hvec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
    int16_t m20, m21, m22, m23;
  };
#endif
} hmat3x4s;

typedef union CGLM_ALIGN_MAT hmat4s {
  hmat4  raw;
  hvec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
    int16_t m20, m21, m22, m23;
    int16_t m30, m31, m32, m33;
  };
#endif
} hmat4s;

typedef union hmat4x2s {
  hmat4x2 raw;
  hvec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
    int16_t m20, m21;
    int16_t m30, m31;
  };
#endif
} hmat4x2s;

typedef union hmat4x3s {
  hmat4x3 raw;
  hvec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
    int16_t m20, m21, m22;
    int16_t m30, m31, m32;
  };
#endif
} hmat4x3s;

/*----------------------------------------------*
 *           32-bit integer types               *
 *----------------------------------------------*/
typedef union ivec2s {
  ivec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t x;
    int32_t y;
  };
  
  struct {
    int32_t r;
    int32_t i;
  };
  
  struct {
    int32_t u;
    int32_t v;
  };
  
  struct {
    int32_t s;
    int32_t t;
  };
#endif
} ivec2s;

typedef union ivec3s {
  ivec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t x;
    int32_t y;
    int32_t z;
  };
  
  struct {
    int32_t r;
    int32_t g;
    int32_t b;
  };
#endif
} ivec3s;

typedef union ivec4s {
  ivec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
  };
  
  struct {
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
  };
#endif
} ivec4s;

typedef union CGLM_ALIGN_IF(16) iversors {
  ivec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
  };

  struct {
    ivec3s imag;
    int32_t    real;
  };
#endif
} iversors;

typedef union imat2s {
  imat2  raw;
  ivec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
  };
#endif
} imat2s;

typedef union imat2x3s {
  imat2x3 raw;
  ivec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
  };
#endif
} imat2x3s;

typedef union imat2x4s {
  imat2x4 raw;
  ivec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
  };
#endif
} imat2x4s;

typedef union imat3s {
  imat3  raw;
  ivec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
    int32_t m20, m21, m22;
  };
#endif
} imat3s;

typedef union imat3x2s {
  imat3x2 raw;
  ivec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
    int32_t m20, m21;
  };
#endif
} imat3x2s;

typedef union imat3x4s {
  imat3x4 raw;
  ivec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
    int32_t m20, m21, m22, m23;
  };
#endif
} imat3x4s;

typedef union CGLM_ALIGN_MAT imat4s {
  imat4  raw;
  ivec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
    int32_t m20, m21, m22, m23;
    int32_t m30, m31, m32, m33;
  };
#endif
} imat4s;

typedef union imat4x2s {
  imat4x2 raw;
  ivec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
    int32_t m20, m21;
    int32_t m30, m31;
  };
#endif
} imat4x2s;

typedef union imat4x3s {
  imat4x3 raw;
  ivec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
    int32_t m20, m21, m22;
    int32_t m30, m31, m32;
  };
#endif
} imat4x3s;

typedef union uvec2s {
  uvec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t x;
    uint32_t y;
  };
  
  struct {
    uint32_t r;
    uint32_t i;
  };
  
  struct {
    uint32_t u;
    uint32_t v;
  };
  
  struct {
    uint32_t s;
    uint32_t t;
  };
#endif
} uvec2s;

typedef union uvec3s {
  uvec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t x;
    uint32_t y;
    uint32_t z;
  };
  
  struct {
    uint32_t r;
    uint32_t g;
    uint32_t b;
  };
#endif
} uvec3s;

typedef union uvec4s {
  uvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
  };
  
  struct {
    uint32_t r;
    uint32_t g;
    uint32_t b;
    uint32_t a;
  };
#endif
} uvec4s;

typedef union CGLM_ALIGN_IF(16) uversors {
  uvec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
  };

  struct {
    uvec3s imag;
    uint32_t    real;
  };
#endif
} uversors;

typedef union umat2s {
  umat2  raw;
  uvec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
  };
#endif
} umat2s;

typedef union umat2x3s {
  umat2x3 raw;
  uvec3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
  };
#endif
} umat2x3s;

typedef union umat2x4s {
  umat2x4 raw;
  uvec4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
  };
#endif
} umat2x4s;

typedef union umat3s {
  umat3  raw;
  uvec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
    uint32_t m20, m21, m22;
  };
#endif
} umat3s;

typedef union umat3x2s {
  umat3x2 raw;
  uvec2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
    uint32_t m20, m21;
  };
#endif
} umat3x2s;

typedef union umat3x4s {
  umat3x4 raw;
  uvec4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
    uint32_t m20, m21, m22, m23;
  };
#endif
} umat3x4s;

typedef union CGLM_ALIGN_MAT umat4s {
  umat4  raw;
  uvec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
    uint32_t m20, m21, m22, m23;
    uint32_t m30, m31, m32, m33;
  };
#endif
} umat4s;

typedef union umat4x2s {
  umat4x2 raw;
  uvec2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
    uint32_t m20, m21;
    uint32_t m30, m31;
  };
#endif
} umat4x2s;

typedef union umat4x3s {
  umat4x3 raw;
  uvec3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
    uint32_t m20, m21, m22;
    uint32_t m30, m31, m32;
  };
#endif
} umat4x3s;

#endif /* cglm_types_struct_h */
