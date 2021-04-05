// Copyright (c) 2021 by Chrono
//
// g++ par_algo.cpp -std=c++17 -o a.out;./a.out
// g++ par_algo.cpp -std=c++20 -o a.out;./a.out
// g++ par_algo.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <random>
#include <array>
#include <vector>

#if __has_include(<execution>)
#include <execution>
#else
#error "no <execution> header file"
#endif

#include <algorithm>

using namespace std;

void case1()
{

}


int main()
{
    case1();

    using namespace std;

    cout << "par algorithm demo" << endl;
}
