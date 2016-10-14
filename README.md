# 🎥 OpenGL Mathematics (glm) for `C`

The original glm library is for C++ only (templates, namespaces, classes...), this library targeted to C99 but currently you can use it for C89 safely by language extensions e.g `__register`


<table>
  <tbody>
    <tr>
      <td>
        <div>Like some other graphics libraries (especially OpenGL) this library use Column-Major layout to keep matrices in the memory. </div>
        <div>&nbsp;</div>
        <div>In the future the library may support an option to use row-major layout, CURRENTLY if you need to row-major layout you will need to transpose it. </div>
      </td>
      <td>
        <img src="https://upload.wikimedia.org/wikipedia/commons/3/3f/Matrix_Columns.svg" width="300px" />
      </td>
    </tr>
  </tbody>
</table>

##Features
- general purpose matrix operations (mat4, mat3)
- general purpose vector operations (cross, dot, ...)
- affine transforms
- optimized affine transform matrices (mul, rigid-body inverse)
- camera (lookat)
- projections (ortho, perspective)
- quaternions
- euler angles / yaw-pitch-roll

<hr />

This library is header only so you dont need link to application. All functions are marked inline (always_inline) so compiler probably will inline all these functions

Most of math functions are optimized manualy with SSE2 if available, if not? Dont worry there are non-sse versions of all operations

This library provides:

- Simple usage
- Small memory footprint
- The codes are small and more readable than C++ templates, metafuncs
- Optimized operations with SIMD and non-SIMD
- All operations are inline (if compiler will do), no function call overhead
- Chain matrix multiplication (square only)

You can pass matrices and vectors as array to functions rather than get address.

```C
  mat4 m = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  };

  glm_translate(m, (vec3){1.0f, 0.0f, 0.0f});
```

Library contains general purpose mat4 mul and inverse functions but also contains some special form (optimized) of these functions for affine transform matrices. If you want to multiply two affine transform matrices you can use glm_mul instead of glm_mat4_mul and glm_inv_tr (ROT + TR) instead glm_mat4_inv
```C
/* multiplication */
mat4 modelMat;
glm_mul(T, R, modelMat);

/* othonormal rot + tr matrix inverse (rigid-body) */
glm_inv_tr(modelMat);
```

##License
MIT. check the LICENSE file

##Install
Import the library to your include folder, thats it!

##Notes

- This library uses float types only, does not support Integers, Double... yet
