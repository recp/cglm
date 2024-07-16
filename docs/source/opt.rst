.. default-domain:: C

🛠️ Options
===============================================================================

A few options are provided via macros.

❗️ IMPORTANT ❗️

It's a good idea to set up your config macros in build settings like CMake, Xcode, or Visual Studio. This is especially important if you're using features like Modules in Xcode, where adding macros directly before the **cglm** headers might not work.

Alignment Option
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

By default, **cglm** requires types to be aligned with specific byte requirements:

- vec3: 8 bytes
- vec4: 16 bytes
- mat4: 16 bytes (32 on AVX)
- versor: 16 bytes

Starting with **v0.4.5**, **cglm** offers an option to relax these alignment requirements. To use this option, define the **CGLM_ALL_UNALIGNED** macro before including any headers. This definition can be made within Xcode, Visual Studio, other IDEs, or directly in your build system. If using pre-compiled versions of **cglm**, you'll need to compile them with the **CGLM_ALL_UNALIGNED** macro.

**❗️NOTE:❗️** If you're using **cglm** across multiple interdependent projects:

- Always or never use the **CGLM_ALL_UNALIGNED** macro in all linked projects to avoid configuration conflicts. A **cglm** header from one project could require alignment, while a header from another might not, leading to **cglm** functions accessing invalid memory locations.

- **Key Point:** Maintain the same **cglm** configuration across all your projects. For example, if you activate **CGLM_ALL_UNALIGNED** in one project, ensure it's set in the others too.

**❗️NOTE:❗️**

While **CGLM_ALL_UNALIGNED** allows for flexibility in alignment, it doesn't override C's fundamental alignment rules. For example, an array like *vec4* decays to a pointer (float*) in functions, which must adhere to the alignment requirements of a float pointer (4 bytes). This adherence is crucial because **cglm** directly dereferences these pointers instead of copying data, and failing to meet alignment requirements can lead to unpredictable errors, such as crashes.

You can use `CGLM_ALIGN` and `CGLM_ALIGN_MAT` macros for aligning local variables or struct members. However, when dealing with dynamic memory allocation or custom memory locations, you'll need to ensure alignment requirements are met appropriately for those cases

Clipspace Option[s]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

By starting **v0.8.3** cglm provides options to switch between clipspace configurations.

Clipspace related files are located at `include/cglm/[struct]/clipspace.h` but 
these are included in related files like `cam.h`. If you don't want to change your existing 
clipspace configuration and want to use different clipspace function like `glm_lookat_zo` or `glm_lookat_lh_zo`...
then you can include individual headers or just define `CGLM_CLIPSPACE_INCLUDE_ALL` which will include all headers for you.

1. **CGLM_CLIPSPACE_INCLUDE_ALL**
2. **CGLM_FORCE_DEPTH_ZERO_TO_ONE**
3. **CGLM_FORCE_LEFT_HANDED**


1. **CGLM_CLIPSPACE_INCLUDE_ALL**:

By defining this macro, **cglm** will include all clipspace functions for you by just using
`#include cglm/cglm.h` or `#include cglm/struct.h` or `#include cglm/call.h`

Otherwise you need to include header you want manually e.g. `#include cglm/clipspace/view_rh_zo.h`

2. **CGLM_FORCE_DEPTH_ZERO_TO_ONE**

This is similar to **GLM**'s **GLM_FORCE_DEPTH_ZERO_TO_ONE** option. 
This will set clip space between 0 to 1 which makes **cglm** Vulkan, Metal friendly. 

You can use functions like `glm_lookat_lh_zo()` individually. By setting **CGLM_FORCE_DEPTH_ZERO_TO_ONE**
functions in cam.h for instance will use `_zo` versions.

3. **CGLM_FORCE_LEFT_HANDED**

Force **cglm** to use the left handed coordinate system by default, currently **cglm** uses right handed coordinate system as default,
you can change this behavior with this option.

**VERY VERY IMPORTANT:**

Be careful if you include **cglm** in multiple projects.

SSE and SSE2 Shuffle Option
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**_mm_shuffle_ps** generates **shufps** instruction even if registers are same.
You can force it to generate **pshufd** instruction by defining
**CGLM_NO_INT_DOMAIN** macro. As default it is not defined.

SSE3 and SSE4 Dot Product Options
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You have to extra options for dot product: **CGLM_SSE4_DOT** and **CGLM_SSE3_DOT**.

- If **SSE4** is enabled then you can define **CGLM_SSE4_DOT** to force cglm to use **_mm_dp_ps** instruction.
- If **SSE3** is enabled then you can define **CGLM_SSE3_DOT** to force cglm to use **_mm_hadd_ps** instructions.

otherwise cglm will use custom cglm's hadd functions which are optimized too.

Struct API Options
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To configure the Struct API namespace, you can define the following macros before including the cglm/struct.h header:

- **CGLM_OMIT_NS_FROM_STRUCT_API**: omits CGLM_STRUCT_API_NS (`glms_`) namespace completely if there is sub namespace e.g `mat4_`, `vec4_` ... DEFAULT is not defined
- **CGLM_STRUCT_API_NS**:           define name space for struct api, DEFAULT is **glms**
- **CGLM_STRUCT_API_NAME_SUFFIX**:  define name suffix, DEFAULT is **empty** e.g defining it as #define CGLM_STRUCT_API_NAME_SUFFIX  s will add s suffix to mat4_mul -> mat4s_mul


Print Options
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. **CGLM_DEFINE_PRINTS**
2. **CGLM_NO_PRINTS_NOOP** (use CGLM_DEFINE_PRINTS)

Inline prints are only enabled in **DEBUG** mode or if **CGLM_DEFINE_PRINTS** is defined.
**glmc_** versions will always print too.

Because **cglm** tried to enable print functions in debug mode and disable them in
release/production mode to eliminate printing costs when we do not need them.

**cglm** checks **DEBUG** or **_DEBUG** macros to test debug mode, if these are not working for you then you can use 
**CGLM_DEFINE_PRINTS** to force enable, or create a PR to introduce new macro to test against debugging mode.

If DEBUG mode is not enabled then print functions will be emptied to eliminate print function calls.
You can disable this feature too by defining **CGLM_DEFINE_PRINTS** macro top of cglm header 
or in project/build settings...

3. **CGLM_PRINT_PRECISION**    5

precision.

4. **CGLM_PRINT_MAX_TO_SHORT** 1e5

if a number is greater than this value then %g will be used, since this is shorten print you won't be able to see high precision.

5. **CGLM_PRINT_COLOR**        "\033[36m"
6. **CGLM_PRINT_COLOR_RESET**  "\033[0m"

You can disable colorful print output by defining **CGLM_PRINT_COLOR** and **CGLM_PRINT_COLOR_RESET** as empty macro.
Because some terminals may not support colors.
