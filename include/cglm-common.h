/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef glm_common_h
#define glm_common_h

#if defined(_WIN32)
#  define CGLM_INLINE __forceinline
#else
#  define CGLM_INLINE static inline __attribute((always_inline))
#endif

#endif /* glm_common_h */
