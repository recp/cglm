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
to define it in build system. If you use pre-compiled verisons then you
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
2. **CGLM_NO_PRINTS_NOOP**

Inline prints are only enabled in DEBUG mode and if **CGLM_DEFINE_PRINTS** is defined.
If DEBUG is not enabled then print function bodies will be emptied to eliminate print function calls.
You can disable this feature too by defining **CGLM_NO_PRINTS_NOOP** macro top of cglm headers.

3. **CGLM_PRINT_PRECISION**    5

precision.

4. **CGLM_PRINT_MAX_TO_SHORT** 1e5

if a number is greater than this value then %g will be used, since this is shorten print you won't be able to see high precision.

5. **CGLM_PRINT_COLOR**        "\033[36m"
6. **CGLM_PRINT_COLOR_RESET**  "\033[0m"
