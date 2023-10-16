/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_h
#define cglm_types_h

#if defined(_MSC_VER)
/* do not use alignment for older visual studio versions */
#  if _MSC_VER < 1913 /*  Visual Studio 2017 version 15.6  */
#    define CGLM_ALL_UNALIGNED
#    define CGLM_ALIGN(X) /* no alignment */
#  else
#    define CGLM_ALIGN(X) __declspec(align(X))
#  endif
#else
#  define CGLM_ALIGN(X) __attribute((aligned(X)))
#endif

#ifndef CGLM_ALL_UNALIGNED
#  define CGLM_ALIGN_IF(X) CGLM_ALIGN(X)
#else
#  define CGLM_ALIGN_IF(X) /* no alignment */
#endif

#ifdef __AVX__
#  define CGLM_ALIGN_MAT CGLM_ALIGN(32)
#else
#  define CGLM_ALIGN_MAT CGLM_ALIGN(16)
#endif

#ifndef CGLM_HAVE_BUILTIN_ASSUME_ALIGNED

#  if defined(__has_builtin)
#    if __has_builtin(__builtin_assume_aligned)
#      define CGLM_HAVE_BUILTIN_ASSUME_ALIGNED 1
#    endif
#  elif defined(__GNUC__) && defined(__GNUC_MINOR__)
#    if __GNUC__ >= 4 && __GNUC_MINOR__ >= 7
#      define CGLM_HAVE_BUILTIN_ASSUME_ALIGNED 1
#    endif
#  endif

#  ifndef CGLM_HAVE_BUILTIN_ASSUME_ALIGNED
#    define CGLM_HAVE_BUILTIN_ASSUME_ALIGNED 0
#  endif

#endif

#if CGLM_HAVE_BUILTIN_ASSUME_ALIGNED
#  define CGLM_ASSUME_ALIGNED(expr, alignment) \
     __builtin_assume_aligned((expr), (alignment))
#else
#  define CGLM_ASSUME_ALIGNED(expr, alignment) (expr)
#endif

#define CGLM_CASTPTR_ASSUME_ALIGNED(expr, type) \
  ((type*)CGLM_ASSUME_ALIGNED((expr), __alignof__(type)))

#define CGLM_INT_TYPE(bits) \
typedef int##bits##_t                          i##bits; \
typedef i##bits                                i##bits##v1[1]; \
typedef i##bits                                i##bits##v2[2]; \
typedef i##bits                                i##bits##v3[3]; \
typedef CGLM_ALIGN_IF(bits/8*4) i##bits        i##bits##v4[4]; \
\
typedef i##bits##v1                            i##bits##m1x1[1]; \
typedef i##bits##v2                            i##bits##m1x2[1]; \
typedef i##bits##v3                            i##bits##m1x3[1]; \
typedef i##bits##v4                            i##bits##m1x4[1]; \
typedef i##bits##m1x1                          i##bits##m1; \
\
typedef i##bits##v1                            i##bits##m2x1[2]; \
typedef CGLM_ALIGN_IF(bits/8*4) i##bits##v1    i##bits##v2x2[2]; \
typedef i##bits##v3                            i##bits##v2x3[2]; \
typedef i##bits##v4                            i##bits##v2x4[2]; \
typedef i##bits##v2x2                          i##bits##m2;      \
\
typedef i##bits##v1                            i##bits##m3x1[3]; \
typedef i##bits##v2                            i##bits##m3x2[3]; \
typedef i##bits##v3                            i##bits##m3x3[3]; \
typedef i##bits##v4                            i##bits##m3x4[3]; \
typedef i##bits##m3x3                          i##bits##m3; \
\
typedef i##bits##v1                            i##bits##m4x1[4]; \
typedef i##bits##v2                            i##bits##m4x2[4]; \
typedef i##bits##v3                            i##bits##m4x3[4]; \
typedef CGLM_ALIGN_IF(bits/8*16) i##bits##v4   i##bits##m4x4[4]; \
typedef i##bits##m4x4                          i##bits##m4; \
\
typedef i##bits##v4                            i##bits##versor; \
\
typedef uint##bits##_t                         u##bits; \
typedef u##bits                                u##bits##v1[1]; \
typedef u##bits                                u##bits##v2[2]; \
typedef u##bits                                u##bits##v3[3]; \
typedef CGLM_ALIGN_IF(bits/8*4) u##bits        u##bits##v4[4]; \
\
typedef u##bits##v1                            u##bits##m1x1[1]; \
typedef u##bits##v2                            u##bits##m1x2[1]; \
typedef u##bits##v3                            u##bits##m1x3[1]; \
typedef u##bits##v4                            u##bits##m1x4[1]; \
typedef u##bits##m1x1                          u##bits##m1; \
\
typedef u##bits##v1                            u##bits##m2x1[2]; \
typedef CGLM_ALIGN_IF(bits/8*4) u##bits##v2    u##bits##m2x2[2]; \
typedef u##bits##v3                            u##bits##m2x3[2]; \
typedef u##bits##v4                            u##bits##m2x4[2]; \
typedef u##bits##m2x2                          u##bits##m2; \
\
typedef u##bits##v1                            u##bits##m3x1[3]; \
typedef u##bits##v2                            u##bits##m3x2[3]; \
typedef u##bits##v3                            u##bits##m3x3[3]; \
typedef u##bits##v4                            u##bits##m3x4[3]; \
typedef u##bits##m3x3                          u##bits##m3; \
\
typedef u##bits##v1                            u##bits##m4x1[4]; \
typedef u##bits##v2                            u##bits##m4x2[4]; \
typedef u##bits##v3                            u##bits##m4x3[4]; \
typedef CGLM_ALIGN_IF(bits/8*16) u##bits##v4   u##bits##m4x4[4]; \
typedef u##bits##m4x4                          u##bits##m4; \
typedef u##bits##v4                            u##bits##versor;

