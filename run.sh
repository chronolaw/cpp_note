#!/bin/sh

#GCC=gcc:10
#GCC=gcc:7

#GCC=chronolaw/cpp_note:gcc10
GCC=chronolaw/cpp_note:gcc7

#echo ${GCC}

#docker run -it --rm -v ${PWD}:/tmp:ro ${GCC}
docker run -it --rm -v ${PWD}:/tmp ${GCC}

