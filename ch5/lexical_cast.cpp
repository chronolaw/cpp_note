// Copyright (c) 2021 by Chrono
//
// g++ lexical_cast.cpp -std=c++17 -o a.out;./a.out
// g++ lexical_cast.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

void case1()
{
    auto n1 = lexical_cast<short>("42");
    auto n2 = lexical_cast<int>("100");
    auto n3 = lexical_cast<long>("64");

    assert(n1 == 42);
    assert(n2 == 100);
    assert(n3 == 64);
}

void case2()
{
    auto s1 = lexical_cast<string>(42);
    auto s2 = lexical_cast<string>(0x64);

    assert(s1 == "42");
    assert(s2 == "100");
}

int main()
{
    case1();
    case2();

    cout << "lexical_cast demo" << endl;
}