#define CGLM_FLOAT_TYPE(type, bits) \
typedef type                                   f##bits##v1[1]; \
typedef type                                   f##bits##v2[2]; \
typedef type                                   f##bits##v3[3]; \
typedef CGLM_ALIGN_IF(bits/8*4) type           f##bits##v4[4]; \
\
typedef f##bits##v1                            f##bits##m1x1[1]; \
typedef f##bits##v2                            f##bits##m1x2[1]; \
typedef f##bits##v3                            f##bits##m1x3[1]; \
typedef f##bits##v4                            f##bits##m1x4[1]; \
typedef f##bits##m1x1                          f##bits##m1; \
\
typedef f##bits##v1                            f##bits##m2x1[2]; \
typedef CGLM_ALIGN_IF(bits/8*4) f##bits##v2    f##bits##m2x2[2]; \
typedef f##bits##v3                            f##bits##m2x3[2]; \
typedef f##bits##v4                            f##bits##m2x4[2]; \
typedef f##bits##m2x2                          f##bits##m2;      \
\
typedef f##bits##v1                            f##bits##m3x1[3]; \
typedef f##bits##v2                            f##bits##m3x2[3]; \
typedef f##bits##v3                            f##bits##m3x3[3]; \
typedef f##bits##v4                            f##bits##m3x4[3]; \
typedef f##bits##m3x3                          f##bits##m3; \
\
typedef f##bits##v1                            f##bits##m4x1[4]; \
typedef f##bits##v2                            f##bits##m4x2[4]; \
typedef f##bits##v3                            f##bits##m4x3[4]; \
typedef CGLM_ALIGN_IF(bits/8*16) f##bits##v4   f##bits##m4x4[4]; \
typedef f##bits##m4x4                          f##bits##m4; \
\
typedef f##bits##m4                            f##bits##versor;

CGLM_INT_TYPE(8)
CGLM_INT_TYPE(16)
CGLM_INT_TYPE(32)
CGLM_INT_TYPE(64)

CGLM_FLOAT_TYPE(float, 32)
CGLM_FLOAT_TYPE(double, 64)

/* define color format with N components and base type of [T]v[Tn] */
#define CGLM_COLOR_FORMAT(N, T, Tn) \
typedef struct T##v##Tn##c##N \
{ \
	union { \
		u8m3x##N raw; \
		struct { \
			u8v##N bits; \
			u8v##N colors; \
			u8v##N shift; \
		}; \
	}; \
	T##m##Tn##x##N mask; \
} T##v##Tn##c##N;

CGLM_COLOR_FORMAT(4, u8, 4)  /* RGBA8888  */
CGLM_COLOR_FORMAT(3, u8, 3)  /* RGB888    */
CGLM_COLOR_FORMAT(4, u16, 1) /* RGB4444   */
CGLM_COLOR_FORMAT(3, u16, 1) /* RGB565    */
CGLM_COLOR_FORMAT(4, f32, 4) /* RGBAF32C4 */
CGLM_COLOR_FORMAT(3, f32, 3) /* RGBAF32C3 */

/*
  Important: cglm stores quaternion as [x, y, z, w] in memory since v0.4.0 
  it was [w, x, y, z] before v0.4.0 ( v0.3.5 and earlier ). w is real part.
*/

#define GLM_E         2.71828182845904523536028747135266250   /* e           */
#define GLM_LOG2E     1.44269504088896340735992468100189214   /* log2(e)     */
#define GLM_LOG10E    0.434294481903251827651128918916605082  /* log10(e)    */
#define GLM_LN2       0.693147180559945309417232121458176568  /* loge(2)     */
#define GLM_LN10      2.30258509299404568401799145468436421   /* loge(10)    */
#define GLM_PI        3.14159265358979323846264338327950288   /* pi          */
#define GLM_PI_2      1.57079632679489661923132169163975144   /* pi/2        */
#define GLM_PI_4      0.785398163397448309615660845819875721  /* pi/4        */
#define GLM_1_PI      0.318309886183790671537767526745028724  /* 1/pi        */
#define GLM_2_PI      0.636619772367581343075535053490057448  /* 2/pi        */
#define GLM_2_SQRTPI  1.12837916709551257389615890312154517   /* 2/sqrt(pi)  */
#define GLM_SQRT2     1.41421356237309504880168872420969808   /* sqrt(2)     */
#define GLM_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2)   */

#define GLM_Ef        ((float)GLM_E)
#define GLM_LOG2Ef    ((float)GLM_LOG2E)
#define GLM_LOG10Ef   ((float)GLM_LOG10E)
#define GLM_LN2f      ((float)GLM_LN2)
#define GLM_LN10f     ((float)GLM_LN10)
#define GLM_PIf       ((float)GLM_PI)
#define GLM_PI_2f     ((float)GLM_PI_2)
#define GLM_PI_4f     ((float)GLM_PI_4)
#define GLM_1_PIf     ((float)GLM_1_PI)
#define GLM_2_PIf     ((float)GLM_2_PI)
#define GLM_2_SQRTPIf ((float)GLM_2_SQRTPI)
#define GLM_SQRT2f    ((float)GLM_SQRT2)
#define GLM_SQRT1_2f  ((float)GLM_SQRT1_2)

/* DEPRECATED! use GLM_PI and friends */
#define CGLM_PI       GLM_PIf
#define CGLM_PI_2     GLM_PI_2f
#define CGLM_PI_4     GLM_PI_4f

#endif /* cglm_types_h */
