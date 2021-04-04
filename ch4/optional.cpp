// Copyright (c) 2021 by Chrono
//
// g++ optional.cpp -std=c++17 -o a.out;./a.out
// g++ optional.cpp -std=c++20 -o a.out;./a.out
// g++ optional.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <optional>

using namespace std;

void case1()
{
    optional<int> op;
    assert(!op);
}


int main()
{
    case1();

    cout << "optional demo" << endl;
}
