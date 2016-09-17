/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef glm_common_h
#define glm_common_h

#include <stdint.h>

#if defined(_WIN32)
#  define CGLM_INLINE __forceinline
#  define CGLM_ALIGN(X) __declspec(align(X))
#else
#  define CGLM_INLINE static inline __attribute((always_inline))
#  define CGLM_ALIGN(X) __attribute((aligned(X)))
#endif

#define glm__memcpy(type, dest, src, size)                                    \
  do {                                                                        \
    type *srci;                                                               \
    type *srci_end;                                                           \
    type *desti;                                                              \
                                                                              \
    srci     = (type *)src;                                                   \
    srci_end = (type *)((char *)srci + size);                                 \
    desti    = (type *)dest;                                                  \
                                                                              \
    while (srci != srci_end)                                                  \
      *desti++ = *srci++;                                                     \
  } while (0)

#define glm__memzero(dest, size)                                              \
  do {                                                                        \
    int32_t *desti;                                                           \
    int32_t *desti_end;                                                       \
                                                                              \
    desti     = (int32_t *)dest;                                              \
    desti_end = (int32_t *)((char *)desti + size);                            \
                                                                              \
    while (desti != desti_end)                                                \
      *desti++ = 0;                                                           \
  } while (0)

#endif /* glm_common_h */
