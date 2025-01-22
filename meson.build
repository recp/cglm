project('cglm', 'c',
    version : '0.9.5',
    license : 'mit',
    default_options : [
        'c_std=c11',
        'warning_level=2',
        'buildtype=release'
    ]
)

cc = meson.get_compiler('c')

cglm_install = get_option('install')
cglm_deps = cc.find_library('m', required : false)

cglm_args = []
build_args = []

if get_option('default_library') == 'static'
    cglm_args += '-DCGLM_STATIC'
endif

if cc.compiles(
    'int *test(char *p) { return (int*)__builtin_assume_aligned(p, 4); }',
    name : '__builtin_assume_aligned test')
    cglm_args += '-DCGLM_HAVE_BUILTIN_ASSUME_ALIGNED=1'
else
    cglm_args += '-DCGLM_HAVE_BUILTIN_ASSUME_ALIGNED=0'
endif

if host_machine.system() == 'windows'
    build_args += '-DCGLM_EXPORTS'
endif

cglm_inc = include_directories('include')

cglm_src = files(
    'src/euler.c',
    'src/affine.c',
    'src/io.c',
    'src/quat.c',
    'src/cam.c',
    'src/vec2.c',
    'src/ivec2.c',
    'src/vec3.c',
    'src/ivec3.c',
    'src/vec4.c',
    'src/ivec4.c',
    'src/mat2.c',
    'src/mat2x3.c',
    'src/mat2x4.c',
    'src/mat3.c',
    'src/mat3x2.c',
    'src/mat3x4.c',
    'src/mat4.c',
    'src/mat4x2.c',
    'src/mat4x3.c',
    'src/plane.c',
    'src/noise.c',
    'src/frustum.c',
    'src/box.c',
    'src/aabb2d.c',
    'src/project.c',
    'src/sphere.c',
    'src/ease.c',
    'src/curve.c',
    'src/bezier.c',
    'src/ray.c',
    'src/affine2d.c',
    'src/clipspace/ortho_lh_no.c',
    'src/clipspace/ortho_lh_zo.c',
    'src/clipspace/ortho_rh_no.c',
    'src/clipspace/ortho_rh_zo.c',
    'src/clipspace/persp_lh_no.c',
    'src/clipspace/persp_lh_zo.c',
    'src/clipspace/persp_rh_no.c',
    'src/clipspace/persp_rh_zo.c',
    'src/clipspace/view_lh_no.c',
    'src/clipspace/view_lh_zo.c',
    'src/clipspace/view_rh_no.c',
    'src/clipspace/view_rh_zo.c',
    'src/clipspace/project_no.c',
    'src/clipspace/project_zo.c'
)

cglm_lib = library('cglm',
    cglm_src,
    install : cglm_install,
    dependencies : cglm_deps,
    c_args : [ build_args, cglm_args ],
    version : meson.project_version(),
    soversion : '0',
    build_by_default: not meson.is_subproject()
)

cglm_dep = declare_dependency(
    link_with : cglm_lib,
    dependencies : cglm_deps,
    compile_args : cglm_args,
    include_directories : cglm_inc,
    version : meson.project_version()
)

if meson.version().version_compare('>= 0.54.0')
    meson.override_dependency('cglm', cglm_dep)
endif

if cglm_install
    install_subdir('include/cglm', install_dir : get_option('includedir'))

    pkg = import('pkgconfig')
    pkg.generate(
        name : 'cglm',
        libraries : cglm_lib,
        extra_cflags : cglm_args,
        version : meson.project_version(),
        url : 'https://github.com/recp/cglm',
        description : 'OpenGL Mathematics (glm) for C'
    )
endif

if get_option('build_tests') == true

test_src = files(
    'test/runner.c',
    'test/src/test_bezier.c',
    'test/src/test_clamp.c',
    'test/src/test_common.c',
    'test/src/test_euler.c',
    'test/src/tests.c',
    'test/src/test_struct.c',
)

test_exe = executable('tests',
    test_src,
    dependencies : cglm_dep,
    c_args : '-DGLM_TESTS_NO_COLORFUL_OUTPUT'
)

test('cglm.tests', test_exe)

endif
