# 🎥 OpenGL Mathematics (glm) for `C`
[![Build Status](https://travis-ci.org/recp/cglm.svg?branch=master)](https://travis-ci.org/recp/cglm)
 [![Build status](https://ci.appveyor.com/api/projects/status/av7l3gc0yhfex8y4/branch/master?svg=true)](https://ci.appveyor.com/project/recp/cglm/branch/master)
[![Documentation Status](https://readthedocs.org/projects/cglm/badge/?version=latest)](http://cglm.readthedocs.io/en/latest/?badge=latest)
[![Coverage Status](https://coveralls.io/repos/github/recp/cglm/badge.svg?branch=master)](https://coveralls.io/github/recp/cglm?branch=master)
[![codecov](https://codecov.io/gh/recp/cglm/branch/master/graph/badge.svg)](https://codecov.io/gh/recp/cglm)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/6a62b37d5f214f178ebef269dc4a6bf1)](https://www.codacy.com/app/recp/cglm?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=recp/cglm&amp;utm_campaign=Badge_Grade)
[![Backers on Open Collective](https://opencollective.com/cglm/backers/badge.svg)](#backers)
[![Sponsors on Open Collective](https://opencollective.com/cglm/sponsors/badge.svg)](#sponsors)

#### Documentation

Almost all functions (inline versions) and parameters are documented inside the corresponding headers. <br />
Complete documentation: http://cglm.readthedocs.io

#### Note for previous versions:

- _dup (duplicate) is changed to _copy. For instance `glm_vec_dup -> glm_vec3_copy`
- OpenGL related functions are dropped to make this lib platform/third-party independent
- make sure you have latest version and feel free to report bugs, troubles
- **[bugfix]** euler angles was implemented in reverse order (extrinsic) it was fixed, now they are intrinsic. Make sure that
you have the latest version
- **[major change]** by starting v0.4.0, quaternions are stored as [x, y, z, w], it was [w, x, y, z] in v0.3.5 and earlier versions
- **[api rename]** by starting v0.4.5, **glm_simd** functions are renamed to **glmm_**  
- **[new option]** by starting v0.4.5, you can disable alignment requirement, check options in docs.  
- **[major change]** by starting v0.5.0, vec3 functions use **glm_vec3_** namespace, it was **glm_vec_** until v0.5.0
- **[major change]** by starting v0.5.1, built-in alignment is removed from **vec3** and **mat3** types

#### Note for C++ developers:
If you are not aware of the original GLM library yet, you may also want to look at:
https://github.com/g-truc/glm

#### Note for new comers (Important):
- `vec4` and `mat4` variables must be aligned. (There will be unaligned versions later)
- **in** and **[in, out]** parameters must be initialized (please). But **[out]** parameters not, initializing out param is  also redundant
- All functions are inline if you don't want to use pre-compiled versions with glmc_ prefix, you can ignore build process. Just include headers.
- if your debugger takes you to cglm headers then make sure you are not trying to copy vec4 to vec3 or alig issues...
- Welcome!

#### Note for experienced developers:
- Since I'm testing this library in my projects, sometimes bugs occurs; finding that bug[s] and making improvements would be more easy with multiple developer/contributor and their projects or knowledge. Consider to make some tests if you suspect something is wrong and any feedbacks, contributions and bug reports are always welcome.

#### Allocations?
`cglm` doesn't alloc any memory on heap. So it doesn't provide any allocator. You should alloc memory for **out** parameters too if you pass pointer of memory location. Don't forget that **vec4** (also quat/**versor**) and **mat4** must be aligned (16-bytes), because *cglm* uses SIMD instructions to optimize most operations if available.

#### Returning vector or matrix... ?

**cglm** supports both *ARRAY API* and *STRUCT API*, so you can return structs if you utilize struct api (`glms_`).

#### Other APIs like Vulkan, Metal, Dx?
Currently *cglm* uses default clip space configuration (-1, 1) for camera functions (perspective, extract corners...), in the future other clip space configurations will be supported

<hr/>

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
- array api and struct api, you can use arrays or structs.
- general purpose matrix operations (mat4, mat3)
- chain matrix multiplication (square only)
- general purpose vector operations (cross, dot, rotate, proj, angle...)
- affine transformations
- matrix decomposition (extract rotation, scaling factor)
- optimized affine transform matrices (mul, rigid-body inverse)
- camera (lookat)
- projections (ortho, perspective)
- quaternions
- euler angles / yaw-pitch-roll to matrix
- extract euler angles
- inline or pre-compiled function call
- frustum (extract view frustum planes, corners...)
- bounding box  (AABB in Frustum (culling), crop, merge...)
- bounding sphere
- project, unproject
- easing functions
- curves
- curve interpolation helpers (S*M*C, deCasteljau...)
- helpers to convert cglm types to Apple's simd library to pass cglm types to Metal GL without packing them on both sides
- ray intersection helpers
- and others...

<hr />

You have two option to call a function/operation: inline or library call (link)
Almost all functions are marked inline (always_inline) so compiler will probably inline.
To call pre-compiled version, just use `glmc_` (c stands for 'call') instead of `glm_`.

```C
  #include <cglm/cglm.h>   /* for inline */
  #include <cglm/call.h>   /* for library call (this also includes cglm.h) */

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

Library contains general purpose mat4 mul and inverse functions, and also contains some special forms (optimized) of these functions for affine transformations' matrices. If you want to multiply two affine transformation matrices you can use glm_mul instead of glm_mat4_mul and glm_inv_tr (ROT + TR) instead glm_mat4_inv
```C
/* multiplication */
mat4 modelMat;
glm_mul(T, R, modelMat);

/* othonormal rot + tr matrix inverse (rigid-body) */
glm_inv_tr(modelMat);
```

### Struct API

The struct API works as follows, note the `s` suffix on types, the `glms_` prefix on functions and the `GLMS_` prefix on constants:

```C
#include <cglm/struct.h>

mat4s mat = GLMS_MAT4_IDENTITY_INIT;
mat4s inv = glms_mat4_inv(mat);
```

Struct functions generally take their parameters as *values* and *return* their results, rather than taking pointers and writing to out parameters. That means your parameters can usually be `const`, if you're into that.

The types used are actually unions that allow access to the same data multiple ways. One of those ways involves anonymous structures, available since C11. MSVC also supports it for earlier C versions out of the box and GCC/Clang do if you enable `-fms-extensions`. To explicitly enable these anonymous structures, `#define CGLM_USE_ANONYMOUS_STRUCT` to `1`, to disable them, to `0`. For backward compatibility, you can also `#define CGLM_NO_ANONYMOUS_STRUCT` (value is irrelevant) to disable them. If you don't specify explicitly, cglm will do a best guess based on your compiler and the C version you're using.

## Build

### CMake (All platforms)
```bash
$ mkdir build
$ cd build
$ cmake .. # [Optional] -DCGLM_SHARED=ON
$ make
$ sudo make install # [Optional]
```

##### Cmake options with Defaults:

```CMake
option(CGLM_SHARED "Shared build" ON)
option(CGLM_STATIC "Static build" OFF)
option(CGLM_USE_C99 "" OFF) # C11 
option(CGLM_USE_TEST "Enable Tests" OFF) # for make check - make test
```

#### Use with your CMake project
* Example:
```cmake
cmake_minimum_required(VERSION 3.8.2)

project(<Your Project Name>)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${LIBRARY_NAME} PRIVATE
  cglm)

add_subdirectory(external/cglm/)

# or you can use find_package to configure cglm
```

### Unix (Autotools)

```bash
$ sh autogen.sh
$ ./configure
$ make
$ make check # [Optional]
$ [sudo] make install # [Optional]
```

This will also install pkg-config files so you can use
`pkg-config --cflags cglm` and `pkg-config --libs cglm` to retrieve compiler
and linker flags.

The files will be installed into the given prefix (usually `/usr/local` by
default on Linux), but your pkg-config may not be configured to actually check
there. You can figure out where it's looking by running `pkg-config --variable
pc_path pkg-config` and change the path the files are installed to via
`./configure --with-pkgconfigdir=/your/path`. Alternatively, you can add the
prefix path to your `PKG_CONFIG_PATH` environment variable.

### Windows (MSBuild)
Windows related build file and project files are located in `win` folder,
make sure you are inside `cglm/win` folder.
Code Analysis is enabled, so it may take awhile to build.

```Powershell
$ cd win
$ .\build.bat
```
if `msbuild` won't work (because of multi version VS) then try to build with `devenv`:
```Powershell
$ devenv cglm.sln /Build Release
```

#### Running Tests on Windows

You can see test project in same visual studio solution file. It is enough to run that project to run tests.

### Building Docs
First you need install Sphinx: http://www.sphinx-doc.org/en/master/usage/installation.html
then:
```bash
$ cd docs
$ sphinx-build source build
```
it will compile docs into build folder, you can run index.html inside that function.

## How to use
If you want to use the inline versions of functions, then include the main header
```C
#include <cglm/cglm.h>
```
the header will include all headers. Then call the func you want e.g. rotate vector by axis:
```C
glm_vec3_rotate(v1, glm_rad(45), (vec3){1.0f, 0.0f, 0.0f});
```
some functions are overloaded :) e.g you can normalize vector:
```C
glm_vec3_normalize(vec);
```
this will normalize vec and store normalized vector into `vec` but if you will store normalized vector into another vector do this:
```C
glm_vec3_normalize_to(vec, result);
```
like this function you may see `_to` postfix, this functions store results to another variables and save temp memory


to call pre-compiled versions include header with `c` postfix, c means call. Pre-compiled versions are just wrappers.
```C
#include <cglm/call.h>
```
this header will include all headers with c postfix. You need to call functions with c posfix:
```C
glmc_vec3_normalize(vec);
```

Function usage and parameters are documented inside related headers. You may see same parameter passed twice in some examples like this:
```C
glm_mat4_mul(m1, m2, m1);

/* or */
glm_mat4_mul(m1, m1, m1);
```
the first two parameter are **[in]** and the last one is **[out]** parameter. After multiplying *m1* and *m2*, the result is stored in *m1*. This is why we send *m1* twice. You may store the result in a different matrix, this is just an example.

### Example: Computing MVP matrix

#### Option 1
```C
mat4 proj, view, model, mvp;

/* init proj, view and model ... */

glm_mat4_mul(proj, view, viewProj);
glm_mat4_mul(viewProj, model, mvp);
```

#### Option 2
```C
mat4 proj, view, model, mvp;

/* init proj, view and model ... */

glm_mat4_mulN((mat4 *[]){&proj, &view, &model}, 3, mvp);
```

## How to send matrix to OpenGL

mat4 is array of vec4 and vec4 is array of floats. `glUniformMatrix4fv` functions accecpts `float*` as `value` (last param), so you can cast mat4 to float* or you can pass first column of matrix as beginning of memory of matrix:

Option 1: Send first column
```C
glUniformMatrix4fv(location, 1, GL_FALSE, matrix[0]);

/* array of matrices */
glUniformMatrix4fv(location, 1, GL_FALSE, matrix[0][0]);
```

Option 2: Cast matrix to pointer type (also valid for multiple dimensional arrays)
```C
glUniformMatrix4fv(location, 1, GL_FALSE, (float *)matrix);
```

You can pass matrices the same way to other APIs e.g. Vulkan, DX...

## Notes

- This library uses float types only, does not support Integers, Double... yet
- If headers are not working properly with your compiler, IDE please open an issue, because I'm using GCC and clang to test it maybe sometimes MSVC

**TODO:**
- [ ] Unit tests (In Progress)
- [ ] Unit tests for comparing cglm with glm results
- [x] Add version info
- [ ] Unaligned operations (e.g. `glm_umat4_mul`)
- [x] Extra documentation
- [ ] ARM Neon Arch (In Progress)


## Contributors

This project exists thanks to all the people who contribute. [[Contribute](CONTRIBUTING.md)].
<a href="https://github.com/recp/cglm/graphs/contributors"><img src="https://opencollective.com/cglm/contributors.svg?width=890&button=false" /></a>


## Backers

Thank you to all our backers! 🙏 [[Become a backer](https://opencollective.com/cglm#backer)]

<a href="https://opencollective.com/cglm#backers" target="_blank"><img src="https://opencollective.com/cglm/backers.svg?width=890"></a>


## Sponsors

Support this project by becoming a sponsor. Your logo will show up here with a link to your website. [[Become a sponsor](https://opencollective.com/cglm#sponsor)]

<a href="https://opencollective.com/cglm/sponsor/0/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/0/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/1/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/1/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/2/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/2/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/3/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/3/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/4/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/4/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/5/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/5/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/6/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/6/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/7/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/7/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/8/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/8/avatar.svg"></a>
<a href="https://opencollective.com/cglm/sponsor/9/website" target="_blank"><img src="https://opencollective.com/cglm/sponsor/9/avatar.svg"></a>

## License
MIT. check the LICENSE file
