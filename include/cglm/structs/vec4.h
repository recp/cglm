/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec4s_h
#define cglm_vec4s_h

#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

#define GLMS_VEC4_ONE_INIT   {1.0f, 1.0f, 1.0f, 1.0f}
#define GLMS_VEC4_BLACK_INIT {0.0f, 0.0f, 0.0f, 1.0f}
#define GLMS_VEC4_ZERO_INIT  {0.0f, 0.0f, 0.0f, 0.0f}

#define GLMS_VEC4_ONE        ((vec4s)GLM_VEC4_ONE_INIT)
#define GLMS_VEC4_BLACK      ((vec4s)GLM_VEC4_BLACK_INIT)
#define GLMS_VEC4_ZERO       ((vec4s)GLM_VEC4_ZERO_INIT)

CGLM_INLINE
vec4s
glms_vec4(vec3s v3, float last)
{
  vec4s r;
  glm_vec4(v3.raw, last, r.raw);
  return r;
}

CGLM_INLINE
vec3s
glms_vec4_copy3(vec4s v)
{
  vec3s r;
  glm_vec4_copy3(v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_copy(vec4s v)
{
  vec4s r;
  glm_vec4_copy(v.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_ucopy(vec4s v)
{
  vec4s r;
  glm_vec4_ucopy(v.raw, r.raw);
  return r;
}


CGLM_INLINE
float
glms_vec4_dot(vec4s a, vec4s b)
{
  return glm_vec4_dot(a.raw, b.raw);
}

CGLM_INLINE
float
glms_vec4_norm2(vec4s v)
{
  return glm_vec4_norm2(v.raw);
}

CGLM_INLINE
float
glms_vec4_norm(vec4s v)
{
  return glm_vec4_norm(v.raw);
}

CGLM_INLINE
vec4s
glms_vec4_add(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_add(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_adds(vec4s v, float s)
{
  vec4s r;
  glm_vec4_adds(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_sub(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_sub(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_subs(vec4s v, float s)
{
  vec4s r;
  glm_vec4_subs(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_mul(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_mul(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_scale(vec4s v, float s)
{
  vec4s r;
  glm_vec4_scale(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_scale_as(vec4s v, float s)
{
  vec4s r;
  glm_vec4_scale_as(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_div(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_div(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_divs(vec4s v, float s)
{
  vec4s r;
  glm_vec4_divs(v.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_addadd(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_addadd(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_subadd(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_subadd(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_muladd(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_muladd(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_muladds(vec4s a, float s)
{
  vec4s r;
  glm_vec4_muladds(a.raw, s, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_maxadd(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_maxadd(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_minadd(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_minadd(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_negate(vec4s v)
{
  glm_vec4_negate(v.raw);
  return v;
}

CGLM_INLINE
vec4s
glms_vec4_inv(vec4s v)
{
  glm_vec4_inv(v.raw);
  return v;
}

CGLM_INLINE
vec4s
glms_vec4_normalize(vec4s v)
{
  glm_vec4_normalize(v.raw);
  return v;
}

CGLM_INLINE
float
glms_vec4_distance(vec4s a, vec4s b)
{
  return glm_vec4_distance(a.raw, b.raw);
}

CGLM_INLINE
vec4s
glms_vec4_maxv(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_maxv(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_minv(vec4s a, vec4s b)
{
  vec4s r;
  glm_vec4_minv(a.raw, b.raw, r.raw);
  return r;
}

CGLM_INLINE
vec4s
glms_vec4_clamp(vec4s v, float minVal, float maxVal)
{
  glm_vec4_clamp(v.raw, minVal, maxVal);
  return v;
}

CGLM_INLINE
vec4s
glms_vec4_lerp(vec4s from, vec4s to, float t)
{
  vec4s r;
  glm_vec4_lerp(from.raw, to.raw, t, r.raw);
  return r;
}

#ifdef __cplusplus
}
#endif
#endif /* cglm_vec4s_h */
