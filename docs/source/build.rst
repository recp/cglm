Build cglm
================================

| **cglm** does not have external dependencies except for unit testing. When you pulled **cglm** repo with submodules all dependencies will be pulled too. `build-deps.sh` will pull all dependencies/submodules and build for you.

External dependencies:
  * cmocka - for unit testing

**NOTE:**
If you only need to inline versions, you don't need to build **cglm**, you don't need to link it to your program.
Just import cglm to your project as dependency / external lib by copy-paste then use it as usual

Unix (Autotools):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash
  :linenos:

  $ sh ./build-deps.sh    # run this only once (dependencies)

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

