.. default-domain:: C

Options
===============================================================================

A few options are provided via macros.

Alignment
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
