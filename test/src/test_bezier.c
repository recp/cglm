/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

CGLM_INLINE
float
test_bezier_plain(float s, float p0, float c0, float c1, float p1) {
  float x, xx, xxx, ss, sss;

  x   = 1.0f - s;
  xx  = x * x;
  xxx = xx * x;
  ss  = s * s;
  sss = ss * s;

  return p0 * xxx + 3.0f * (c0 * s * xx + c1 * ss * x) + p1 * sss;
}

CGLM_INLINE
float
test_hermite_plain(float s, float p0, float t0, float t1, float p1) {
  float ss, sss;

  ss  = s  * s;
  sss = ss * s;

  return p0 * (2.0f * sss - 3.0f * ss + 1.0f)
       + t0 * (sss - 2.0f * ss + s)
       + p1 * (-2.0f * sss + 3.0f * ss)
       + t1 * (sss - ss);
}

TEST_IMPL(bezier) {
  float s, p0, p1, c0, c1, smc, Bs, Bs_plain;

  s        = test_rand();
  p0       = test_rand();
  p1       = test_rand();
  c0       = test_rand();
  c1       = test_rand();

  /* test cubic bezier */
  smc      = glm_smc(s, GLM_BEZIER_MAT, (vec4){p0, c0, c1, p1});
  Bs       = glm_bezier(s, p0, c0, c1, p1);
  Bs_plain = test_bezier_plain(s, p0, c0, c1, p1);

  ASSERT(test_eq(Bs,  Bs_plain));
  ASSERTIFY(test_assert_eqf(smc, Bs_plain))
  ASSERTIFY(test_assert_eqf(Bs,  smc))

  /* test cubic hermite */
  smc      = glm_smc(s, GLM_HERMITE_MAT, (vec4){p0, p1, c0, c1});
  Bs       = glm_hermite(s, p0, c0, c1, p1);
  Bs_plain = test_hermite_plain(s, p0, c0, c1, p1);

  ASSERT(test_eq(Bs,  Bs_plain));
  ASSERT(test_eq(smc, Bs_plain));
  ASSERT(test_eq(Bs,  smc));
  
  TEST_SUCCESS
}
