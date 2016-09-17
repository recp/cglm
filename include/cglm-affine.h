/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_h
#define cglm_affine_h

#include "cglm.h"
#include "cglm-vec.h"
#include <math.h>

CGLM_INLINE
void
glm_translate_to(mat4 m, vec3 v, mat4 dest) {
  mat4 t = GLM_MAT4_IDENTITY_INIT;

#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest[3],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps(t[0]),
                                                _mm_set1_ps(v[0])),
                                     _mm_mul_ps(_mm_load_ps(t[1]),
                                                _mm_set1_ps(v[1]))),
                          _mm_add_ps(_mm_mul_ps(_mm_load_ps(t[2]),
                                                _mm_set1_ps(v[2])),
                                     _mm_load_ps(t[3]))))
  ;

  _mm_store_ps(dest[0], _mm_load_ps(m[0]));
  _mm_store_ps(dest[1], _mm_load_ps(m[1]));
  _mm_store_ps(dest[2], _mm_load_ps(m[2]));
#else
  vec4 v1, v2, v3;

  glm_vec4_scale(t[0], v[0], v1);
  glm_vec4_scale(t[1], v[1], v2);
  glm_vec4_scale(t[2], v[2], v3);

  glm_vec4_add(v1, t[3], t[3]);
  glm_vec4_add(v2, t[3], t[3]);
  glm_vec4_add(v3, t[3], t[3]);

  glm__memcpy(float, dest, t, sizeof(mat4));
#endif
}

CGLM_INLINE
void
glm_translate(mat4 m, vec3 v) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(m[3],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps(m[0]),
                                                _mm_set1_ps(v[0])),
                                     _mm_mul_ps(_mm_load_ps(m[1]),
                                                _mm_set1_ps(v[1]))),
                          _mm_add_ps(_mm_mul_ps(_mm_load_ps(m[2]),
                                                _mm_set1_ps(v[2])),
                                     _mm_load_ps(m[3]))))
  ;
#else
  vec4 v1, v2, v3;

  glm_vec4_scale(m[0], v[0], v1);
  glm_vec4_scale(m[1], v[1], v2);
  glm_vec4_scale(m[2], v[2], v3);

  glm_vec4_add(v1, m[3], m[3]);
  glm_vec4_add(v2, m[3], m[3]);
  glm_vec4_add(v3, m[3], m[3]);
#endif
}

CGLM_INLINE
void
glm_translate_x(mat4 m, float to) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(m[3],
               _mm_add_ps(_mm_mul_ps(_mm_load_ps(m[0]),
                                     _mm_set1_ps(to)),
                          _mm_load_ps(m[3])))
  ;
#else
  vec4 v1;
  glm_vec4_scale(m[0], to, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

CGLM_INLINE
void
glm_translate_y(mat4 m, float to) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(m[3],
               _mm_add_ps(_mm_mul_ps(_mm_load_ps(m[1]),
                                     _mm_set1_ps(to)),
                          _mm_load_ps(m[3])))
  ;
#else
  vec4 v1;
  glm_vec4_scale(m[1], to, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

CGLM_INLINE
void
glm_translate_z(mat4 m, float to) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(m[3],
               _mm_add_ps(_mm_mul_ps(_mm_load_ps(m[2]),
                                     _mm_set1_ps(to)),
                          _mm_load_ps(m[3])))
  ;
#else
  vec4 v1;
  glm_vec4_scale(m[2], to, v1);
  glm_vec4_add(v1, m[3], m[3]);
#endif
}

/* scale */

CGLM_INLINE
void
glm_scale_to(mat4 m, vec3 v, mat4 dest) {
  glm_vec4_scale(m[0], v[0], dest[0]);
  glm_vec4_scale(m[1], v[1], dest[1]);
  glm_vec4_scale(m[2], v[2], dest[2]);

  glm_vec4_dup(m[3], dest[3]);
}

CGLM_INLINE
void
glm_scale(mat4 m, vec3 v) {
  glm_scale_to(m, v, m);
}

CGLM_INLINE
void
glm_scale1(mat4 m, float s) {
  glm_scale_to(m, (vec3){s, s, s}, m);
}

CGLM_INLINE
void
glm_rotate_x(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT4_IDENTITY_INIT;

  cosVal = cosf(rad);
  sinVal = sinf(rad);

  t[1][1] =  cosVal;
  t[1][2] =  sinVal;
  t[2][1] = -sinVal;
  t[2][2] =  cosVal;

  glm_mat4_mul(t, m, dest);
}

CGLM_INLINE
void
glm_rotate_y(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT4_IDENTITY_INIT;

  cosVal = cosf(rad);
  sinVal = sinf(rad);

  t[0][0] =  cosVal;
  t[0][2] = -sinVal;
  t[2][0] =  sinVal;
  t[2][2] =  cosVal;

  glm_mat4_mul(t, m, dest);
}

CGLM_INLINE
void
glm_rotate_z(mat4 m, float rad, mat4 dest) {
  float cosVal;
  float sinVal;
  mat4  t = GLM_MAT4_IDENTITY_INIT;

  cosVal = cosf(rad);
  sinVal = sinf(rad);

  t[0][0] =  cosVal;
  t[0][1] =  sinVal;
  t[1][0] = -sinVal;
  t[1][1] =  cosVal;

  glm_mat4_mul(t, m, dest);
}

#endif /* cglm_affine_h */
