Pod::Spec.new do |s|

  # Description
  s.name         = "cglm"
  s.version      = "0.9.5"
  s.summary      = "📽 Highly Optimized Graphics Math (glm) for C"
  s.description  = <<-DESC
cglm is math library for graphics programming for C. See the documentation or README for all features.
                   DESC

  s.documentation_url = "http://cglm.readthedocs.io"

  # Home
  s.homepage     = "https://github.com/recp/cglm"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "Recep Aslantas" => "recp@acm.org" }

  # Sources
  s.source               = { :git => "https://github.com/recp/cglm.git", :tag => "v#{s.version}" }
  s.source_files         = "src", "include/cglm/**/*.h"
  s.public_header_files  = "include", "include/cglm/**/*.h"
  s.exclude_files        = "src/win/*", "src/dllmain.c", "src/**/*.h"
  s.preserve_paths       = "include", "src"
  s.header_mappings_dir  = "include"

  # Linking
  s.library = "m"

  # Configuration
  s.pod_target_xcconfig = {
    'CLANG_ENABLE_MODULES' => 'NO',
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
    'CLANG_WARN_DOCUMENTATION_COMMENTS' => 'NO',
    'GCC_C_LANGUAGE_STANDARD' => 'gnu11',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GLM_TESTS_NO_COLORFUL_OUTPUT'
  }
end
