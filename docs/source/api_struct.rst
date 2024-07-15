Struct API 
================================

Struct API is alternative API to array api to use **cglm** with improved type safety and easy to use. 
Since struct api is built top of array api, every struct API is not documented here. 
See array api documentation for more information for individual functions.

By default struct api adds `s` suffix to every type name e.g. vec3s, mat4s, versors etc. 
Also struct api `s` suffix to namespace e.g. `glms_vec3_add`, `glms_mat4_mul` etc.

By starting v0.9.0, struct api namespace is configurable. We can omit **glms_** namespace or 
even change it with custom name to move existing api integrations to **cglm** more easily...
We can also add **s** to function names if we want e.g. `glms_vec3_add()` -> `vec3_add()` or `vec3s_add()`.

By including **cglm/struct.h** header you will include all struct api. It will also include **cglm/cglm.h** too. 
Since struct apis are inline you don't need to build or link *cglm* against 
your project unless if you want to use pre-built call-api too.

Struct API is built top of array api. So you can mix them. 
Use **.raw** union member to access raw array data to use it with array api. 

Unlike array api ([0], [1], [0][0] ...), it is also possible to use struct api 
with **.x**, **.y**, **.z**, **.w**, **.r**, **.g**, **.b**, **.a**, **.m00**, **m01**... 
accessors to access individual elements/properties of vectors and matrices.

Struct API usage:
-----------------

.. code-block:: c

   #include <cglm/struct.h>
   
   mat4s m1  = glms_mat4_identity(); /* init...  */
   mat4s m2  = glms_mat4_identity(); /* init...  */
   mat4s m3  = glms_mat4_mul(glms_mat4_mul(m1, m2), glms_mat4_mul(m3, m4));
   
   vec3s v1  = { 1.0f, 0.0f, 0.0f };
   vec3s v2  = { 0.0f, 1.0f, 0.0f };
   vec4s v4  = { 0.0f, 1.0f, 0.0f, 0.0f };
   vec4  v5a = { 0.0f, 1.0f, 0.0f, 0.0f };
   
   mat4s m4 = glms_rotate(m3, M_PI_2, 
                          glms_vec3_cross(glms_vec3_add(v1, v6) 
                                          glms_vec3_add(v1, v7)));

   v1.x = 1.0f; v1.y = 0.0f; v1.z = 0.0f;
   // or
   v1.raw[0] = 1.0f; v1.raw[1] = 0.0f; v1.raw[2] = 0.0f;

   /* use struct api with array api (mix them). */
   /* use .raw to access array and use it with array api */

   glm_vec4_add(m4.col[0].raw, v5a, m4.col[0].raw);
   glm_mat4_mulv(m4.raw, v4.raw, v5a);

or omit `glms_` namespace completely (see options below):

.. code-block:: c

   #define CGLM_OMIT_NS_FROM_STRUCT_API

   #include <cglm/struct.h>

   mat4s m1  = mat4_identity(); /* init...  */
   mat4s m2  = mat4_identity(); /* init...  */
   mat4s m3  = mat4_mul(mat4_mul(m1, m2), mat4_mul(m3, m4));
   
   vec3s v1  = { 1.0f, 0.0f, 0.0f };
   vec3s v2  = { 0.0f, 1.0f, 0.0f };
   vec4s v4  = { 0.0f, 1.0f, 0.0f, 0.0f };
   vec4  v5a = { 0.0f, 1.0f, 0.0f, 0.0f };
   
   mat4s m4 = glms_rotate(m3, M_PI_2, 
                          vec3_cross(vec3_add(v1, v6) 
                                     vec3_add(v1, v7)));
   
   v1.x = 1.0f; v1.y = 0.0f; v1.z = 0.0f;
   // or
   v1.raw[0] = 1.0f; v1.raw[1] = 0.0f; v1.raw[2] = 0.0f;

   /* use struct api with array api (mix them) */
   glm_vec4_add(m4.col[0].raw, v5a, m4.col[0].raw);
   glm_mat4_mulv(m4.raw, v4.raw, v5a);
   
Configuring the Struct API:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To configure the Struct API namespace, you can define the following macros before including the cglm/struct.h header:

- **CGLM_OMIT_NS_FROM_STRUCT_API**: omits CGLM_STRUCT_API_NS (`glms_`) namespace completely if there is sub namespace e.g `mat4_`, `vec4_` ... DEFAULT is not defined
- **CGLM_STRUCT_API_NS**:           define name space for struct api, DEFAULT is **glms**
- **CGLM_STRUCT_API_NAME_SUFFIX**:  define name suffix, DEFAULT is **empty** e.g defining it as #define CGLM_STRUCT_API_NAME_SUFFIX  s will add s suffix to mat4_mul -> mat4s_mul

❗️ IMPORTANT ❗️

It's a good idea to set up your config macros in build settings like CMake, Xcode, or Visual Studio. This is especially important if you're using features like Modules in Xcode, where adding macros directly before the **cglm** headers might not work.

Detailed documentation for Struct API:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Since struct api if built top of array api, see array api functions for more information about individual functions.
