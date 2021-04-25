// Copyright (c) 2021 by Chrono
//
// g++ timer.cpp -std=c++17 -lboost_timer -o a.out;./a.out
// g++ timer.cpp -std=c++20 -lboost_timer -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <thread>

#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::timer;

void case1()
{
    cpu_timer t;

    for (int i = 0; i < 3; i++) {
        t.start();
        this_thread::sleep_for(100ms);

        t.stop();
        this_thread::sleep_for(50ms);
        assert(t.is_stopped());
        t.resume();

        cout << t.format() << endl;
    }
}

void case2()
{
    cpu_timer t;

    this_thread::sleep_for(1ms);

    auto x = t.elapsed();

    cout << "wall: " << x.wall/1000 << endl;
    cout << "user: " << x.user << endl;
    cout << "sys: " << x.system << endl;
}

int main()
{
    case1();
    case2();

    cout << "timer demo" << endl;
}
