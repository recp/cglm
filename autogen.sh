#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

cd $(dirname "$0")

autoheader

if [ "$(uname)" = "Darwin" ]; then
  glibtoolize
else
  libtoolize
fi

aclocal -I m4
autoconf
automake --add-missing --copy
