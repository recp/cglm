/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec4s_ext_h
#define cglm_vec4s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec4-ext.h"

CGLM_INLINE
vec4s
glms_vec4_broadcast(float val) {
  vec4s r;
  glm_vec4_broadcast(val, r.raw);
  return r;
}

CGLM_INLINE
bool
glms_vec4_eq(vec4s v, float val) {
  return glm_vec4_eq(v.raw, val);
}

CGLM_INLINE
bool
glms_vec4_eq_eps(vec4s v, float val) {
  return glm_vec4_eq_eps(v.raw, val);
}

CGLM_INLINE
bool
glms_vec4_eq_all(vec4s v) {
  return glm_vec4_eq_all(v.raw);
}

CGLM_INLINE
bool
glms_vec4_eqv(vec4s a, vec4s b) {
  return glm_vec4_eqv(a.raw, b.raw);
}

CGLM_INLINE
bool
glms_vec4_eqv_eps(vec4s a, vec4s b) {
  return glm_vec4_eqv_eps(a.raw, b.raw);
}

CGLM_INLINE
float
glms_vec4_max(vec4s v) {
  return glm_vec4_max(v.raw);
}

CGLM_INLINE
float
glms_vec4_min(vec4s v) {
  return glm_vec4_min(v.raw);
}

CGLM_INLINE
bool
glms_vec4_isnan(vec4s v) {
  return glm_vec4_isnan(v.raw);
}

CGLM_INLINE
bool
glms_vec4_isinf(vec4s v) {
  return glm_vec4_isinf(v.raw);
}

CGLM_INLINE
bool
glms_vec4_isvalid(vec4s v) {
  return glm_vec4_isvalid(v.raw);
}

CGLM_INLINE
vec4s
glms_vec4_sign(vec4s v) {
  vec4s r;
  glm_vec4_sign(v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_sqrt(vec4s v) {
  vec4s r;
  glm_vec4_sqrt(v.raw, r.raw);
  return r;
}

#endif /* cglm_vec4s_ext_h */
