.. default-domain:: C

euler angles
============

Header: cglm/euler.h

You may wonder what **glm_euler_sq** type ( **_sq** stands for sequence ) and
:c:func:`glm_euler_by_order` do.
I used them to convert euler angles in one coordinate system to another. For
instance if you have **Z_UP** euler angles and if you want to convert it
to **Y_UP** axis then :c:func:`glm_euler_by_order` is your friend. For more
information check :c:func:`glm_euler_order` documentation

You must pass arrays as array, if you use C compiler then you can use something
like this:

.. code-block:: c

   float pitch, yaw, roll;
   mat4  rot;

   /* pitch = ...; yaw = ...; roll = ... */
   glm_euler((vec3){pitch, yaw, roll}, rot);

Rotation Conveniention
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Current *cglm*'s euler functions uses these convention:

* Tait–Bryan angles (x-y-z convention)
* Intrinsic rotations (pitch, yaw and roll).
  This is reserve order of extrinsic (elevation, heading and bank) rotation
* Right hand rule (actually all rotations in *cglm* use **RH**)
* All angles used in *cglm* are **RADIANS** not degrees


**NOTE**: The default :c:func:`glm_euler` function is the short name of
:c:func:`glm_euler_xyz` this is why you can't see :c:func:`glm_euler_xyz`.
When you see an euler function which doesn't have any X, Y, Z suffix then
assume that uses **_xyz** (or instead it accept order as parameter).

If rotation doesn't work properly, your options:

1. If you use (or paste) degrees convert it to radians before calling an euler function

.. code-block:: c

   float pitch, yaw, roll;
   mat4  rot;

   /* pitch = degrees; yaw = degrees; roll = degrees */
   glm_euler((vec3){glm_rad(pitch), glm_rad(yaw), glm_rad(roll)}, rot);

2. Convention mismatch. You may have extrinsic angles,
   if you do (if you must) then consider to use reverse order e.g if you have
   **xyz** extrinsic then use **zyx**

3. *cglm* may implemented it wrong, consider to create an issue to report it
   or pull request to fix it

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Types:

1. glm_euler_sq

Functions:

1. :c:func:`glm_euler_order`
#. :c:func:`glm_euler_angles`
#. :c:func:`glm_euler`
#. :c:func:`glm_euler_xyz`
#. :c:func:`glm_euler_zyx`
#. :c:func:`glm_euler_zxy`
#. :c:func:`glm_euler_xzy`
#. :c:func:`glm_euler_yzx`
#. :c:func:`glm_euler_yxz`
#. :c:func:`glm_euler_by_order`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: glm_euler_sq  glm_euler_order(int ord[3])

    | packs euler angles order to glm_euler_sq enum.

    To use :c:func:`glm_euler_by_order` function you need *glm_euler_sq*. You
    can get it with this function.

    You can build param like this:

    | X = 0, Y = 1, Z = 2

    if you have ZYX order then you pass this: [2, 1, 0] = ZYX.
    if you have YXZ order then you pass this: [1, 0, 2] = YXZ

    As you can see first item specifies which axis will be first then the
    second one specifies which one will be next an so on.

    Parameters:
      | *[in]*  **ord**  euler angles order [Angle1, Angle2, Angle2]

    Returns:
      packed euler order

.. c:function:: void  glm_euler_angles(mat4 m, vec3 dest)

    | extract euler angles (in radians) using xyz order

    Parameters:
      | *[in]*  **m**     affine transform
      | *[out]* **dest**  angles vector [x, y, z]

.. c:function:: void  glm_euler(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    this is alias of glm_euler_xyz function

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_xyz(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_zyx(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_zxy(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_xzy(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_yzx(vec3 angles, mat4 dest)

    build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void  glm_euler_yxz(vec3 angles, mat4 dest)

    | build rotation matrix from euler angles

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **dest**    rotation matrix

.. c:function:: void glm_euler_by_order(vec3 angles, glm_euler_sq ord, mat4 dest)

    | build rotation matrix from euler angles with given euler order.

    Use :c:func:`glm_euler_order` function to build *ord* parameter

    Parameters:
      | *[in]*  **angles**  angles as vector [Xangle, Yangle, Zangle]
      | *[in]*  **ord**     euler order
      | *[in]*  **dest**    rotation matrix
