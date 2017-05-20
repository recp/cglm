# 🎥 OpenGL Mathematics (glm) for `C`
[![Build Status](https://travis-ci.org/recp/cglm.svg?branch=master)](https://travis-ci.org/recp/cglm)
[![Build status](https://ci.appveyor.com/api/projects/status/av7l3gc0yhfex8y4/branch/master?svg=true)](https://ci.appveyor.com/project/recp/cglm/branch/master)
[![Coverage Status](https://coveralls.io/repos/github/recp/cglm/badge.svg?branch=master)](https://coveralls.io/github/recp/cglm?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/6a62b37d5f214f178ebef269dc4a6bf1)](https://www.codacy.com/app/recp/cglm?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=recp/cglm&amp;utm_campaign=Badge_Grade)

The original glm library is for C++ only (templates, namespaces, classes...), this library targeted to C99 but currently you can use it for C89 safely by language extensions e.g `__register`

#### Note for previous versions:

- _dup (duplicate) is changed to _copy. For instance `glm_vec_dup -> glm_vec_copy`
- OpenGL related functions are dropped to make this lib platform/third-party independent
- make sure you have latest version and feel free to report bugs, troubles

#### Note for C++ developers:
If you don't aware about original GLM library yet, you may also want to look at:
https://github.com/g-truc/glm


<table>
  <tbody>
    <tr>
      <td>
        <div>Like some other graphics libraries (especially OpenGL) this library use Column-Major layout to keep matrices in the memory. </div>
        <div>&nbsp;</div>
        <div>In the future the library may support an option to use row-major layout, CURRENTLY if you need to row-major layout you will need to transpose it. </div>
      </td>
      <td>
        <img src="https://upload.wikimedia.org/wikipedia/commons/3/3f/Matrix_Columns.svg" width="300px" />
      </td>
    </tr>
  </tbody>
</table>

## Features
- general purpose matrix operations (mat4, mat3)
- chain matrix multiplication (square only)
- general purpose vector operations (cross, dot, rotate, proj, angle...)
- affine transforms
- matrix decomposition (extract rotation, scaling factor)
- optimized affine transform matrices (mul, rigid-body inverse)
- camera (lookat)
- projections (ortho, perspective)
- quaternions
- euler angles / yaw-pitch-roll to matrix
- extract euler angles
- inline or pre-compiled function call

<hr />

You have two option to call a function/operation: inline or library call (link)
Almost all functions are marked inline (always_inline) so compiler probably will inline.
To call pre-compiled version, just use `glmc_` (c stands for 'call') instead of `glm_`.

```C
  #include <cglm.h>        /* for inline */
  #include <cglm-call.h>   /* for library call (this also includes cglm.h) */

  mat4 rot, trans, rt;
  /* ... */
  glm_mul(trans, rot, rt);  /* inline */
  glmc_mul(trans, rot, rt); /* call from library */
```
Most of math functions are optimized manualy with SSE2 if available, if not? Dont worry there are non-sse versions of all operations

You can pass matrices and vectors as array to functions rather than get address.

```C
  mat4 m = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  };

  glm_translate(m, (vec3){1.0f, 0.0f, 0.0f});
```

Library contains general purpose mat4 mul and inverse functions but also contains some special form (optimized) of these functions for affine transform matrices. If you want to multiply two affine transform matrices you can use glm_mul instead of glm_mat4_mul and glm_inv_tr (ROT + TR) instead glm_mat4_inv
```C
/* multiplication */
mat4 modelMat;
glm_mul(T, R, modelMat);

/* othonormal rot + tr matrix inverse (rigid-body) */
glm_inv_tr(modelMat);
```

## License
MIT. check the LICENSE file

## Build

### Unix (Autotools)

```text
$ sh ./build-deps.sh # run only once (dependencies)
$
$ sh autogen.sh
$ ./configure
$ make
$ make install
$ [sudo] make install
```

### Windows (MSBuild)
Windows related build files, project files are located in `win` folder,
make sure you are inside `cglm/win` folder.
Code Analysis are enabled, it may take awhile to build

```Powershell
$ cd win
$ .\build.bat
```
if `msbuild` won't work (because of multi version VS) then try to build with `devenv`:
```Powershell
$ devenv cglm.sln /Build Release
```

## How to use
If you want to use inline versions of funcstions then; include main header
```C
#include <cglm.h>
```
the haeder will include all headers. Then call func you want e.g. rotate vector by axis:
```C
glm_vec_rotate(v1, glm_rad(45), (vec3){1.0f, 0.0f, 0.0f});
```
some functions are overloaded :) e.g you can normalize vector:
```C
glm_vec_normalize(vec);
```
this will normalize vec and store normalized vector into `vec` but if you will store normalized vector into another vector do this:
```C
glm_vec_normalize_to(vec, result);
```
like this function you may see `_to` postfix, this functions store results to another variables and save temp memory


to call pre-compiled versions include header with `c` postfix, c means call. Pre-compiled versions are just wrappers.
```C
#include <cglm-call.h>
```
this header will include all heaers with c postfix. You need to call functions with c posfix:
```C
glmc_vec_normalize(vec);
```

Function usage and parameters are documented inside related headers.
## Notes

- This library uses float types only, does not support Integers, Double... yet
- If headers are not working properly with your compiler, IDE please open an issue, because I'm using GCC and clang to test it maybe sometimes MSVC

**TODO:**
- [ ] Unit tests
- [ ] Unit tests for comparing cglm with glm results
- [ ] Add version info
- [ ] Unaligned operations (e.g. `glm_umat4_mul`)
- [ ] Extra documentation
- [ ] ARM Neon Arch
