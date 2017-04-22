#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

# check if deps are pulled
git submodule update --init --recursive

# fix glibtoolize

cd $(dirname "$0")

if [ "$(uname)" = "Darwin" ]; then
  libtoolBin=$(which glibtoolize)
  libtoolBinDir=$(dirname "${libtoolBin}")
  ln -s $libtoolBin "${libtoolBinDir}/libtoolize"
fi

# general deps: gcc make autoconf automake libtool cmake

# test - cmocka
cd ./test/lib/cmocka
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug ..
make -j8
cd ../../../../
