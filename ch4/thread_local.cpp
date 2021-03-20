// Copyright (c) 2021 by Chrono
//
// g++ thread_local.cpp -lpthread -std=c++17 -o a.out;./a.out
// g++ thread_local.cpp -lpthread -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <thread>

using namespace std;

void case1()
{
    //static int n = 0;
    thread_local int n = 0;

    auto f = [&](int x)
    {
        n += x;

        cout << n;
        cout << ", tid=" <<
            this_thread::get_id() << endl;
    };

    thread t1(f, 10);
    thread t2(f, 20);

    t1.join();
    t2.join();
}



int main()
{
    case1();

    cout << "thread_local demo" << endl;
}
