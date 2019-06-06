.. default-domain:: C

precompiled functions (call)
================================================================================

All funcitons in **glm_** namespace are forced to **inline**.
Most functions also have pre-compiled version.

Precompiled versions are in **glmc_** namespace. *c* in the namespace stands for
"call".

Since precompiled functions are just wrapper for inline verisons,
these functions are not documented individually.
It would be duplicate documentation also it
would be hard to sync documentation between inline and call verison for me.

By including **clgm/cglm.h** you include all inline verisons. To get precompiled
versions you need to include **cglm/call.h** header it also includes all
call versions plus *clgm/cglm.h* (inline verisons)
