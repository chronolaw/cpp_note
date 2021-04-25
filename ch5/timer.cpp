// Copyright (c) 2021 by Chrono
//
// g++ timer.cpp -std=c++17 -o a.out;./a.out
// g++ timer.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::timer;

void case1()
{
    cpu_timer t;
}

int main()
{
    case1();

    cout << "timer demo" << endl;
}
