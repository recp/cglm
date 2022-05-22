API documentation
================================

Some functions may exist twice,
once for their namespace and once for global namespace
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
   quat
   euler
   mat2
   mat3
   mat4
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
