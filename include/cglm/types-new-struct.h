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
typedef union f32v2s {
  f32v2 raw;
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
} f32v2s;

typedef union f32v3s {
  f32v3 raw;
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
} f32v3s;

typedef union CGLM_ALIGN_IF(16) f32v4s {
  f32v4 raw;
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
} f32v4s;

typedef union CGLM_ALIGN_IF(16) f32versors {
  f32v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };

  struct {
    f32v3s imag;
    float real;
  };
#endif
} f32versors;

typedef union f32m2s {
  f32m2  raw;
  f32v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
  };
#endif
} f32m2s;

typedef union f32m2x3s {
  f32m2x3 raw;
  f32v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
  };
#endif
} f32m2x3s;

typedef union f32m2x4s {
  f32m2x4 raw;
  f32v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
  };
#endif
} f32m2x4s;

typedef union f32m3s {
  f32m3  raw;
  f32v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
  };
#endif
} f32m3s;

typedef union f32m3x2s {
  f32m3x2 raw;
  f32v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
    float m20, m21;
  };
#endif
} f32m3x2s;

typedef union f32m3x4s {
  f32v3x4 raw;
  f32v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
  };
#endif
} f32m3x4s;

typedef union CGLM_ALIGN_MAT f32m4s {
  f32m4  raw;
  f32v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
#endif
} f32m4s;

typedef union f32m4x2s {
  f32m4x2 raw;
  f32v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
    float m20, m21;
    float m30, m31;
  };
#endif
} f32m4x2s;

typedef union f32m4x3s {
  f32m4x3 raw;
  f32v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    float m30, m31, m32;
  };
#endif
} f32m4x3s;


/*----------------------------------------------*
 *             8-bit integer types              *
 *----------------------------------------------*/
typedef union u8v2s {
  u8v2 raw;
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
} u8v2s;

typedef union u8v3s {
  u8v3 raw;
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
} u8v3s;

typedef union u8v4s {
  u8v4 raw;
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
} u8v4s;

typedef union CGLM_ALIGN_IF(16) u8versors {
  u8v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t w;
  };

  struct {
    u8v3s imag;
    uint8_t real;
  };
#endif
} u8versors;

typedef union u8m2s {
  u8v2  raw;
  u8v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
  };
#endif
} u8m2s;

typedef union u8m2x3s {
  u8m2x3 raw;
  u8v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
  };
#endif
} u8m2x3s;

typedef union u8m2x4s {
  u8m2x4 raw;
  u8v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
  };
#endif
} u8m2x4s;

typedef union u8m3s {
  u8m3  raw;
  u8v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
    uint8_t m20, m21, m22;
  };
#endif
} u8m3s;

typedef union u8m3x2s {
  u8m3x2 raw;
  u8v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
    uint8_t m20, m21;
  };
#endif
} u8m3x2s;

typedef union u8m3x4s {
  u8m3x4 raw;
  u8v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
    uint8_t m20, m21, m22, m23;
  };
#endif
} u8m3x4s;

typedef union CGLM_ALIGN_MAT u8m4s {
  u8m4  raw;
  u8v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02, m03;
    uint8_t m10, m11, m12, m13;
    uint8_t m20, m21, m22, m23;
    uint8_t m30, m31, m32, m33;
  };
#endif
} u8m4s;

typedef union u8m4x2s {
  u8m4x2 raw;
  u8m2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01;
    uint8_t m10, m11;
    uint8_t m20, m21;
    uint8_t m30, m31;
  };
#endif
} u8m4x2s;

typedef union u8m4x3s {
  u8m4x3 raw;
  u8v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint8_t m00, m01, m02;
    uint8_t m10, m11, m12;
    uint8_t m20, m21, m22;
    uint8_t m30, m31, m32;
  };
#endif
} u8m4x3s;

typedef union i8v2s {
  i8v2 raw;
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
} i8v2s;

typedef union i8v3s {
  i8v3 raw;
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
} i8v3s;

typedef union i8v4s {
  i8v4 raw;
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
} i8v4s;

typedef union CGLM_ALIGN_IF(16) i8versors {
  i8v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t x;
    int8_t y;
    int8_t z;
    int8_t w;
  };

  struct {
    i8v3s imag;
    int8_t real;
  };
#endif
} i8versors;

typedef union i8m2s {
  i8m2  raw;
  i8v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
  };
#endif
} i8m2s;

typedef union i8m2x3s {
  i8m2x3 raw;
  i8v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
  };
#endif
} i8m2x3s;

typedef union i8m2x4s {
  i8m2x4 raw;
  i8v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
  };
#endif
} i8m2x4s;

typedef union i8m3s {
  i8m3  raw;
  i8v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
    int8_t m20, m21, m22;
  };
#endif
} i8m3s;

