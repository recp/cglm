How to send vector or matrix to OpenGL like API
==================================================

*cglm*'s vector and matrix types are arrays. So you can send them directly to a
function which accepts pointer. But you may got warnings for matrix because it is
two dimensional array.

Passing / Uniforming Matrix to OpenGL:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**glUniformMatrix4fv** accepts float pointer, you can pass matrix to that parameter
and it should work but with warnings. "You can pass" doesn't mean that you must pass like that.

**Correct options:**

Correct doesn't mean correct way to use OpenGL it is just shows correct way to pass cglm type to it.

1. Pass first column
---------------------

The goal is that pass address of matrix, first element of matrix is also address of matrix,
because it is array of vectors and vector is array of floats.

.. code-block:: c

   mat4 matrix;
   /* ... */
   glUniformMatrix4fv(location, 1, GL_FALSE, matrix[0]);

array of matrices:

.. code-block:: c

   mat4 matrix;
   /* ... */
   glUniformMatrix4fv(location, count, GL_FALSE, matrix[0][0]);

1. Cast matrix to pointer
--------------------------

.. code-block:: c

   mat4 matrix;
   /* ... */
   glUniformMatrix4fv(location, count, GL_FALSE, (float *)matrix);

in this way, passing array of matrices is same

Passing / Uniforming Vectors to OpenGL:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You don't need to do extra thing when passing cglm vectors to OpengL or other APIs.
Because a function like **glUniform4fv** accepts vector as pointer. cglm's vectors
are array of floats. So you can pass it directly to those functions:

.. code-block:: c

   vec4 vec;
   /* ... */
   glUniform4fv(location, 1, vec);

this show how to pass **vec4** others are same.
