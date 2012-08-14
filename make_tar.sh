#! /bin/bash

autoreconf -fi &&
./configure &&
make dist &&
make distclean &&
env rm -rf `xargs < .gitignore` &&
cd build-aux/ &&
env rm -rf `xargs < .gitignore` &&
cd m4/ &&
env rm -rf `xargs < .gitignore` &&
cd .. && cd ..
