#!/bin/sh

GCC=gcc:10
#GCC=gcc:7

#echo ${GCC}

docker run -it --rm -v ${PWD}:/tmp ${GCC}

