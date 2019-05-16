/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec3s_h
#define cglm_vec3s_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec3.h"
#include "vec3-ext.h"

#define GLMS_VEC3_ONE_INIT   {1.0f, 1.0f, 1.0f}
#define GLMS_VEC3_ZERO_INIT  {0.0f, 0.0f, 0.0f}

#define GLMS_VEC3_ONE  ((vec3s)GLMS_VEC3_ONE_INIT)
#define GLMS_VEC3_ZERO ((vec3s)GLMS_VEC3_ZERO_INIT)

#define GLMS_YUP  ((vec3s){0.0f, 1.0f, 0.0f})
#define GLMS_ZUP  ((vec3s){0.0f, 0.0f, 1.0f})
#define GLMS_XUP  ((vec3s){1.0f, 0.0f, 0.0f})

CGLM_INLINE
vec3s
glms_vec3(vec4s v4) {
  vec3s r;
  glm_vec3(v4.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_copy(vec3s v) {
  vec3s r;
  glm_vec3_copy(v.raw, r.raw);
  return r;
}

CGLM_INLINE
void
glms_vec3_pack(vec3s dst[], vec3 src[], size_t len) {
	size_t i;
	
	for (i = 0; i < len; i++) {
		dst[i].x = src[i][0];
		dst[i].y = src[i][1];
		dst[i].z = src[i][2];
	}
}

CGLM_INLINE
void
glms_vec3_unpack(vec3 dst[], vec3s src[], size_t len) {
	size_t i;

	for (i = 0; i < len; i++) {
		dst[i][0] = src[i].x;
		dst[i][1] = src[i].y;
		dst[i][2] = src[i].z;
	}	
}

CGLM_INLINE
vec3s
glms_vec3_zero() {
  vec3s r;
  glm_vec3_zero(r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_one() {
  vec3s r;
  glm_vec3_one(r.raw);
  return r;
}

CGLM_INLINE
float
glms_vec3_dot(vec3s a, vec3s b) {
  return glm_vec3_dot(a.raw, b.raw);
}

CGLM_INLINE
float
glms_vec3_norm2(vec3s v) {
  return glm_vec3_norm2(v.raw);
}

CGLM_INLINE
float
glms_vec3_norm(vec3s v) {
  return glm_vec3_norm(v.raw);
}

CGLM_INLINE
vec3s
glms_vec3_add(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_add(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_adds(vec3s a, float s) {
  vec3s r;
  glm_vec3_adds(a.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_sub(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_sub(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_subs(vec3s a, float s) {
  vec3s r;
  glm_vec3_subs(a.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_mul(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_mul(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_scale(vec3s v, float s) {
  vec3s r;
  glm_vec3_scale(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_scale_as(vec3s v, float s) {
  vec3s r;
  glm_vec3_scale_as(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_div(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_div(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_divs(vec3s a, float s) {
  vec3s r;
  glm_vec3_divs(a.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_addadd(vec3s a, vec3s b, vec3s dest) {
  glm_vec3_addadd(a.raw, b.raw, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_subadd(vec3s a, vec3s b, vec3s dest) {
  glm_vec3_subadd(a.raw, b.raw, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_muladd(vec3s a, vec3s b, vec3s dest) {
  glm_vec3_muladd(a.raw, b.raw, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_muladds(vec3s a, float s, vec3s dest) {
  glm_vec3_muladds(a.raw, s, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_maxadd(vec3s a, vec3s b, vec3s dest) {
  glm_vec3_maxadd(a.raw, b.raw, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_minadd(vec3s a, vec3s b, vec3s dest) {
  glm_vec3_minadd(a.raw, b.raw, dest.raw);
  return dest;
}

CGLM_INLINE
vec3s
glms_vec3_flipsign(vec3s v) {
  glm_vec3_flipsign(v.raw);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_negate(vec3s v) {
  glm_vec3_negate(v.raw);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_inv(vec3s v) {
  glm_vec3_inv(v.raw);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_normalize(vec3s v) {
  glm_vec3_normalize(v.raw);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_cross(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_cross(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_crossn(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_crossn(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
float
glms_vec3_distance(vec3s a, vec3s b) {
  return glm_vec3_distance(a.raw, b.raw);
}

CGLM_INLINE
float
glms_vec3_angle(vec3s a, vec3s b) {
  return glm_vec3_angle(a.raw, b.raw);
}

CGLM_INLINE
vec3s
glms_vec3_rotate(vec3s v, float angle, vec3s axis) {
  glm_vec3_rotate(v.raw, angle, axis.raw);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_rotate_m4(mat4s m, vec3s v) {
  vec3s r;
  glm_vec3_rotate_m4(m.raw, v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_rotate_m3(mat3s m, vec3s v) {
  vec3s r;
  glm_vec3_rotate_m3(m.raw, v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_proj(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_proj(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_center(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_center(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
float
glms_vec3_distance2(vec3s a, vec3s b) {
  return glm_vec3_distance2(a.raw, b.raw);
}

CGLM_INLINE
vec3s
glms_vec3_maxv(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_maxv(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_minv(vec3s a, vec3s b) {
  vec3s r;
  glm_vec3_minv(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_ortho(vec3s v) {
  vec3s r;
  glm_vec3_ortho(v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_clamp(vec3s v, float minVal, float maxVal) {
  glm_vec3_clamp(v.raw, minVal, maxVal);
  return v;
}

CGLM_INLINE
vec3s
glms_vec3_lerp(vec3s from, vec3s to, float t) {
  vec3s r;
  glm_vec3_lerp(from.raw, to.raw, t, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_cross(vec3s a, vec3s b) {
  vec3s r;
  glm_cross(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
float
glms_dot(vec3s a, vec3s b) {
  return glm_dot(a.raw, b.raw);
}

CGLM_INLINE
vec3s
glms_normalize(vec3s v) {
  glm_normalize(v.raw);
  return v;
}

#endif /* cglm_vec3s_h */
