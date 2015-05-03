#!/bin/bash
#A test harness that runs all the test cases for the modules

toplevel=$(pwd)
for module in $(find . -name Makefile  -not -path ./Makefile)
do
    cd $(dirname $module)
    make $1 2>&1 |grep -v "make"|grep -v "g++"
    cd $toplevel
done
