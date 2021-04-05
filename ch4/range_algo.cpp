// Copyright (c) 2021 by Chrono
//
// g++ range_algo.cpp -std=c++20 -o a.out;./a.out

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
namespace ranges = std::ranges;

void case1()
{

    vector<int> v = {1,3,5,7,9};

    ranges:for_each(v, [](auto& x){
        cout << x << endl;
    });
}


int main()
{
    case1();

    using namespace std;

    cout << "range algorithm demo" << endl;
}
