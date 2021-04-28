### Simple GLM app for quick generation of reference values

#### Usage
1. Clone, link or copy the GLM library's root directory to `test/glm_cmp/glm`.
1. Ensuring your current directory is `test/glm_cmp`:
    `mkdir build && cd build && cmake .. && make && ./glmcmp`

Please do not delete prior reference-data-producing functions as it may be necessary to return to these to examine future bugs or assumptions. By all means remove or comment-out the call site from the `main` function, though, to focus on what you're working on.
