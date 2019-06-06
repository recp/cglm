#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

# check if deps are pulled
git submodule update --init --recursive

cd $(dirname "$0")

# general deps: gcc make autoconf automake libtool cmake

# test - cmocka
cd ./test/lib/cmocka
rm -rf build
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug ..
make -j8
cd ../../../../
