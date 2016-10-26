#! /bin/sh
#
# Copyright (c), Recep Aslantas.
#
# MIT License (MIT), http://opensource.org/licenses/MIT
# Full license can be found in the LICENSE file
#

cd `dirname "$0"`

if [ "`uname`" = "Darwin" ]; then
  libtoolBin=$(which glibtoolize)
  libtoolBinDir=$(dirname "${libtoolBin}")
  ln -s $libtoolBin "${libtoolBinDir}/libtoolize"
fi

autoheader
libtoolize
aclocal -I m4
autoconf
automake --add-missing --copy
