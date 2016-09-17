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

#define glm__memset(type, dest, size, val)                                    \
  do {                                                                        \
    type *desti;                                                              \
    type *desti_end;                                                          \
                                                                              \
    desti     = (type *)dest;                                                 \
    desti_end = (type *)((char *)desti + size);                               \
                                                                              \
    while (desti != desti_end)                                                \
      *desti++ = val;                                                         \
  } while (0)

#define glm__memzero(type, dest, size) glm__memset(type, dest, size, 0)

#endif /* glm_common_h */
