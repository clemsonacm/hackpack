#!/bin/bash
#A test harness that runs all the test cases for the modules

for module in $(find . -name Makefile  -not -path ./Makefile)
do
    pushd $(dirname $module) &> /dev/null
    make $1 2>&1 |grep -v "make"|grep -v "g++"
    popd &> /dev/null
done
