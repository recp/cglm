Features
================================================================================

* **scalar** and **simd** (sse, avx, neon...) optimizations
* option to use different clipspaces e.g. Left Handed, Zero-to-One... (currrently right handed negative-one is default)
* array api and struct api, you can use arrays or structs.
* general purpose matrix operations (mat4, mat3)
* chain matrix multiplication (square only)
* general purpose vector operations (cross, dot, rotate, proj, angle...)
* affine transformations
* matrix decomposition (extract rotation, scaling factor)
* optimized affine transform matrices (mul, rigid-body inverse)
* camera (lookat)
* projections (ortho, perspective)
* quaternions
* euler angles / yaw-pitch-roll to matrix
* extract euler angles
* inline or pre-compiled function call
* frustum (extract view frustum planes, corners...)
* bounding box (AABB in Frustum (culling), crop, merge...)
* bounding sphere
* project, unproject
* easing functions
* curves
* curve interpolation helpers (SMC, deCasteljau...)
* helpers to convert cglm types to Apple's simd library to pass cglm types to Metal GL without packing them on both sides
* ray intersection helpers
* and others...
