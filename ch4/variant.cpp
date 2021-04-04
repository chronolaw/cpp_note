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


int main()
{
    case1();

    cout << "variant demo" << endl;
}
