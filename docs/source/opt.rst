.. default-domain:: C

Options
===============================================================================

A few options are provided via macros.

Alignment Option
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

As default, cglm requires types to be aligned. Alignment requirements:

vec3:   8 byte
vec4:   16 byte
mat4:   16 byte
versor: 16 byte

By starting **v0.4.5** cglm provides an option to disable alignment requirement.
To enable this option define **CGLM_ALL_UNALIGNED** macro before all headers.
You can define it in Xcode, Visual Studio (or other IDEs) or you can also prefer
to define it in build system. If you use pre-compiled versions then you
have to compile cglm with **CGLM_ALL_UNALIGNED** macro.

**VERY VERY IMPORTANT:** If you use cglm in multiple projects and
 those projects are depends on each other, then

 | *ALWAYS* or *NEVER USE* **CGLM_ALL_UNALIGNED** macro in linked projects

 if you do not know what you are doing. Because a cglm header included
 via 'project A' may force types to be aligned and another cglm header
 included via 'project B' may not require alignment. In this case
 cglm functions will read from and write to **INVALID MEMORY LOCATIONs**.

 ALWAYS USE SAME CONFIGURATION / OPTION for **cglm** if you have multiple projects.

 For instance if you set CGLM_ALL_UNALIGNED in a project then set it in other projects too

Clipspace Option[s]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

By starting **v0.8.3** cglm provides options to switch between clipspace configurations.

Clipspace related files are located at `include/cglm/[struct]/clipspace.h` but 
these are included in related files like `cam.h`. If you don't want to change your existing 
clipspace configuration and want to use different clipspace function like `glm_lookat_zo` or `glm_lookat_lh_zo`...
then you can include individual headers or just define `CGLM_CLIPSPACE_INCLUDE_ALL` which will iclude all headers for you.

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
**CGLM_USE_INT_DOMAIN** macro. As default it is not defined.

SSE3 and SSE4 Dot Product Options
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You have to extra options for dot product: **CGLM_SSE4_DOT** and **CGLM_SSE3_DOT**.

- If **SSE4** is enabled then you can define **CGLM_SSE4_DOT** to force cglm to use **_mm_dp_ps** instruction.
- If **SSE3** is enabled then you can define **CGLM_SSE3_DOT** to force cglm to use **_mm_hadd_ps** instructions.

otherwise cglm will use custom cglm's hadd functions which are optimized too.

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
