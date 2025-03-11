/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_h
#define cglm_types_h

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
# include <stdalign.h>
#endif

#if defined(_MSC_VER)
/* do not use alignment for older visual studio versions */
/* also ARM32 also causes similar error, disable it for now on ARM32 too */
#  if _MSC_VER < 1913 || _M_ARM /*  Visual Studio 2017 version 15.6  */
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

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
# define CGLM_CASTPTR_ASSUME_ALIGNED(expr, type) \
   ((type*)CGLM_ASSUME_ALIGNED((expr), alignof(type)))
#elif defined(_MSC_VER)
# define CGLM_CASTPTR_ASSUME_ALIGNED(expr, type) \
   ((type*)CGLM_ASSUME_ALIGNED((expr), __alignof(type)))
#else
# define CGLM_CASTPTR_ASSUME_ALIGNED(expr, type) \
   ((type*)CGLM_ASSUME_ALIGNED((expr), __alignof__(type)))
#endif

typedef int                     ivec2[2];
typedef int                     ivec3[3];
typedef int                     ivec4[4];

typedef float                   vec2[2];
typedef float                   vec3[3];
typedef CGLM_ALIGN_IF(16) float vec4[4];
typedef vec4                    versor;     /* |x, y, z, w| -> w is the last */
typedef vec3                    mat3[3];
typedef vec2                    mat3x2[3];  /* [col (3), row (2)] */
typedef vec4                    mat3x4[3];  /* [col (3), row (4)] */
typedef CGLM_ALIGN_IF(16) vec2  mat2[2];
typedef vec3                    mat2x3[2];  /* [col (2), row (3)] */
typedef vec4                    mat2x4[2];  /* [col (2), row (4)] */
typedef CGLM_ALIGN_MAT    vec4  mat4[4];
typedef vec2                    mat4x2[4];  /* [col (4), row (2)] */
typedef vec3                    mat4x3[4];  /* [col (4), row (3)] */

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
#define GLM_TAU       6.283185307179586476925286766559005768  /* tau         */
#define GLM_TAU_2     GLM_PI                                  /* tau/2       */
#define GLM_TAU_4     GLM_PI_2                                /* tau/4       */
#define GLM_1_TAU     0.159154943091895335768883763372514362  /* 1/tau       */
#define GLM_2_TAU     0.318309886183790671537767526745028724  /* 2/tau       */
#define GLM_2_SQRTPI  1.12837916709551257389615890312154517   /* 2/sqrt(pi)  */
#define GLM_SQRTTAU   2.506628274631000502415765284811045253  /* sqrt(tau)   */
#define GLM_SQRT2     1.41421356237309504880168872420969808   /* sqrt(2)     */
#define GLM_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2)   */

#define GLM_Ef         ((float)GLM_E)
#define GLM_LOG2Ef     ((float)GLM_LOG2E)
#define GLM_LOG10Ef    ((float)GLM_LOG10E)
#define GLM_LN2f       ((float)GLM_LN2)
#define GLM_LN10f      ((float)GLM_LN10)
#define GLM_PIf        ((float)GLM_PI)
#define GLM_PI_2f      ((float)GLM_PI_2)
#define GLM_PI_4f      ((float)GLM_PI_4)
#define GLM_1_PIf      ((float)GLM_1_PI)
#define GLM_2_PIf      ((float)GLM_2_PI)
#define GLM_TAUf       ((float)GLM_TAU)
#define GLM_TAU_2f     ((float)GLM_TAU_2)
#define GLM_TAU_4f     ((float)GLM_TAU_4)
#define GLM_1_TAUf     ((float)GLM_1_TAU)
#define GLM_2_TAUf     ((float)GLM_2_TAU)
#define GLM_2_SQRTPIf  ((float)GLM_2_SQRTPI)
#define GLM_2_SQRTTAUf ((float)GLM_SQRTTAU)
#define GLM_SQRT2f     ((float)GLM_SQRT2)
#define GLM_SQRT1_2f   ((float)GLM_SQRT1_2)

/* DEPRECATED! use GLM_PI and friends */
#define CGLM_PI       GLM_PIf
#define CGLM_PI_2     GLM_PI_2f
#define CGLM_PI_4     GLM_PI_4f

#endif /* cglm_types_h */
