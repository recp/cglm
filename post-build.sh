#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

cd $(dirname "$0")

mkdir -p "$(pwd)/.libs"

libmocka_folder=$(pwd)/test/lib/cmocka/build/src/

if [ "$(uname)" = "Darwin" ]; then
  libcmocka=libcmocka.0.dylib
else
  libcmocka=libcmocka.so.0
fi

libcmocka_path="$libmocka_folder$libcmocka"
if [ -f "$libcmocka_path" ]; then
  ln -sf "$libcmocka_path" "$(pwd)/.libs/$libcmocka";
fi
