/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_intrin_h
#define cglm_intrin_h

#include <xmmintrin.h>
#include <emmintrin.h>

/* float */
#define _mm_madd_ps(L, R0, R1)                                                \
   _mm_add_ps(_mm_mul_ps(_mm_set1_ps(*(L)), R0),                              \
              _mm_mul_ps(_mm_set1_ps(*(L + 1)), R1))

#define _mm_madd4_ps(L, R0, R1, R2, R3)                                       \
  _mm_add_ps(_mm_madd_ps(L, R0, R1),                                          \
             _mm_madd_ps(L + 2, R2, R3))

#endif /* cglm_intrin_h */
