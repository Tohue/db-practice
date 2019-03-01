#!/bin/bash
aclocal;
autoconf;
autoheader;
automake --add-missing;
./configure;
make
./src/main
