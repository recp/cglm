/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_h
#define cglm_quat_h

#include "cglm.h"
#include "cglm-intrin.h"
#include <math.h>

CGLM_INLINE
float
glm_quat_dot(versor q, versor r) {
  return q[0] * r[0] + q[1] * r[1] + q[2] * r[2] + q[3] * r[3];
}

CGLM_INLINE
void
glm_quat_slerp(versor q,
               versor r,
               float  t,
               versor dest) {
  float cosTheta, sinTheta, angle, a, b, c;

#if defined( __SSE__ ) || defined( __SSE2__ )
  __m128 xmm_q;

  xmm_q = _mm_load_ps(q);

  cosTheta = glm_quat_dot(q, r);
  if (cosTheta < 0.0f) {
    _mm_store_ps(q,
                 _mm_xor_ps(xmm_q,
                            _mm_set1_ps(-0.f))) ;

    cosTheta = glm_quat_dot(q, r);
  }

  if (fabs(cosTheta) >= 1.0f) {
    _mm_store_ps(dest, xmm_q);
    return;
  }

  sinTheta = sqrt(1.0f - cosTheta * cosTheta);

  c = 1.0f - t;

  /* LERP */
  if (fabs(sinTheta) < 0.001f) {
    _mm_store_ps(dest, _mm_add_ps(_mm_mul_ps(_mm_set1_ps(c),
                                             xmm_q),
                                  _mm_mul_ps(_mm_set1_ps(t),
                                             _mm_load_ps(r))));
    return;
  }

  /* SLERP */
  angle = acos(cosTheta);
  a = sin(c * angle);
  b = sin(t * angle);

  _mm_store_ps(dest,
               _mm_div_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(a),
                                                xmm_q),
                                     _mm_mul_ps(_mm_set1_ps(b),
                                                _mm_load_ps(r))),
                          _mm_set1_ps(sinTheta)));
#else
  cosTheta = glm_quat_dot(q, r);
  if (cosTheta < 0.0f) {
    q[0] *= -1.0f;
    q[1] *= -1.0f;
    q[2] *= -1.0f;
    q[3] *= -1.0f;

    cosTheta = glm_quat_dot(q, r);
  }

  if (fabs(cosTheta) >= 1.0f) {
    dest[0] = q[0];
    dest[1] = q[1];
    dest[2] = q[2];
    dest[3] = q[3];

    return;
  }

  sinTheta = sqrt(1.0f - cosTheta * cosTheta);

  c = 1.0f - t;

  /* LERP */
  if (fabs(sinTheta) < 0.001f) {
    dest[0] = c * q[0] + t * r[0];
    dest[1] = c * q[1] + t * r[1];
    dest[2] = c * q[2] + t * r[2];
    dest[3] = c * q[3] + t * r[3];

    return;
  }

  /* SLERP */
  angle = acos(cosTheta);
  a = sin(c * angle);
  b = sin(t * angle);

  dest[0] = (q[0] * a + r[0] * b) / sinTheta;
  dest[1] = (q[1] * a + r[1] * b) / sinTheta;
  dest[2] = (q[2] * a + r[2] * b) / sinTheta;
  dest[3] = (q[3] * a + r[3] * b) / sinTheta;
#endif
}

#endif /* cglm_quat_h */
