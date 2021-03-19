// Copyright (c) 2021 by Chrono
//
// g++ for_each.cpp -std=c++17 -o a.out;./a.out
// g++ for_each.cpp -std=c++20 -o a.out;./a.out
// g++ for_each.cpp -std=c++17 -I../common -o a.out;./a.out

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
#if 1
    vector<int> v = {3,5,1,7,10};

    for(const auto& x : v) {
        cout << x << ",";
    }
#endif
    cout << endl;

#if 1
    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    for_each(cbegin(v), cend(v), print);
#endif
    cout << endl;

#if 1
    for_each(
        cbegin(v), cend(v),
        [](const auto& x)
        {
            cout << x << ",";
        }
    );
#endif
    cout << endl;

}

void case2()
{
    vector<int> v = {3,5,1,7,10};

// it can not work in gcc 7.5
#if __cplusplus >= 202002
    for_each_n(
        cbegin(v), 3,
        [](const auto& x)
        {
            cout << x*x << ",";
        }
    );
#endif
    cout << endl;
}

int main()
{
    case1();
    case2();

    using namespace std;

    cout << "for_each demo" << endl;
}
