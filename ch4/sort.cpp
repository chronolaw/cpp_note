// Copyright (c) 2021 by Chrono
//
// g++ sort.cpp -std=c++17 -o a.out;./a.out
// g++ sort.cpp -std=c++20 -o a.out;./a.out
// g++ sort.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <random>
#include <array>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void case1()
{
    minstd_rand rand;

    vector<int> v = {3,5,1,7,10,99,42};

    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    std::reverse(begin(v), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    cout << "sorting..." << endl;

    // total sort
    std::sort(begin(v), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    std::shuffle(begin(v), end(v), rand);

    // top3
    std::partial_sort(
        begin(v), next(begin(v), 3), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    std::shuffle(begin(v), end(v), rand);

    // best3
    std::nth_element(
        begin(v), next(begin(v), 3), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    std::shuffle(begin(v), end(v), rand);

    // Median
    auto mid_iter =
        next(begin(v), size(v)/2);
    std::nth_element( begin(v), mid_iter, end(v));
    for_each(cbegin(v), cend(v), print);
    cout << "median is " << *mid_iter << endl;

    std::shuffle(begin(v), end(v), rand);

    // partition
    auto pos = std::partition(
        begin(v), end(v),
        [](const auto& x)
        {
            return x > 9;
        }
    );
    for_each(begin(v), pos, print);
    cout << endl;
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    // min/max
    auto [mi, ma] = std::minmax_element(
        cbegin(v), cend(v)
    );
    cout << *mi << ","
         << *ma << endl;
}

int main()
{
    case1();
    //case2();

    using namespace std;

    cout << "sort demo" << endl;
}
