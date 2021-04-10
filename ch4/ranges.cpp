// Copyright (c) 2021 by Chrono
//
// g++ ranges.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <random>
#include <string>
#include <array>
#include <vector>

#if __cplusplus <= 201703L
#error "needs C++20 or higher"
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
    vector<int> v = {9,5,1,7,3};

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

    cout << endl;
}

void case2()
{
    minstd_rand rand;

    vector<int> v = {9,5,1,7,3};

    ranges::shuffle(v, rand);
    cout << endl;

    ranges::partial_sort(v, next(begin(v), 3));
    ranges::for_each(v, print);

    ranges::shuffle(v, rand);
    cout << endl;

    auto [mi, ma] = ranges::minmax_element(v);
    cout << *mi << ","
         << *ma << endl;
    cout << endl;
}

void case3()
{
    vector<int> v = {3,7,2,4,9,6,8,1,5};

    for (auto&& x : v | views::drop(3) | views::reverse) {
        cout << x << ",";
    }
    cout << endl;

    auto r1 = v | views::drop(3);
    auto r2 = r1 | views::reverse;

    ranges::for_each(r2, print);
    cout << endl;

    cout << endl;
}

void case4()
{

    vector<int> v = {3,7,2,4,9,6,8,1,5};

    ranges::for_each(v, print);
    cout << endl;

#if 0
    auto r1 =  v | views::filter(
                [](auto& x) {
                    return x % 2 == 0;
                }) ;
    ranges::for_each(r1, print);
    cout << endl;
#endif

    ranges::for_each(
            v | views::filter(
                [](auto& x) {
                    return x % 2 == 0;
                }),
        print
    );
    cout << endl;

    decltype(v) v2;
    ranges::copy(v | views::take(3), back_inserter(v2));

    ranges::for_each(v2, print);
    cout << endl;

    vector<pair<int,string>> pairs = {
        {1, "one"}, {2, "two"}, {3, "three"}
    };

    ranges::for_each(
        pairs | views::take(2) | views::values,
        print
    );
    cout << endl;

    cout << endl;
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "ranges algorithm demo" << endl;
}
