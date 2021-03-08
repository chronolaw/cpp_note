// Copyright (c) 2021 by Chrono
//
// g++ test.cpp -std=c++17 -o a.out;./a.out
// g++ test.cpp -std=c++20 -o a.out;./a.out
// g++ test.cpp -std=c++17 -I../common -o a.out;./a.out

#include <iostream>

//#include "std.hpp"

int main()
{
    using namespace std;

    cout << "c++ version = " << __cplusplus << endl;

    cout << "gcc version = " << __VERSION__ << endl;

    cout << "gcc major = " << __GNUC__ << endl;
    cout << "gcc minor = " << __GNUC_MINOR__ << endl;
    cout << "gcc patch = " << __GNUC_PATCHLEVEL__ << endl;

    cout << "libstdc++ = " << __GLIBCXX__ << endl;
}
