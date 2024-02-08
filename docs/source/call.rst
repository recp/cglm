.. default-domain:: C

precompiled functions (call)
================================================================================

All functions in **glm_** namespace are forced to **inline**.
Most functions also have pre-compiled version.

Precompiled versions are in **glmc_** namespace. *c* in the namespace stands for
"call".

Since precompiled functions are just wrapper for inline versions,
these functions are not documented individually.
It would be duplicate documentation also it
would be hard to sync documentation between inline and call version for me.

By including **clgm/cglm.h** you include all inline versions. To get precompiled
versions you need to include **cglm/call.h** header it also includes all
call versions plus *clgm/cglm.h* (inline versions)