typedef union i8m3x2s {
  i8m3x2 raw;
  i8v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
    int8_t m20, m21;
  };
#endif
} i8m3x2s;

typedef union i8m3x4s {
  i8m3x4 raw;
  i8v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
    int8_t m20, m21, m22, m23;
  };
#endif
} i8m3x4s;

typedef union CGLM_ALIGN_MAT i8m4s {
  i8m4  raw;
  i8v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02, m03;
    int8_t m10, m11, m12, m13;
    int8_t m20, m21, m22, m23;
    int8_t m30, m31, m32, m33;
  };
#endif
} i8m4s;

typedef union i8m4x2s {
  i8m4x2 raw;
  i8v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01;
    int8_t m10, m11;
    int8_t m20, m21;
    int8_t m30, m31;
  };
#endif
} i8m4x2s;

typedef union i8m4x3s {
  i8m4x3 raw;
  i8v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int8_t m00, m01, m02;
    int8_t m10, m11, m12;
    int8_t m20, m21, m22;
    int8_t m30, m31, m32;
  };
#endif
} i8m4x3s;

/*----------------------------------------------*
 *           16-bit integer types               *
 *----------------------------------------------*/
typedef union u16v2s {
  u16v2 raw;
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
} u16v2s;

typedef union u16v3s {
  u16v3 raw;
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
} u16v3s;

typedef union u16v4s {
  u16v4 raw;
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
} u16v4s;

typedef union CGLM_ALIGN_IF(16) u16versors {
  u16v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint16_t w;
  };

  struct {
    u16v3s imag;
    uint16_t real;
  };
#endif
} u16versors;

typedef union u16m2s {
  u16m2  raw;
  u16v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
  };
#endif
} u16m2s;

typedef union u16m2x3s {
  u16m2x3 raw;
  u16v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
  };
#endif
} u16m2x3s;

typedef union u16m2x4s {
  u16m2x4 raw;
  u16v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
  };
#endif
} u16m2x4s;

typedef union u16m3s {
  u16m3  raw;
  u16v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
    uint16_t m20, m21, m22;
  };
#endif
} u16m3s;

typedef union u16m3x2s {
  u16m3x2 raw;
  u16v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
    uint16_t m20, m21;
  };
#endif
} u16m3x2s;

typedef union u16m3x4s {
  u16m3x4 raw;
  u16v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
    uint16_t m20, m21, m22, m23;
  };
#endif
} u16m3x4s;

typedef union CGLM_ALIGN_MAT u16m4s {
  u16m4  raw;
  u16v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02, m03;
    uint16_t m10, m11, m12, m13;
    uint16_t m20, m21, m22, m23;
    uint16_t m30, m31, m32, m33;
  };
#endif
} u16m4s;

typedef union u16m4x2s {
  u16m4x2 raw;
  u16v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01;
    uint16_t m10, m11;
    uint16_t m20, m21;
    uint16_t m30, m31;
  };
#endif
} u16m4x2s;

typedef union u16m4x3s {
  u16m4x3 raw;
  u16v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint16_t m00, m01, m02;
    uint16_t m10, m11, m12;
    uint16_t m20, m21, m22;
    uint16_t m30, m31, m32;
  };
#endif
} u16m4x3s;

typedef union i16v2s {
  i16v2 raw;
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
} i16v2s;

typedef union i16v3s {
  i16v3 raw;
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
} i16v3s;

typedef union i16v4s {
  i16v4 raw;
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
} i16v4s;

typedef union CGLM_ALIGN_IF(16) i16versors {
  i16v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t w;
  };

  struct {
    i16v3s imag;
    int16_t real;
  };
#endif
} i16versors;

typedef union i16m2s {
  i16m2  raw;
  i16v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
  };
#endif
} i16m2s;

typedef union i16m2x3s {
  i16m2x3 raw;
  i16v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
  };
#endif
} i16m2x3s;

typedef union i16m2x4s {
  i16m2x4 raw;
  i16v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
  };
#endif
} i16m2x4s;

typedef union i16m3s {
  i16m3  raw;
  i16v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
    int16_t m20, m21, m22;
  };
#endif
} i16m3s;

typedef union i16m3x2s {
  i16m3x2 raw;
  i16v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
    int16_t m20, m21;
  };
#endif
} i16m3x2s;

typedef union i16m3x4s {
  i16m3x4 raw;
  i16v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
    int16_t m20, m21, m22, m23;
  };
#endif
} i16m3x4s;

typedef union CGLM_ALIGN_MAT i16m4s {
  i16m4  raw;
  i16v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02, m03;
    int16_t m10, m11, m12, m13;
    int16_t m20, m21, m22, m23;
    int16_t m30, m31, m32, m33;
  };
#endif
} i16m4s;

typedef union i16m4x2s {
  i16m4x2 raw;
  i16v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01;
    int16_t m10, m11;
    int16_t m20, m21;
    int16_t m30, m31;
  };
