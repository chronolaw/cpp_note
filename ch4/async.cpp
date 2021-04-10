// Copyright (c) 2021 by Chrono
//
// g++ async.cpp -lpthread -std=c++17 -o a.out;./a.out
// g++ async.cpp -lpthread -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <atomic>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

void case1()
{
    auto task = [](auto x)
    {
        //using namespace std::chrono_literals;

        this_thread::sleep_for( x * 1ms);

        cout << "sleep for " << x << endl;

        return x;
    };

    auto f = std::async(task, 10);

    f.wait();

    //cout << f.valid() << endl;

    assert(f.valid());
    cout << f.get() << endl;
    assert(!f.valid());

    //cout << f.get() << endl;
    //cout << f.valid() << endl;
}

int main()
{
    case1();
    //case2();

    cout << "async demo" << endl;
}
