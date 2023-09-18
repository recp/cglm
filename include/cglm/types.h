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

/*----------------------------------------------*
 *             8-bit integer types              *
 *----------------------------------------------*/
typedef int8_t                     bvec1[1];
typedef int8_t                     bvec2[2];
typedef int8_t                     bvec3[3];
typedef CGLM_ALIGN_IF(4) int8_t    bvec4[4];

typedef bvec1                      bmat1x1[1]; 
typedef bvec2                      bmat1x2[1];
typedef bvec3                      bmat1x3[1];
typedef bvec4                      bmat1x4[1];
typedef bmat1x1                    bmat1;

typedef bvec1                      bmat2x1[2];
typedef CGLM_ALIGN_IF(4) bvec2     bmat2x2[2];
typedef bvec3                      bmat2x3[2];  /* [col (2), row (3)] */
typedef bvec4                      bmat2x4[2];  /* [col (2), row (4)] */
typedef bmat2x2                    bmat2;

typedef bvec1                      bmat3x1[3];
typedef bvec2                      bmat3x2[3];  /* [col (3), row (2)] */
typedef bvec3                      bmat3x3[3];
typedef bvec4                      bmat3x4[3];  /* [col (3), row (4)] */
typedef bmat3x3                    bmat3;

typedef bvec1                      bmat4x1[4]; 
typedef bvec2                      bmat4x2[4];  /* [col (4), row (2)] */
typedef bvec3                      bmat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_MAT bvec4       bmat4x4[4];
typedef bmat4x4                    bmat4;
typedef bvec4                      bversor;     /* |x, y, z, w| -> w is the last */

typedef uint8_t                    ubvec1[1];
typedef uint8_t                    ubvec2[2];
typedef uint8_t                    ubvec3[3];
typedef CGLM_ALIGN_IF(4) uint8_t   ubvec4[4];

typedef ubvec1                     ubmat1x1[1]; 
typedef ubvec2                     ubmat1x2[1];
typedef ubvec3                     ubmat1x3[1];
typedef ubvec4                     ubmat1x4[1];
typedef ubmat1x1                   ubmat1;

typedef ubvec1                     ubmat2x1[2];
typedef CGLM_ALIGN_IF(4) ubvec2    ubmat2x2[2];
typedef ubvec3                     ubmat2x3[2];  /* [col (2), row (3)] */
typedef ubvec4                     ubmat2x4[2];  /* [col (2), row (4)] */
typedef ubmat2x2                   ubmat2;

typedef ubvec1                     ubmat3x1[3];
typedef ubvec2                     ubmat3x2[3];  /* [col (3), row (2)] */
typedef ubvec3                     ubmat3x3[3];
typedef ubvec4                     ubmat3x4[3];  /* [col (3), row (4)] */
typedef ubmat3x3                   ubmat3;

typedef ubvec1                     ubmat4x1[4];
typedef ubvec2                     ubmat4x2[4];  /* [col (4), row (2)] */
typedef ubvec3                     ubmat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_IF(16) ubvec4   ubmat4x4[4];
typedef ubmat4x4                   ubmat4;
typedef ubvec4                     ubversor;     /* |x, y, z, w| -> w is the last */

/*----------------------------------------------*
 *           16-bit integer types               *
 *----------------------------------------------*/
typedef int16_t                    hvec1[1];
typedef int16_t                    hvec2[2];
typedef int16_t                    hvec3[3];
typedef CGLM_ALIGN_IF(8) int16_t   hvec4[4];

typedef hvec1                      hmat1x1[1]; 
typedef hvec2                      hmat1x2[1];
typedef hvec3                      hmat1x3[1];
typedef hvec4                      hmat1x4[1];
typedef hmat1x1                    hmat1;

typedef hvec1                      hmat2x1[2];
typedef CGLM_ALIGN_IF(8) hvec2     hmat2x2[2];
typedef hvec3                      hmat2x3[2];  /* [col (2), row (3)] */
typedef hvec4                      hmat2x4[2];  /* [col (2), row (4)] */
typedef hmat2x2                    hmat2;

typedef hvec1                      hmat3x1[3];
typedef hvec2                      hmat3x2[3];  /* [col (3), row (2)] */
typedef hvec3                      hmat3x3[3];
typedef hvec4                      hmat3x4[3];  /* [col (3), row (4)] */
typedef hmat3x3                    hmat3;

typedef hvec1                      hmat4x1[4]; 
typedef hvec2                      hmat4x2[4];  /* [col (4), row (2)] */
typedef hvec3                      hmat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_IF(32) hvec4    hmat4x4[4];
typedef hmat4x4                    hmat4;
typedef hvec4                      hversor;     /* |x, y, z, w| -> w is the last */

typedef uint16_t                   uhvec1[1];
typedef uint16_t                   uhvec2[2];
typedef uint16_t                   uhvec3[3];
typedef CGLM_ALIGN_IF(8) uint16_t  uhvec4[4];

typedef uhvec1                     uhmat1x1[1]; 
typedef uhvec2                     uhmat1x2[1];
typedef uhvec3                     uhmat1x3[1];
typedef uhvec4                     uhmat1x4[1];
typedef uhmat1x1                   uhmat1;

typedef uhvec1                     uhmat2x1[2];
typedef CGLM_ALIGN_IF(8) uhvec2    uhmat2x2[2];
typedef uhvec3                     uhmat2x3[2];  /* [col (2), row (3)] */
typedef uhvec4                     uhmat2x4[2];  /* [col (2), row (4)] */
typedef uhmat2x2                   uhmat2;

