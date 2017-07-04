# CONTRIBUTING

Any contributions (code, documentation, ...) are welcome. This project uses [cmocka](http://cmocka.org) for testing, you may need to check their documentation 

# New Features
- This library may not accept all new features, it is better to create an issue and get approval before coding
- You must add test for every new feature
- The feature must be compiled in both UNIX/POSIX systems (e.g. macos, linux...) and Windows

# Code Style
This library is written with C99, don't try to add C++ files (yes it can compiled into lib),
if you have enough reason to add C++ files than create an issue and get approval before coding,

- All functions must have `glm` prefix
- Lines should be wrapped at 80 characters.
- Don't invent new style for existing ones
- Use C89 style comments (`/* comments */`) not C++ style comments (`// comments`)
- Don't use TABs instead use 2 spaces for TABs
- All indents must be 2 spaces, not 1 nor 4 space
- All functions in `include` folder must be exported by `CGLM_EXPORT` and wrapped by `extern "C" {` for C++
- Crate new line for return type, attribs:

```C
CGLM_INLINE
void
glm_mul(mat4 m1, mat4 m2, mat4 dest)
```

not acceptable:

```C
CGLM_INLINE void glm_mul(mat4 m1, mat4 m2, mat4 dest)
```
- Variables must be declared at the top of a scope before usage:
```C
int x;
int y;

x = y = 0;
```

not acceptable:

```C
int x;

x = 0;
int y = 0;
```

- All files must retain same LICENSE statement
- Code with warnings will not be accepted, please suppress them (not by disabling them)
- Run code anaylysis before submitting pull requests, if you use Xcode you can enable Sanitizer in scheme, you can use valgrind in linux
