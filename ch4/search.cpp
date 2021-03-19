// Copyright (c) 2021 by Chrono
//
// g++ search.cpp -std=c++17 -o a.out;./a.out
// g++ search.cpp -std=c++20 -o a.out;./a.out
// g++ search.cpp -std=c++17 -I../common -o a.out;./a.out

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
    vector<int> v = {3,5,1,7,10,99,42};

    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    // total sort
    std::sort(begin(v), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    auto found = binary_search(
        cbegin(v), cend(v), 7
    );
    cout << "found: " << found << endl;

    decltype(cend(v)) pos;

    pos = std::lower_bound(
        cbegin(v), cend(v), 7
    );
    //assert(pos != cend(v));
    //assert(*pos == 7);
    found = (pos != cend(v)) && (*pos == 7);
    assert(found);

    pos = std::lower_bound(
        cbegin(v), cend(v), 9
    );
    //assert(pos != cend(v));
    //cout << *pos << endl;
    found = (pos != cend(v)) && (*pos == 9);
    assert(!found);

    pos = std::upper_bound(
        cbegin(v), cend(v), 9
    );
    //cout << *pos << endl;

    cout << "equal_range:";
#if __cplusplus >= 201703
    auto [lower, upper] = std::equal_range(
        cbegin(v), cend(v), 7
    );
    for_each(
        lower, std::next(upper), print
    );
#else
    auto range = std::equal_range(
        cbegin(v), cend(v), 7
    );
    //cout << *range.first << endl;
    //cout << *range.second << endl;
    for_each(
        range.first, std::next(range.second), print
    );
#endif
    cout << endl;
}

void case2()
{
    multiset<int> s = {3,5,1,7,7,7,10,99,42};

    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    auto pos = s.find(7);
    assert(pos != s.end());

    auto lower_pos = s.lower_bound(7);
    auto upper_pos = s.upper_bound(7);

    for_each(
        lower_pos, upper_pos, print
    );
    cout << endl;

    auto [p1, p2] = s.equal_range(7);
    for_each(
        p1, p2, print
    );
    cout << endl;
}

void case3()
{
    vector<int> v = {1,9,11,3,5,7};

    decltype(v.end()) pos;

    pos = std::find(
        begin(v), end(v), 3
    );
    assert(pos != end(v));

    pos = std::find_if(
        begin(v), end(v),
        [](auto x) {
            return x % 2 == 0;
        }
    );
    assert(pos == end(v));

    array<int, 2> arr = {3,5};
    pos = std::find_first_of(
        begin(v), end(v),
        begin(arr), end(arr)
    );
    assert(pos != end(v));
}

int main()
{
    case1();
    case2();
    case3();

    using namespace std;

    cout << "search demo" << endl;
}