typedef uhvec1                     uhmat3x1[3];
typedef uhvec2                     uhmat3x2[3];  /* [col (3), row (2)] */
typedef uhvec3                     uhmat3x3[3];
typedef uhvec4                     uhmat3x4[3];  /* [col (3), row (4)] */
typedef uhmat3x3                   uhmat3;

typedef uhvec1                     uhmat4x1[4]; 
typedef uhvec2                     uhmat4x2[4];  /* [col (4), row (2)] */
typedef uhvec3                     uhmat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_IF(16) uhvec4   uhmat4x4[4];
typedef uhmat4x4                   uhmat4;
typedef uhvec4                     uhversor;     /* |x, y, z, w| -> w is the last */

/*----------------------------------------------*
 *           32-bit integer types               *
 *----------------------------------------------*/
typedef int32_t                    ivec1[1];
typedef int32_t                    ivec2[2];
typedef int32_t                    ivec3[3];
typedef CGLM_ALIGN_IF(16) int32_t  ivec4[4];

typedef ivec1                      imat1x1[1]; 
typedef ivec2                      imat1x2[1];
typedef ivec3                      imat1x3[1];
typedef ivec4                      imat1x4[1];
typedef imat1x1                    imat1;

typedef ivec1                      imat2x1[2];
typedef CGLM_ALIGN_IF(16) ivec2    imat2x2[2];
typedef ivec3                      imat2x3[2];  /* [col (2), row (3)] */
typedef ivec4                      imat2x4[2];  /* [col (2), row (4)] */
typedef imat2x2                    imat2;

typedef ivec1                      imat3x1[3];
typedef ivec2                      imat3x2[3];  /* [col (3), row (2)] */
typedef ivec3                      imat3x3[3];
typedef ivec4                      imat3x4[3];  /* [col (3), row (4)] */
typedef imat3x3                    imat3;

typedef ivec1                      imat4x1[4];
typedef ivec2                      imat4x2[4];  /* [col (4), row (2)] */
typedef ivec3                      imat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_MAT ivec4       imat4x4[4];
typedef imat4x4                    imat4;
typedef ivec4                      iversor;     /* |x, y, z, w| -> w is the last */

typedef uint32_t                   uvec1[1];
typedef uint32_t                   uvec2[2];
typedef uint32_t                   uvec3[3];
typedef CGLM_ALIGN_IF(16) uint32_t uvec4[4];

typedef uvec1                      umat1x1[1]; 
typedef uvec2                      umat1x2[1];
typedef uvec3                      umat1x3[1];
typedef uvec4                      umat1x4[1];
typedef umat1x1                    umat1;

typedef uvec1                      umat2x1[2];
typedef CGLM_ALIGN_IF(16) uvec2    umat2x2[2];
typedef uvec3                      umat2x3[2];  /* [col (2), row (3)] */
typedef uvec4                      umat2x4[2];  /* [col (2), row (4)] */
typedef umat2x2                    umat2;

typedef uvec1                      umat3x1[3];
typedef uvec2                      umat3x2[3];  /* [col (3), row (2)] */
typedef uvec3                      umat3x3[3];
typedef uvec4                      umat3x4[3];  /* [col (3), row (4)] */
typedef umat3x3                    umat3;

typedef uvec1                      umat4x1[4]; 
typedef uvec2                      umat4x2[4];  /* [col (4), row (2)] */
typedef uvec3                      umat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_MAT uvec4       umat4x4[4];
typedef umat4x4                    umat4;
typedef uvec4                      uversor;     /* |x, y, z, w| -> w is the last */

/*----------------------------------------------*
 *     single-precision floating-point types    *
 *----------------------------------------------*/
typedef float                     vec1[1];
typedef float                     vec2[2];
typedef float                     vec3[3];
typedef CGLM_ALIGN_IF(16) float   vec4[4];

typedef vec1                      mat1x1[1]; 
typedef vec2                      mat1x2[1];
typedef vec3                      mat1x3[1];
typedef vec4                      mat1x4[1];
typedef mat1x1                    mat1;

typedef vec1                      mat2x1[2];
typedef CGLM_ALIGN_IF(16) vec2    mat2x2[2];
typedef vec3                      mat2x3[2];  /* [col (2), row (3)] */
typedef vec4                      mat2x4[2];  /* [col (2), row (4)] */
typedef mat2x2                    mat2;

typedef vec1                      mat3x1[3];
typedef vec2                      mat3x2[3];  /* [col (3), row (2)] */
typedef vec3                      mat3x3[3];
typedef vec4                      mat3x4[3];  /* [col (3), row (4)] */
typedef mat3x3                    mat3;

typedef vec1                      mat4x1[4];
typedef vec2                      mat4x2[4];  /* [col (4), row (2)] */
typedef vec3                      mat4x3[4];  /* [col (4), row (3)] */
typedef CGLM_ALIGN_MAT vec4       mat4x4[4];
typedef mat4x4                    mat4;
typedef vec4                      versor;     /* |x, y, z, w| -> w is the last */

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

/* define color format with N components and base type of [T]vec[Tn] */
#define CGLM_COLOR_FORMAT(N, T, Tn) \
typedef struct T##vec##Tn##c##N \
{ \
	union { \
		ubmat3x##N raw; \
		struct { \
			ubvec##N bits; \
			ubvec##N colors; \
			ubvec##N shift; \
		}; \
	}; \
	T##mat##Tn##x##N mask; \
} T##vec##Tn##c##N;

CGLM_COLOR_FORMAT(4, uh, 1);
CGLM_COLOR_FORMAT(3, uh, 1);
CGLM_COLOR_FORMAT(4, ub, 4);
CGLM_COLOR_FORMAT(3, ub, 3);
CGLM_COLOR_FORMAT(4,   , 4);
CGLM_COLOR_FORMAT(3,   , 3);

#endif /* cglm_types_h */
