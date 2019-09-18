/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/* test inline mat4 */

#define GLM_PREFIX glm_
#define GLM(X) (glm_ ## X)

#include "test_mat4.h"

#undef GLM
#undef GLM_PREFIX

/* test pre-compiled mat4 */

#define GLM_PREFIX glmc_
#define GLM(X) (glmc_ ## X)

#include "test_mat4.h"

#undef GLM
#undef GLM_PREFIX
