/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_simd_h
#define cglm_quat_simd_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "../../cglm-common.h"
#include "cglm-intrin.h"

CGLM_INLINE
void
glm_quat_slerp_sse2(versor q,
                    versor r,
                    float  t,
                    versor dest) {
  /* https://en.wikipedia.org/wiki/Slerp */
  float cosTheta, sinTheta, angle, a, b, c;

  __m128 xmm_q;

  xmm_q = _mm_load_ps(q);

  cosTheta = glm_vec4_dot(q, r);
  if (cosTheta < 0.0f) {
    _mm_store_ps(q,
                 _mm_xor_ps(xmm_q,
                            _mm_set1_ps(-0.f))) ;

    cosTheta = -cosTheta;
  }

  if (cosTheta >= 1.0f) {
    _mm_store_ps(dest, xmm_q);
    return;
  }

  sinTheta = sqrtf(1.0f - cosTheta * cosTheta);

  c = 1.0f - t;

  /* LERP */
  if (sinTheta < 0.001f) {
    _mm_store_ps(dest, _mm_add_ps(_mm_mul_ps(_mm_set1_ps(c),
                                             xmm_q),
                                  _mm_mul_ps(_mm_set1_ps(t),
                                             _mm_load_ps(r))));
    return;
  }

  /* SLERP */
  angle = acosf(cosTheta);
  a = sinf(c * angle);
  b = sinf(t * angle);

  _mm_store_ps(dest,
               _mm_div_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(a),
                                                xmm_q),
                                     _mm_mul_ps(_mm_set1_ps(b),
                                                _mm_load_ps(r))),
                          _mm_set1_ps(sinTheta)));
}

#endif
#endif /* cglm_quat_simd_h */
