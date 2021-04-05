// Copyright (c) 2021 by Chrono
//
// g++ range_algo.cpp -std=c++17 -o a.out;./a.out
// g++ range_algo.cpp -std=c++20 -o a.out;./a.out
// g++ range_algo.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <random>
#include <array>
#include <vector>

#if __cplusplus <= 201703L
#error "needs C++20 or higher"
#endif

#include <ranges>
#include <algorithm>

using namespace std;

void case1()
{

}


int main()
{
    case1();

    using namespace std;

    cout << "range algorithm demo" << endl;
}
