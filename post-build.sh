#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

cd $(dirname "$0")

mkdir -p .libs

if [ "$(uname)" = "Darwin" ]; then
  ln -sf $(pwd)/test/lib/cmocka/build/src/libcmocka.0.dylib \
      .libs/libcmocka.0.dylib;
else
  ln -sf $(pwd)/test/lib/cmocka/build/src/libcmocka.so.0 \
      .libs/libcmocka.so.0;
fi
