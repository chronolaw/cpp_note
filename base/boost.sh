#!/bin/bash

VER_DOT='1.75.0'
VER_DASH='1_75_0'

#wget https://dl.bintray.com/boostorg/release/${VER_DOT}/source/boost_${VER_DASH}.tar.gz

tar xfz boost_${VER_DASH}.tar.gz
cd boost_${VER_DASH}


./bootstrap.sh
./b2 tools/bcp

./dist/bin/bcp lexical_cast ..
./dist/bin/bcp string_algo ..
./dist/bin/bcp property_tree ..
