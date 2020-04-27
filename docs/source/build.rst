Build cglm
================================

| **cglm** does not have any external dependencies.

**NOTE:**
If you only need to inline versions, you don't need to build **cglm**, you don't need to link it to your program.
Just import cglm to your project as dependency / external lib by copy-paste then use it as usual

CMake (All platforms):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash
  :linenos:

  $ mkdir build
  $ cd build
  $ cmake .. # [Optional] -DCGLM_SHARED=ON
  $ make
  $ sudo make install # [Optional]

**make** will build cglm to **build** folder.
If you don't want to install **cglm** to your system's folder you can get static and dynamic libs in this folder.

**CMake Options:**

.. code-block:: CMake
  :linenos:

  option(CGLM_SHARED "Shared build" ON)
  option(CGLM_STATIC "Static build" OFF)
  option(CGLM_USE_C99 "" OFF) # C11 
  option(CGLM_USE_TEST "Enable Tests" OFF) # for make check - make test

**Use with your CMake project example**

.. code-block:: CMake
  :linenos:

  cmake_minimum_required(VERSION 3.8.2)
  
  project(<Your Project Name>)
  
  add_executable(${PROJECT_NAME} src/main.c)
  target_link_libraries(${LIBRARY_NAME} PRIVATE
    cglm)
  
  add_subdirectory(external/cglm/)

Unix (Autotools):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash
  :linenos:

  $ sh autogen.sh
  $ ./configure
  $ make
  $ make check            # run tests (optional)
  $ [sudo] make install   # install to system (optional)

**make** will build cglm to **.libs** sub folder in project folder.
If you don't want to install **cglm** to your system's folder you can get static and dynamic libs in this folder.

Windows (MSBuild):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Windows related build files, project files are located in `win` folder,
make sure you are inside in cglm/win folder.

Code Analysis are enabled, it may take awhile to build.

.. code-block:: bash
  :linenos:

  $ cd win
  $ .\build.bat

if *msbuild* is not worked (because of multi versions of Visual Studio)
then try to build with *devenv*:

.. code-block:: bash
  :linenos:

  $ devenv cglm.sln /Build Release

Currently tests are not available on Windows.

Documentation (Sphinx):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**cglm** uses sphinx framework for documentation, it allows lot of formats for documentation. To see all options see sphinx build page:

https://www.sphinx-doc.org/en/master/man/sphinx-build.html

Example build:

.. code-block:: bash
  :linenos:

  $ cd cglm/docs
  $ sphinx-build source build
