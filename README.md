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

This library is header only so you dont need link to application. All functions are marked inline (always_inline) so compiler probably will inline all these functions

Most of math functions are optimized manualy with SSE2 if available, if not? Dont worry there are non-sse versions of all operations

Why manual? Because this will decrease *compile time* and some operations are faster than compiler optimization. 

This library offers:

- Simple usage
- Small memory usage
- Fast compiling time
- The codes are small and more readable than C++ templates, metafuncs
- Optimized operations with SIMD and non-SIMD
- Small code size
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

##License
MIT. check the LICENSE file

##Install
Import the library to your include folder, thats it!

##Notes

- This library uses float types only, does not support Integers, Double... yet
