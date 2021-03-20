// Copyright (c) 2021 by Chrono
//
// g++ atomic.cpp -lpthread -std=c++17 -o a.out;./a.out
// g++ atomic.cpp -lpthread -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <atomic>
#include <thread>

using namespace std;


void case1()
{
    atomic_int  x {0};
    atomic_long y {1000L};

    assert(++x == 1);
    y += 200;
    assert(y < 2000);
}

void case2()
{
    atomic_uint  x {0};

    x.store(10);
    assert(x.load() == 10);

    auto v = x.fetch_add(5);
    assert(v == 10 && x == 15);

    v = x.fetch_sub(2);
    assert(v == 15 && x == 13);

    auto u = x.exchange(100);
    assert(u == 13 && x == 100);

    unsigned int w = 100;
    auto flag = x.compare_exchange_strong(w, 42);
    assert(flag && x == 42);

    w = 0;
    flag = x.compare_exchange_strong(w, 10);
    assert(!flag && w == 42);
}

void case3()
{
    static atomic_flag flag {false};
    static atomic_int  n;

    auto f = [&]()
    {
        auto value = flag.test_and_set();

        if (value) {
            cout << "flag has been set." << endl;
        } else {
            cout << "set flag by " <<
                this_thread::get_id() << endl;
        }

        n += 100;

        //using namespace std::chrono_literals;

        this_thread::sleep_for(n.load() * 10ms);
        cout << n << endl;

    };

    thread t1(f);
    thread t2(f);

    t1.join();
    t2.join();
}


int main()
{
    case1();
    case2();
    case3();

    cout << "atomic demo" << endl;
}
