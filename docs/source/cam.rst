.. default-domain:: C

camera
======

Header: cglm/cam.h

There are many convenient functions for camera. For instance :c:func:`glm_look`
is just wrapper for :c:func:`glm_lookat`. Sometimes you only have direction
instead of target, so that makes easy to build view matrix using direction.
There is also :c:func:`glm_look_anyup` function which can help build view matrix
without providing UP axis. It uses :c:func:`glm_vec3_ortho` to get a UP axis and
builds view matrix.

You can also *_default* versions of ortho and perspective to build projection
fast if you don't care specific projection values.

*_decomp* means decompose; these function can help to decompose projection
matrices.

 **NOTE**: Be careful when working with high range (very small near, very large
 far) projection matrices. You may not get exact value you gave.
 **float** type cannot store very high precision so you will lose precision.
 Also your projection matrix will be inaccurate due to losing precision

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_frustum`
#. :c:func:`glm_ortho`
#. :c:func:`glm_ortho_aabb`
#. :c:func:`glm_ortho_aabb_p`
#. :c:func:`glm_ortho_aabb_pz`
#. :c:func:`glm_ortho_default`
#. :c:func:`glm_ortho_default_s`
#. :c:func:`glm_perspective`
#. :c:func:`glm_persp_move_far`
#. :c:func:`glm_perspective_default`
#. :c:func:`glm_perspective_resize`
#. :c:func:`glm_lookat`
#. :c:func:`glm_look`
#. :c:func:`glm_look_anyup`
#. :c:func:`glm_persp_decomp`
#. :c:func:`glm_persp_decompv`
#. :c:func:`glm_persp_decomp_x`
#. :c:func:`glm_persp_decomp_y`
#. :c:func:`glm_persp_decomp_z`
#. :c:func:`glm_persp_decomp_far`
#. :c:func:`glm_persp_decomp_near`
#. :c:func:`glm_persp_fovy`
#. :c:func:`glm_persp_aspect`
#. :c:func:`glm_persp_sizes`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_frustum(float left, float right, float bottom, float top, float nearVal, float farVal, mat4  dest)

    | set up perspective peprojection matrix

    Parameters:
      | *[in]*  **left**      viewport.left
      | *[in]*  **right**     viewport.right
      | *[in]*  **bottom**    viewport.bottom
      | *[in]*  **top**       viewport.top
      | *[in]*  **nearVal**   near clipping plane
      | *[in]*  **farVal**    far clipping plane
      | *[out]* **dest**      result matrix

.. c:function:: void  glm_ortho(float left, float right, float bottom, float top, float nearVal, float farVal, mat4  dest)

    | set up orthographic projection matrix

    Parameters:
      | *[in]*  **left**      viewport.left
      | *[in]*  **right**     viewport.right
      | *[in]*  **bottom**    viewport.bottom
      | *[in]*  **top**       viewport.top
      | *[in]*  **nearVal**   near clipping plane
      | *[in]*  **farVal**    far clipping plane
      | *[out]* **dest**      result matrix

.. c:function:: void  glm_ortho_aabb(vec3 box[2], mat4 dest)

    | set up orthographic projection matrix using bounding box
    | bounding box (AABB) must be in view space

    Parameters:
      | *[in]*  **box**   AABB
      | *[in]*  **dest**  result matrix

.. c:function:: void  glm_ortho_aabb_p(vec3 box[2], float padding, mat4 dest)

    | set up orthographic projection matrix using bounding box
    | bounding box (AABB) must be in view space

    this version adds padding to box

    Parameters:
      | *[in]*  **box**      AABB
      | *[in]*  **padding**  padding
      | *[out]* **d**        result matrix

.. c:function:: void  glm_ortho_aabb_pz(vec3 box[2], float padding, mat4 dest)

    | set up orthographic projection matrix using bounding box
    | bounding box (AABB) must be in view space

    this version adds Z padding to box

    Parameters:
      | *[in]*  **box**      AABB
      | *[in]*  **padding**  padding for near and far
      | *[out]* **d**        result matrix

    Returns:
      square of norm / magnitude

.. c:function:: void  glm_ortho_default(float aspect, mat4  dest)

    | set up unit orthographic projection matrix

    Parameters:
      | *[in]*  **aspect** aspect ration ( width / height )
      | *[out]* **dest**   result matrix

.. c:function:: void  glm_ortho_default_s(float aspect, float size, mat4  dest)

    | set up orthographic projection matrix with given CUBE size

    Parameters:
      | *[in]*  **aspect** aspect ration ( width / height )
      | *[in]*  **size**   cube size
      | *[out]* **dest**   result matrix

.. c:function:: void  glm_perspective(float fovy, float aspect, float nearVal, float farVal, mat4  dest)

    | set up perspective projection matrix

    Parameters:
      | *[in]*  **fovy**    field of view angle
      | *[in]*  **aspect**  aspect ratio ( width / height )
      | *[in]*  **nearVal** near clipping plane
      | *[in]*  **farVal**  far clipping planes
      | *[out]* **dest**    result matrix

.. c:function:: void  glm_persp_move_far(mat4 proj, float deltaFar)

    | extend perspective projection matrix's far distance

    | this function does not guarantee far >= near, be aware of that!

    Parameters:
      | *[in, out]*  **proj**      projection matrix to extend
      | *[in]*       **deltaFar**  distance from existing far (negative to shink)

.. c:function:: void glm_perspective_default(float aspect, mat4 dest)

     | set up perspective projection matrix with default near/far
       and angle values

    Parameters:
      | *[in]*  **aspect** aspect aspect ratio ( width / height )
      | *[out]* **dest**   result matrix

.. c:function:: void  glm_perspective_resize(float aspect, mat4 proj)

    | resize perspective matrix by aspect ratio ( width / height )
      this makes very easy to resize proj matrix when window / viewport reized

    Parameters:
      | *[in]*      **aspect** aspect ratio ( width / height )
      | *[in, out]* **proj**   perspective projection matrix

.. c:function:: void  glm_lookat(vec3 eye, vec3 center, vec3 up, mat4 dest)

    | set up view matrix

    **NOTE:** The UP vector must not be parallel to the line of sight from the eye point to the reference point.

    Parameters:
      | *[in]*  **eye**     eye vector
      | *[in]*  **center**  center vector
      | *[in]*  **up**      up vector
      | *[out]* **dest**    result matrix

.. c:function:: void  glm_look(vec3 eye, vec3 dir, vec3 up, mat4 dest)

    | set up view matrix

    convenient wrapper for :c:func:`glm_lookat`: if you only have direction not
    target self then this might be useful. Because you need to get target
    from direction.

    **NOTE:** The UP vector must not be parallel to the line of sight from the eye point to the reference point.

    Parameters:
      | *[in]*  **eye**     eye vector
      | *[in]*  **center**  direction vector
      | *[in]*  **up**      up vector
      | *[out]* **dest**    result matrix

.. c:function:: void  glm_look_anyup(vec3 eye, vec3 dir, mat4 dest)

    | set up view matrix

    convenient wrapper for :c:func:`glm_look` if you only have direction
    and if you don't care what UP vector is then this might be useful
    to create view matrix

    Parameters:
      | *[in]*  **eye**     eye vector
      | *[in]*  **center**  direction vector
      | *[out]* **dest**    result matrix

.. c:function:: void  glm_persp_decomp(mat4 proj, float *nearVal, float *farVal, float *top, float *bottom, float *left, float *right)

    | decomposes frustum values of perspective projection.

    Parameters:
      | *[in]*  **eye**       perspective projection matrix
      | *[out]*  **nearVal**  near
      | *[out]*  **farVal**   far
      | *[out]*  **top**      top
      | *[out]*  **bottom**   bottom
      | *[out]*  **left**     left
      | *[out]* **right**     right

.. c:function:: void  glm_persp_decompv(mat4 proj, float dest[6])

    | decomposes frustum values of perspective projection.
    | this makes easy to get all values at once

    Parameters:
      | *[in]*   **proj**  perspective projection matrix
      | *[out]*  **dest**  array

.. c:function:: void  glm_persp_decomp_x(mat4 proj, float *left, float *right)

    | decomposes left and right values of perspective projection.
    | x stands for x axis (left / right axis)

    Parameters:
      | *[in]*   **proj**   perspective projection matrix
      | *[out]*  **left**   left
      | *[out]*  **right**  right

.. c:function:: void  glm_persp_decomp_y(mat4 proj, float *top, float *bottom)

    | decomposes top and bottom values of perspective projection.
    | y stands for y axis (top / botom axis)

    Parameters:
      | *[in]*   **proj**    perspective projection matrix
      | *[out]*  **top**     top
      | *[out]*  **bottom**  bottom

.. c:function:: void  glm_persp_decomp_z(mat4 proj, float *nearVal, float *farVal)

    | decomposes near and far values of perspective projection.
    | z stands for z axis (near / far axis)

    Parameters:
      | *[in]*   **proj**     perspective projection matrix
      | *[out]*  **nearVal**  near
      | *[out]*  **farVal**   far

.. c:function:: void  glm_persp_decomp_far(mat4 proj, float * __restrict farVal)

    | decomposes far value of perspective projection.

    Parameters:
      | *[in]*  **proj**    perspective projection matrix
      | *[out]* **farVal**  far

.. c:function:: void  glm_persp_decomp_near(mat4 proj, float * __restrict nearVal)

    | decomposes near value of perspective projection.

    Parameters:
      | *[in]*  **proj**    perspective projection matrix
      | *[out]* **nearVal** near

.. c:function:: float  glm_persp_fovy(mat4 proj)

    | returns field of view angle along the Y-axis (in radians)

    if you need to degrees, use glm_deg to convert it or use this:
    fovy_deg = glm_deg(glm_persp_fovy(projMatrix))

    Parameters:
      | *[in]*  **proj**  perspective projection matrix

    Returns:
      | fovy in radians

.. c:function:: float  glm_persp_aspect(mat4 proj)

    | returns aspect ratio of perspective projection

    Parameters:
      | *[in]*  **proj**  perspective projection matrix

.. c:function:: void  glm_persp_sizes(mat4 proj, float fovy, vec4 dest)

    | returns sizes of near and far planes of perspective projection

    Parameters:
      | *[in]*  **proj**  perspective projection matrix
      | *[in]*  **fovy**  fovy (see brief)
      | *[out]* **dest**  sizes order: [Wnear, Hnear, Wfar, Hfar]
