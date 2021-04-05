// Copyright (c) 2021 by Chrono
//
// g++ variant.cpp -std=c++17 -o a.out;./a.out
// g++ variant.cpp -std=c++20 -o a.out;./a.out
// g++ variant.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;

void case1()
{
    union {
        int     n;
        float   f;
        double  d;
    } x;

    x.d = 3.14;
    x.n = 10;
    assert(x.n == 10);

}

void case2()
{
    variant<int, float, double> v;

    v = 42;
    assert(v.index() == 0);
    assert(get<0>(v) == 42);

    v = 3.14f;
    assert(v.index() == 1);

    v = 2.718;
    assert(v.index() == 2);

    auto x = get<double>(v);
    cout << x << endl;

    auto p = get_if<int>(&v);
    assert(p == nullptr);
}


int main()
{
    case1();
    case2();

    cout << "variant demo" << endl;
}
