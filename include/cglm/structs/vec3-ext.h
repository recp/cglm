/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec3s_ext_h
#define cglm_vec3s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec3-ext.h"

CGLM_INLINE
vec3s
glms_vec3_broadcast(float val) {
  vec3s r;
  glm_vec3_broadcast(val, r.raw);
  return r;
}

CGLM_INLINE
bool
glms_vec3_eq(vec3s v, float val) {
  return glm_vec3_eq(v.raw, val);
}

CGLM_INLINE
bool
glms_vec3_eq_eps(vec3s v, float val) {
  return glm_vec3_eq_eps(v.raw, val);
}

CGLM_INLINE
bool
glms_vec3_eq_all(vec3s v) {
  return glm_vec3_eq_all(v.raw);
}

CGLM_INLINE
bool
glms_vec3_eqv(vec3s a, vec3s b) {
  return glm_vec3_eqv(a.raw, b.raw);
}

CGLM_INLINE
bool
glms_vec3_eqv_eps(vec3s a, vec3s b) {
  return glm_vec3_eqv_eps(a.raw, b.raw);
}

CGLM_INLINE
float
glms_vec3_max(vec3s v) {
  return glm_vec3_max(v.raw);
}

CGLM_INLINE
float
glms_vec3_min(vec3s v) {
  return glm_vec3_min(v.raw);
}

CGLM_INLINE
bool
glms_vec3_isnan(vec3s v) {
  return glm_vec3_isnan(v.raw);
}

CGLM_INLINE
bool
glms_vec3_isinf(vec3s v) {
  return glm_vec3_isinf(v.raw);
}

CGLM_INLINE
bool
glms_vec3_isvalid(vec3s v) {
  return glm_vec3_isvalid(v.raw);
}

CGLM_INLINE
vec3s
glms_vec3_sign(vec3s v) {
  vec3s r;
  glm_vec3_sign(v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec3_sqrt(vec3s v) {
  vec3s r;
  glm_vec3_sqrt(v.raw, r.raw);
  return r;
}

#endif /* cglm_vec3s_ext_h */
