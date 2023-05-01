📚 API documentation
================================

**cglm** provides a few APIs for similar functions.

* 📦 **Inline API**: All functions are inline. You can include **cglm/cglm.h** header
  to use this API. This is the default API. `glm_` is namespace/prefix for this API. 
* 📦 **Call API**: All functions are not inline. You need to build *cglm* and link it
  to your project. You can include **cglm/call.h** header to use this API. `glmc_` is namespace/prefix for this API. 

And also there are also sub categories:

* 📦 **Array API**: Types are raw arrays and functions takes array as argument. You can include **cglm/cglm.h** header
  to use this API. This is the default API. `glm_` is namespace/prefix for this API. 
* 📦 **Struct API**: Types are union/struct and functions takes struct as argument and return structs if needed. You can include **cglm/struct.h** header
  to use this API. This also includes **cglm/cglm.h** header.`glms_` is namespace/prefix for this API but your can omit or change it, see struct api docs.
* 📦 **SIMD API**: SIMD functions and helpers. `glmm_` is namespace/prefix for this API. 

📌 Since struct api and call api are built top of inline array api, follow inline array api docs for individual functions. 

.. toctree::
   :maxdepth: 1
   :caption: API documentations:

   api_inline_array
   api_struct
   api_call
   api_simd
