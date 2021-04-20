#!/bin/sh

#GCC=gcc:10
#GCC=gcc:7

#GCC=chronolaw/cpp_note:gcc10
#GCC=chronolaw/cpp_note:gcc7

GCC=gcc7

if [ $# -ne 0 ]; then
    #echo $1
    GCC=$1
fi

#echo ${GCC}
#exit

IMAGE="chronolaw/cpp_note:${GCC}"

#docker run -it --rm -v ${PWD}:/tmp:ro ${GCC}
#docker run -it --rm -v ${PWD}:/tmp ${GCC}

#docker run -it --rm  ${IMAGE}
docker run -it --rm -v ${PWD}:/tmp ${IMAGE}