#endif
} i16m4x2s;

typedef union i16m4x3s {
  i16m4x3 raw;
  i16v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int16_t m00, m01, m02;
    int16_t m10, m11, m12;
    int16_t m20, m21, m22;
    int16_t m30, m31, m32;
  };
#endif
} i16m4x3s;

/*----------------------------------------------*
 *           32-bit integer types               *
 *----------------------------------------------*/
typedef union i32v2s {
  i32v2 raw;
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
} i32v2s;

typedef union i32v3s {
  i32v3 raw;
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
} i32v3s;

typedef union i32v4s {
  i32v4 raw;
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
} i32v4s;

typedef union CGLM_ALIGN_IF(16) i32versors {
  i32v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
  };

  struct {
    i32v3s imag;
    int32_t    real;
  };
#endif
} i32versors;

typedef union i32m2s {
  i32m2  raw;
  i32v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
  };
#endif
} i32m2s;

typedef union i32m2x3s {
  i32m2x3 raw;
  i32v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
  };
#endif
} i32m2x3s;

typedef union i32m2x4s {
  i32m2x4 raw;
  i32v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
  };
#endif
} i32m2x4s;

typedef union i32m3s {
  i32m3  raw;
  i32v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
    int32_t m20, m21, m22;
  };
#endif
} i32m3s;

typedef union i32m3x2s {
  i32m3x2 raw;
  i32v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
    int32_t m20, m21;
  };
#endif
} i32m3x2s;

typedef union i32m3x4s {
  i32m3x4 raw;
  i32v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
    int32_t m20, m21, m22, m23;
  };
#endif
} i32m3x4s;

typedef union CGLM_ALIGN_MAT i32m4s {
  i32m4  raw;
  i32v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02, m03;
    int32_t m10, m11, m12, m13;
    int32_t m20, m21, m22, m23;
    int32_t m30, m31, m32, m33;
  };
#endif
} i32m4s;

typedef union i32m4x2s {
  i32m4x2 raw;
  i32v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01;
    int32_t m10, m11;
    int32_t m20, m21;
    int32_t m30, m31;
  };
#endif
} i32m4x2s;

typedef union i32m4x3s {
  i32m4x3 raw;
  i32v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int32_t m00, m01, m02;
    int32_t m10, m11, m12;
    int32_t m20, m21, m22;
    int32_t m30, m31, m32;
  };
#endif
} i32m4x3s;

typedef union u32v2s {
  u32v2 raw;
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
} u32v2s;

typedef union u32v3s {
  u32v3 raw;
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
} u32v3s;

typedef union u32v4s {
  u32v4 raw;
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
} u32v4s;

typedef union CGLM_ALIGN_IF(16) u32versors {
  u32v4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
  };

  struct {
    u32v3s imag;
    uint32_t    real;
  };
#endif
} u32versors;

typedef union u32m2s {
  u32m2  raw;
  u32v2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
  };
#endif
} u32m2s;

typedef union u32m2x3s {
  u32m2x3 raw;
  u32v3s  col[2]; /* [col (2), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
  };
#endif
} u32m2x3s;

typedef union u32m2x4s {
  u32m2x4 raw;
  u32v4s  col[2]; /* [col (2), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
  };
#endif
} u32m2x4s;

typedef union u32m3s {
  u32m3  raw;
  u32v3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
    uint32_t m20, m21, m22;
  };
#endif
} u32m3s;

typedef union u32m3x2s {
  u32m3x2 raw;
  u32v2s  col[3]; /* [col (3), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
    uint32_t m20, m21;
  };
#endif
} u32m3x2s;

typedef union u32m3x4s {
  u32m3x4 raw;
  u32v4s  col[3]; /* [col (3), row (4)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
    uint32_t m20, m21, m22, m23;
  };
#endif
} u32m3x4s;

typedef union CGLM_ALIGN_MAT u32m4s {
  u32m4  raw;
  u32v4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02, m03;
    uint32_t m10, m11, m12, m13;
    uint32_t m20, m21, m22, m23;
    uint32_t m30, m31, m32, m33;
  };
#endif
} u32m4s;

typedef union u32m4x2s {
  u32m4x2 raw;
  u32v2s  col[4]; /* [col (4), row (2)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01;
    uint32_t m10, m11;
    uint32_t m20, m21;
    uint32_t m30, m31;
  };
#endif
} u32m4x2s;

typedef union u32m4x3s {
  u32m4x3 raw;
  u32v3s  col[4]; /* [col (4), row (3)] */
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    uint32_t m00, m01, m02;
    uint32_t m10, m11, m12;
    uint32_t m20, m21, m22;
    uint32_t m30, m31, m32;
  };
#endif
} u32m4x3s;

#endif /* cglm_types_struct_h */
