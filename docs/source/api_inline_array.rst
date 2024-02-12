Array API - Inline (Default)
========================================

This is the default API of *cglm*. All functions are forced to be inlined 
and struct api, call api uses this inline api to share implementation.

📌 Call api is also array api but it is not inlined. 
In the future there may be option to forward struct api to call api instead of inline api to reduce binary size if needed.

📌 **USE this API docs for similar functions in struct and call api** 

📌 In struct api you can omit namespace e.g :code:`glms_vec3_dot` can be called as :code:`vec3_dot` in struct api, see :doc:`api_struct` to configure struct api for more details.
📌 In struct api functions can return struct/union
📌 In struct api you can access items like **.x**, **.y**, **.z**, **.w**, **.r**, **.g**, **.b**, **.a**, **.m00**, **m01**... 

Some functions may exist twice, once for their namespace and once for global namespace
to make easier to write very common functions

For instance, in general we use :code:`glm_vec3_dot` to get dot product
of two **vec3**. Now we can also do this with :code:`glm_dot`,
same for *_cross* and so on...

The original function stays where it is, the function in global namespace
of same name is just an alias, so there is no call version of those functions.
e.g there is no func like :code:`glmc_dot` because *glm_dot* is just alias for
:code:`glm_vec3_dot`

By including **cglm/cglm.h** header you will include all inline version
of functions. Since functions in this header[s] are inline you don't need to
build or link *cglm* against your project.

But by including **cglm/call.h** header you will include all *non-inline*
version of functions. You need to build *cglm* and link it.
Follow the :doc:`build` documentation for this

.. toctree::
   :maxdepth: 1
   :caption: API categories:

   affine
   affine-mat
   affine2d
   cam
   frustum
   box
   aabb2d
   quat
   euler
   mat2
   mat2x3
   mat2x4
   mat3
   mat3x2
   mat3x4
   mat4
   mat4x2
   mat4x3
   vec2
   vec2-ext
   vec3
   vec3-ext
   vec4
   vec4-ext
   ivec2
   ivec3
   ivec4
   color
   plane
   project
   util
   io
   call
   sphere
   curve
   bezier
   version
   ray
