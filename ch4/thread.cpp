// Copyright (c) 2021 by Chrono
//
// g++ thread.cpp -lpthread -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <atomic>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

void case1()
{
    auto task = [](bool flag)
    {
        auto tid = this_thread::get_id();

        if (flag) {
            cout << tid << "thread yield" << endl;
            this_thread::yield();
        }

        auto time = chrono::system_clock::now() + 100ms;
        this_thread::sleep_until(time);

        cout << tid << " sleep until" << endl;
    };

    thread t1(task, true);
    thread t2(task, false);

    t1.join();
    t2.join();
}

void case2()
{
    auto task = []()
    {
        this_thread::sleep_for(1s);

        cout << "sleep for 1s" << endl;
    };

    //thread t1(task);
    //t1.join();

    jthread {task};
}

int main()
{
    case1();
    case2();

    cout << "thread demo" << endl;
}
