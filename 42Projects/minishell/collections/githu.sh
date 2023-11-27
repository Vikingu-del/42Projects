#!/bin/bash

set -e

PREFIX="$HOME/.local/pkg/readline"
VERSION=8.2

if [ "$(uname -s)" == 'Darwin' ]; then
	cd /private/tmp
else
	cd /tmp
fi

echo ':: Cleaning previous build'
rm -rf "readline-$VERSION"
rm -rf "$PREFIX"

echo ':: Downloading and extracting'
curl -# "https://ftp.gnu.org/gnu/readline/readline-$VERSION.tar.gz" | tar xzf -

echo ':: Building and installing'
cd "readline-$VERSION"
./configure --prefix="$PREFIX"
make -j$(nproc)
make install-static

echo ':: Cleaning up temporary workspace'
cd ..
rm -rf "readline-$VERSION"

echo
echo '< All done, have fun :) >'
