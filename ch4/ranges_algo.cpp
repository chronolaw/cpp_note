// Copyright (c) 2021 by Chrono
//
// g++ ranges_algo.cpp -std=c++20 -o a.out;./a.out

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

    vector<int> v = {9,5,1,7,3};

    auto print = [](const auto& x){
        cout << x << ",";
    };

    ranges::for_each(v, print);
    cout << endl;

    cout << ranges::count_if(
        v, [](auto& x){
                return x >= 5;
            })
    << endl;

    ranges::stable_sort(v);
    ranges::for_each(v, print);
    cout << endl;

    assert(ranges::binary_search(v, 7));

    auto pos = ranges::lower_bound(v, 3);
    assert(pos != end(v) && *pos == 3);
}


int main()
{
    case1();

    using namespace std;

    cout << "ranges algorithm demo" << endl;
}
