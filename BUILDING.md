# Building the library

cglm can be built using one of the following build systems:

## CMake (All platforms)
```bash
$ mkdir build
$ cd build
$ cmake .. # [Optional] -DCGLM_SHARED=ON
$ make
$ sudo make install # [Optional]
```

### Options with defaults

```CMake
option(CGLM_SHARED "Shared build" ON)
option(CGLM_STATIC "Static build" OFF)
option(CGLM_USE_C99 "" OFF) # C11 
option(CGLM_USE_TEST "Enable Tests" OFF) # for make check - make test
```

### Including in a CMake project

#### Header only

This requires no building or installation of cglm.

* Example:

``` cmake
cmake_minimum_required(VERSION 3.8.2)

project(<Your Project Name>)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${LIBRARY_NAME} PRIVATE
  cglm_headers)

add_subdirectory(external/cglm/ EXCLUDE_FROM_ALL)
```

#### Linked

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

### Using CMake to build for WebAssembly

Since math functions like `sinf` are used, this can not be targeted at `wasm32-unknown-unknown`, one of [wasi-sdk](https://github.com/WebAssembly/wasi-sdk) or [emscripten](https://github.com/emscripten-core/emsdk) should be used.

Should note that shared build is not yet supported for WebAssembly.

For [simd128](https://github.com/WebAssembly/simd) support, add `-msimd128` to `CMAKE_C_FLAGS`, in command line `-DCMAKE_C_FLAGS="-msimd128"`.

For tests, the cmake option `CGLM_USE_TEST` would still work, you'll need a wasi runtime for running tests, see our [ci config file](.github/workflows/cmake-wasm.yml) for a detailed example.

#### WASI SDK

```bash
$ cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=/path/to/wasi-sdk-19.0/share/cmake/wasi-sdk.cmake \
  -DWASI_SDK_PREFIX=/path/to/wasi-sdk-19.0
```

Where `/path/to/wasi-sdk-19.0/` is the path to extracted [wasi sdk](https://github.com/WebAssembly/wasi-sdk).

In this case it would by default make a static build.

#### Emscripten

```bash
$ emcmake cmake .. \
  -DCMAKE_EXE_LINKER_FLAGS="-s STANDALONE_WASM" \
  -DCGLM_STATIC=ON
```

The `emcmake` here is the cmake wrapper for Emscripten from installed [emsdk](https://github.com/emscripten-core/emsdk).

## Meson (All platforms)

```bash
$ meson build # [Optional] --default-library=static
$ cd build
$ ninja
$ sudo ninja install # [Optional]
```

### Options with Defaults:

```meson
c_std=c11
buildtype=release
default_library=shared
build_tests=true # to run tests: ninja test
```
### Including in a Meson project
* Example:
```meson
# Clone cglm or create a cglm.wrap under <source_root>/subprojects
project('name', 'c')

cglm_dep = dependency('cglm', fallback : 'cglm', 'cglm_dep')

executable('exe', 'src/main.c', dependencies : cglm_dep)
```

## Swift (Swift Package Manager)

Currently only default build options are supported. Add **cglm** dependency to your project:

```swift
...
Package( 
  ...
  dependencies: [
    ...
    .package(url: "https://github.com/recp/cglm", .branch("master")),
  ]
  ...
)
```

Now add **cgml** as a dependency to your target. Product choices are:
- **cglm** for inlined version of the library which can be linked only statically
- **cglmc** for a compiled version of the library with no linking limitation

```swift
...
.target(
  ...
  dependencies: [
    ...
    .product(name: "cglm", package: "cglm"),
  ]
  ...
)
...
```

## Unix (Autotools)

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

## Windows (MSBuild)
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

### Running Tests on Windows

You can see test project in same visual studio solution file. It is enough to run that project to run tests.

# Building the documentation
First you need install Sphinx: http://www.sphinx-doc.org/en/master/usage/installation.html
then:
```bash
$ cd docs
$ sphinx-build source build
```
it will compile docs into build folder, you can run index.html inside that function.