// Copyright (c) 2021 by Chrono
//
// g++ call_once.cpp -lpthread -std=c++17 -o a.out;./a.out
// g++ call_once.cpp -lpthread -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <mutex>
#include <thread>

using namespace std;

void case1()
{
    static once_flag flag;

    auto f = []()
    {
        cout << "tid=" <<
            this_thread::get_id() << endl;

        std::call_once(flag,
            [](){
                cout << "only once" << endl;
            }
        );
    };

    thread t1(f);
    thread t2(f);

    t1.join();
    t2.join();
}


int main()
{
    case1();

    cout << "call_once demo" << endl;
}
