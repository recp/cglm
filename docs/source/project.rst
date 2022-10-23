.. default-domain:: C

Project / UnProject
================================================================================

Header: cglm/project.h

Viewport is required as *vec4* **[X, Y, Width, Height]** but this doesn't mean
that you should store it as **vec4**. You can convert your data representation
to vec4 before passing it to related functions.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_unprojecti`
#. :c:func:`glm_unproject`
#. :c:func:`glm_project`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_unprojecti(vec3 pos, mat4 invMat, vec4 vp, vec3 dest)

    | maps the specified viewport coordinates into specified space [1]
      the matrix should contain projection matrix.

    if you don't have ( and don't want to have ) an inverse matrix then use
    :c:func:`glm_unproject` version. You may use existing inverse of matrix in somewhere
    else, this is why **glm_unprojecti** exists to save inversion cost

    [1] space:
      - if m = invProj:     View Space
      - if m = invViewProj: World Space
      - if m = invMVP:      Object Space

    You probably want to map the coordinates into object space
    so use invMVP as m

    Computing viewProj:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);
       glm_mat4_mul(viewProj, model, MVP);
       glm_mat4_inv(viewProj, invMVP);

    Parameters:
      | *[in]*  **pos**     point/position in viewport coordinates
      | *[in]*  **invMat**  matrix (see brief)
      | *[in]*  **vp**      viewport as [x, y, width, height]
      | *[out]* **dest**    unprojected coordinates

.. c:function:: void  glm_unproject(vec3 pos, mat4 m, vec4 vp, vec3 dest)

    | maps the specified viewport coordinates into specified space [1]
      the matrix should contain projection matrix.

    this is same as :c:func:`glm_unprojecti` except this function get inverse matrix for
    you.

    [1] space:
      - if m = proj:     View Space
      - if m = viewProj: World Space
      - if m = MVP:      Object Space

    You probably want to map the coordinates into object space so use MVP as m

    Computing viewProj and MVP:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);
       glm_mat4_mul(viewProj, model, MVP);

    Parameters:
      | *[in]*  **pos**  point/position in viewport coordinates
      | *[in]*  **m**    matrix (see brief)
      | *[in]*  **vp**   viewport as [x, y, width, height]
      | *[out]* **dest** unprojected coordinates

.. c:function:: void glm_project(vec3 pos, mat4 m, vec4 vp, vec3 dest)

    | map object coordinates to window coordinates

    Computing MVP:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);
       glm_mat4_mul(viewProj, model, MVP);

    Parameters:
      | *[in]*  **pos**      object coordinates
      | *[in]*  **m**        MVP matrix
      | *[in]*  **vp**       viewport as [x, y, width, height]
      | *[out]* **dest**     projected coordinates

.. c:function:: float glm_project_z(vec3 pos, mat4 m)

    | map object's z coordinate to window coordinates

    this is same as :c:func:`glm_project` except this function projects only Z coordinate
    which reduces a few calculations and parameters.

    Computing MVP:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);
       glm_mat4_mul(viewProj, model, MVP);

    Parameters:
      | *[in]*  **pos**      object coordinates
      | *[in]*  **m**        MVP matrix

    Returns:
        projected z coordinate