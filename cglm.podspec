Pod::Spec.new do |s|

  # Description
  s.name         = "cglm"
  s.version      = "0.5.1"
  s.summary      = "📽 Optimized OpenGL/Graphics Math (glm) for C"
  s.description  = <<-DESC
cglm is math library for graphics programming for C. It is similar to original glm but it is written for C instead of C++ (you can use here too). See the documentation or README for all features.
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
end
