/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_intrin_h
#define cglm_intrin_h
#if defined( __SSE__ ) || defined( __SSE2__ )
#include <xmmintrin.h>
#include <emmintrin.h>

/* float */
#define _mm_shuffle1_ps(a, z, y, x, w)                                        \
  _mm_shuffle_ps(a, a, _MM_SHUFFLE(z, y, x, w))

#define _mm_shuffle1_ps1(a, x)                                                \
  _mm_shuffle_ps(a, a, _MM_SHUFFLE(x, x, x, x))

#define _mm_shuffle2_ps(a, b, z0, y0, x0, w0, z1, y1, x1, w1)                 \
  _mm_shuffle1_ps(_mm_shuffle_ps(a, b, _MM_SHUFFLE(z0, y0, x0, w0)),          \
                  z1, y1, x1, w1);

#endif
#endif /* cglm_intrin_h */
