#!/bin/sh

GCC=gcc:10
#echo ${GCC}

docker run -it --rm -v ${PWD}:/tmp ${GCC}

