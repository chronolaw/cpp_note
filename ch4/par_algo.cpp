// Copyright (c) 2021 by Chrono
//
// g++ par_algo.cpp -std=c++20 -o a.out;time ./a.out

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

#include <ranges>
#include <algorithm>

using namespace std;

namespace ranges = std::ranges;
namespace views = std::views;

auto print = [](const auto& x){
    cout << x << ",";
};

void case1()
{
    minstd_rand rand;
    vector<string> v(1000 * 10);

    //cout << to_string(rand());
    ranges::generate(v, [&](){
        return to_string(rand());
    });

    //ranges::for_each(v | views::take(10), print);

    std::sort(execution::par, begin(v), end(v));
    //std::sort(begin(v), end(v));

    //cout << endl;
}


int main()
{
    case1();

    using namespace std;

    cout << "par algorithm demo" << endl;
}
