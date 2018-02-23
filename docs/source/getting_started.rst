Getting Started
================================
.. image:: cglm-intro.png
   :width: 492px 
   :height: 297px
   :align: center

**cglm** uses **glm** prefix for all functions e.g. glm_lookat. You can see supported types in common header file:

.. code-block:: c
  :linenos:

   typedef float vec3[3];
   typedef int  ivec3[3];
   typedef CGLM_ALIGN(16) float vec4[4];

   typedef vec3 mat3[3];
   typedef vec4 mat4[4];

   typedef vec4 versor;

As you can see types don't store extra informations in favor of space.
You can send these values e.g. matrix to OpenGL directly without casting or calling a function like *value_ptr*

*vec4* and *mat4* requires 16 byte aligment because vec4 and mat4 operations are
vectorized by SIMD instructions (SSE/AVX).

**NOTE:** Unaligned vec4 and unaligned mat4 operations will be supported in the future. Check todo list.
Because you may want to multiply a CGLM matrix with external matrix.
There is no guarantee that non-CGLM matrix is aligned. Unaligned types will have *u* prefix e.g. **umat4**

cglm provides a few way to call a function to do same operation.

* Inline - *glm_, glm_u*
   * aligned
   * unaligned (todo)
* Pre-compiled - *glmc_, glmc_u*
   * aligned
   * unaligned (todo)

For instance **glm_mat4_mul** is inline (all *glm_* functions are inline), to make it non-inline (pre-compiled)
call it as **glmc_mat4_mul** from library, to use unaligned version use **glm_umat4_mul** (todo).

Most functions have **dest** parameter for output. For instance mat4_mul func looks like this:

.. code-block:: c

   CGLM_INLINE
   void
   glm_mat4_mul(mat4 m1, mat4 m2, mat4 dest)

The dest parameter is out parameter. Result will be stored in **dest**.
Also in this case matrix multiplication order is dest = m1 * m2.

* Changing parameter order will change the multiplication order.
* You can pass all parameter same (this is similar to m1 `*=` m1), you can pass **dest** as m1 or m2 (this is similar to m1 `*=` m2)

**v** postfix in function names
-------------------------------

You may see **v** postfix in some function names, v stands for vector.
For instance consider a function that accepts three parameters x, y, z.
This function may be overloaded by **v** postfix to accept vector (vec3) instead of separate parameters.
In some places the v means that it will be apply to a vector.

**_to** postfix in function names
---------------------------------

*_to* version of function will store the result in specified parameter instead of in-out parameter.
Some functions don't have _to prefix but they still behave like this e.g. glm_mat4_mul.
