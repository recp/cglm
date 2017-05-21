/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_h
#define cglm_affine_h

#include "cglm-common.h"
#include "cglm-vec.h"
#include "cglm-affine-mat.h"
#include "cglm-util.h"

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

CGLM_INLINE
void
glm_translate_make(mat4 m, vec3 v) {
  mat4 t = GLM_MAT4_IDENTITY_INIT;
  glm_translate_to(t, v, m);
}

/* scale */

CGLM_INLINE
void
glm_scale_to(mat4 m, vec3 v, mat4 dest) {
  glm_vec4_scale(m[0], v[0], dest[0]);
  glm_vec4_scale(m[1], v[1], dest[1]);
  glm_vec4_scale(m[2], v[2], dest[2]);

  glm_vec4_copy(m[3], dest[3]);
}

CGLM_INLINE
void
glm_scale_make(mat4 m, vec3 v) {
  mat4 t = GLM_MAT4_IDENTITY_INIT;
  glm_scale_to(t, v, m);
}

CGLM_INLINE
void
glm_scale(mat4 m, vec3 v) {
  glm_scale_to(m, v, m);
}

CGLM_INLINE
void
glm_scale1(mat4 m, float s) {
  vec3 v = { s, s, s };
  glm_scale_to(m, v, m);
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

  glm_mat4_mul(m, t, dest);
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

  glm_mat4_mul(m, t, dest);
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

  glm_mat4_mul(m, t, dest);
}

CGLM_INLINE
void
glm_rotate_ndc_make(mat4 m, float angle, vec3 axis_ndc) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/glRotate.xml */

  vec3 v, vs;
  float c;

  c = cosf(angle);

  glm_vec_scale(axis_ndc, 1.0f - c, v);
  glm_vec_scale(axis_ndc, sinf(angle), vs);

  glm_vec_scale(axis_ndc, v[0], m[0]);
  glm_vec_scale(axis_ndc, v[1], m[1]);
  glm_vec_scale(axis_ndc, v[2], m[2]);

  m[0][0] += c;
  m[0][1] += vs[2];
  m[0][2] -= vs[1];

  m[1][0] -= vs[2];
  m[1][1] += c;
  m[1][2] += vs[0];

  m[2][0] += vs[1];
  m[2][1] -= vs[0];
  m[2][2] += c;

  m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
  m[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_rotate_make(mat4 m, float angle, vec3 axis) {
  vec3 axis_ndc;

  glm_vec_normalize_to(axis, axis_ndc);
  glm_rotate_ndc_make(m, angle, axis_ndc);
}

CGLM_INLINE
void
glm_rotate_ndc(mat4 m, float angle, vec3 axis_ndc) {
  mat4 rot, tmp;

  glm_rotate_ndc_make(rot, angle, axis_ndc);

  glm_vec4_scale(m[0], rot[0][0], tmp[1]);
  glm_vec4_scale(m[1], rot[0][1], tmp[0]);
  glm_vec4_add(tmp[1], tmp[0],    tmp[1]);
  glm_vec4_scale(m[2], rot[0][2], tmp[0]);
  glm_vec4_add(tmp[1], tmp[0],    tmp[1]);

  glm_vec4_scale(m[0], rot[1][0], tmp[2]);
  glm_vec4_scale(m[1], rot[1][1], tmp[0]);
  glm_vec4_add(tmp[2], tmp[0],    tmp[2]);
  glm_vec4_scale(m[2], rot[1][2], tmp[0]);
  glm_vec4_add(tmp[2], tmp[0],    tmp[2]);

  glm_vec4_scale(m[0], rot[2][0], tmp[3]);
  glm_vec4_scale(m[1], rot[2][1], tmp[0]);
  glm_vec4_add(tmp[3], tmp[0],    tmp[3]);
  glm_vec4_scale(m[2], rot[2][2], tmp[0]);
  glm_vec4_add(tmp[3], tmp[0],    tmp[3]);

  glm_vec4_copy(tmp[1], m[0]);
  glm_vec4_copy(tmp[2], m[1]);
  glm_vec4_copy(tmp[3], m[2]);
}

CGLM_INLINE
void
glm_rotate(mat4 m, float angle, vec3 axis) {
  vec3 axis_ndc;

  glm_vec_normalize_to(axis, axis_ndc);
  glm_rotate_ndc(m, angle, axis_ndc);
}

/*!
 * @brief decompose scale vector
 *
 * @param[in]  m     affine transform
 * @param[out] s     scale vector (Sx, Sy, Sz)
 */
CGLM_INLINE
void
glm_decompose_scalev(mat4 m, vec3 s) {
  s[0] = glm_vec_norm(m[0]);
  s[1] = glm_vec_norm(m[1]);
  s[2] = glm_vec_norm(m[2]);
}

/*!
 * @brief returns true if matrix is uniform scaled. This is helpful for 
 *        creating normal matrix.
 *
 * @param m[in] m
 *
 * @return boolean
 */
CGLM_INLINE
bool
glm_uniscaled(mat4 m) {
  vec3 s;
  glm_decompose_scalev(m, s);

  return glm_vec_eq_all(s);
}

/*!
 * @brief decompose rotation matrix (mat4) and scale vector [Sx, Sy, Sz]
 *        DON'T pass projected matrix here
 *
 * @param[in]  m affine transform
 * @param[out] r rotation matrix
 * @param[out] r scale matrix
 */
CGLM_INLINE
void
glm_decompose_rs(mat4 m, mat4 r, vec3 s) {
  vec4 t = {0.0f, 0.0f, 0.0f, 1.0f};
  vec3 v;

  glm_vec4_copy(m[0], r[0]);
  glm_vec4_copy(m[1], r[1]);
  glm_vec4_copy(m[2], r[2]);
  glm_vec4_copy(t,    r[3]);

  s[0] = glm_vec_norm(m[0]);
  s[1] = glm_vec_norm(m[1]);
  s[2] = glm_vec_norm(m[2]);

  glm_vec4_scale(r[0], 1.0f/s[0], r[0]);
  glm_vec4_scale(r[1], 1.0f/s[1], r[1]);
  glm_vec4_scale(r[2], 1.0f/s[2], r[2]);

  /* Note from Apple Open Source (asume that the matrix is orthonormal):
     check for a coordinate system flip.  If the determinant
     is -1, then negate the matrix and the scaling factors. */
  glm_vec_cross(m[0], m[1], v);
  if (glm_vec_dot(v, m[2]) < 0.0f) {
    glm_vec4_flipsign(r[0]);
    glm_vec4_flipsign(r[1]);
    glm_vec4_flipsign(r[2]);
    glm_vec_flipsign(s);
  }
}

/*!
 * @brief decompose affine transform, TODO: extract shear factors.
 *        DON'T pass projected matrix here
 *
 * @param[in]  m affine transfrom
 * @param[out] t translation vector
 * @param[out] r rotation matrix (mat4)
 * @param[out] s scaling vector [X, Y, Z]
 */
CGLM_INLINE
void
glm_decompose(mat4 m, vec4 t, mat4 r, vec3 s) {
  glm_vec4_copy(m[3], t);
  glm_decompose_rs(m, r, s);
}

#endif /* cglm_affine_h */
