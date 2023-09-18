/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_color_h
#define cglm_color_h

#include "cglm/common.h"

uhvec1c4 RGB4444   = { .bits={ 4, 4, 4, 4 }     , .colors={0, 1, 2 }    };
uhvec1c3 RGB565    = { .bits={ 5, 6, 5 }        , .colors={0, 1, 2 }    };
ubvec4c4 RGBA8888  = { .bits={ 8, 8, 8, 8 }     , .colors={0, 1, 2, 3 } };
ubvec4c4 ARGB8888  = { .bits={ 8, 8, 8, 8 }     , .colors={3, 0, 1, 2 } };
ubvec4c4 BGRA8888  = { .bits={ 8, 8, 8, 8 }     , .colors={2, 1, 0, 3 } };
vec4c4   RGBAF32C4 = { .bits={ 32, 32, 32, 32 } , .colors={0, 1, 2, 3 } };
vec4c4   ARGBF32C4 = { .bits={ 32, 32, 32, 32 } , .colors={3, 0, 1, 2 } };
vec4c4   BGRAF32C4 = { .bits={ 32, 32, 32, 32 } , .colors={2, 1, 0, 3 } };
vec3c3   RGBF32C3  = { .bits={ 32, 32, 32  }    , .colors={0, 1, 2 }    };

#endif /* cglm_color_h */
