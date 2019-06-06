.. default-domain:: C

frustum
=============

Header: cglm/frustum.h

cglm provides convenient functions to extract frustum planes, corners...
All extracted corners are **vec4** so you must create array of **vec4**
not **vec3**. If you want to store them to save space you msut convert them
yourself.

**vec4** is used to speed up functions need to corners. This is why frustum
fucntions use *vec4* instead of *vec3*

Currenty related-functions use [-1, 1] clip space configuration to extract
corners but you can override it by prodiving **GLM_CUSTOM_CLIPSPACE** macro.
If you provide it then you have to all bottom macros as *vec4*

Current configuration:

.. code-block:: c

   /* near */
   GLM_CSCOORD_LBN {-1.0f, -1.0f, -1.0f, 1.0f}
   GLM_CSCOORD_LTN {-1.0f,  1.0f, -1.0f, 1.0f}
   GLM_CSCOORD_RTN { 1.0f,  1.0f, -1.0f, 1.0f}
   GLM_CSCOORD_RBN { 1.0f, -1.0f, -1.0f, 1.0f}

   /* far */
   GLM_CSCOORD_LBF {-1.0f, -1.0f,  1.0f, 1.0f}
   GLM_CSCOORD_LTF {-1.0f,  1.0f,  1.0f, 1.0f}
   GLM_CSCOORD_RTF { 1.0f,  1.0f,  1.0f, 1.0f}
   GLM_CSCOORD_RBF { 1.0f, -1.0f,  1.0f, 1.0f}


Explain of short names:
  * **LBN**: left  bottom near
  * **LTN**: left  top    near
  * **RTN**: right top    near
  * **RBN**: right bottom near
  * **LBF**: left  bottom far
  * **LTF**: left  top    far
  * **RTF**: right top    far
  * **RBF**: right bottom far

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

.. code-block:: c

   GLM_LBN    0 /* left  bottom near */
   GLM_LTN    1 /* left  top    near */
   GLM_RTN    2 /* right top    near */
   GLM_RBN    3 /* right bottom near */

   GLM_LBF    4 /* left  bottom far  */
   GLM_LTF    5 /* left  top    far  */
   GLM_RTF    6 /* right top    far  */
   GLM_RBF    7 /* right bottom far  */

   GLM_LEFT   0
   GLM_RIGHT  1
   GLM_BOTTOM 2
   GLM_TOP    3
   GLM_NEAR   4
   GLM_FAR    5

Functions:

1. :c:func:`glm_frustum_planes`
#. :c:func:`glm_frustum_corners`
#. :c:func:`glm_frustum_center`
#. :c:func:`glm_frustum_box`
#. :c:func:`glm_frustum_corners_at`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_frustum_planes(mat4 m, vec4 dest[6])

    | extracts view frustum planes

    planes' space:
     - if m = proj:     View Space
     - if m = viewProj: World Space
     - if m = MVP:      Object Space

    You probably want to extract planes in world space so use viewProj as m
    Computing viewProj:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);

    Exracted planes order: [left, right, bottom, top, near, far]

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  exracted view frustum planes

.. c:function:: void  glm_frustum_corners(mat4 invMat, vec4 dest[8])

    | extracts view frustum corners using clip-space coordinates

    corners' space:
     - if m = invViewProj: World Space
     - if m = invMVP:      Object Space

    You probably want to extract corners in world space so use **invViewProj**
    Computing invViewProj:

    .. code-block:: c

       glm_mat4_mul(proj, view, viewProj);
       ...
       glm_mat4_inv(viewProj, invViewProj);

    if you have a near coord at **i** index,
    you can get it's far coord by i + 4;
    follow example below to understand that

    For instance to find center coordinates between a near and its far coord:

    .. code-block:: c

       for (j = 0; j < 4; j++) {
         glm_vec3_center(corners[i], corners[i + 4], centerCorners[i]);
       }

    corners[i + 4] is far of corners[i] point.

    Parameters:
      | *[in]*  **invMat** matrix
      | *[out]* **dest**   exracted view frustum corners

.. c:function:: void  glm_frustum_center(vec4 corners[8], vec4 dest)

    | finds center of view frustum

    Parameters:
      | *[in]*  **corners**  view frustum corners
      | *[out]* **dest**     view frustum center

.. c:function:: void  glm_frustum_box(vec4 corners[8], mat4 m, vec3 box[2])

    | finds bounding box of frustum relative to given matrix e.g. view mat

    Parameters:
      | *[in]*  **corners**  view frustum corners
      | *[in]*  **m**        matrix to convert existing conners
      | *[out]* **box**      bounding box as array [min, max]

.. c:function:: void  glm_frustum_corners_at(vec4  corners[8], float splitDist, float farDist, vec4  planeCorners[4])

    | finds planes corners which is between near and far planes (parallel)

    this will be helpful if you want to split a frustum e.g. CSM/PSSM. This will
    find planes' corners but you will need to one more plane.
    Actually you have it, it is near, far or created previously with this func ;)

    Parameters:
      | *[in]*   **corners**       frustum corners
      | *[in]*   **splitDist**     split distance
      | *[in]*   **farDist**       far distance (zFar)
      | *[out]*  **planeCorners**  plane corners [LB, LT, RT, RB]
