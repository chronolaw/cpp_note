// Copyright (c) 2021 by Chrono
//
// g++ unique_ptr.cpp -std=c++17 -o a.out;./a.out
// g++ unique_ptr.cpp -std=c++20 -o a.out;./a.out
// g++ unique_ptr.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <memory>
#include <string>

#if 1
template<class T, class... Args>
std::unique_ptr<T>
my_make_unique(Args&&... args)
{
    return std::unique_ptr<T>(
            new T(std::forward<Args>(args)...));
}
#endif

void case1()
{
    using namespace std;

    unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 == 10);
    assert(ptr1 != nullptr);

    unique_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");
    assert(ptr2->size() == 5);

    //ptr1++;
    //ptr2 += 2;

    //unique_ptr<int> ptr3;
    //*ptr3 = 42;

    auto ptr3 = make_unique<int>(42);
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_unique<string>("god of war");
    assert(!ptr4->empty());

    auto ptr5 = my_make_unique<long>(100L);
    assert(*ptr5 == 100);
}

void case2()
{
    using namespace std;

    auto ptr1 = make_unique<int>(42);
    assert(ptr1 && *ptr1 == 42);

    auto ptr2 = std::move(ptr1);
    assert(!ptr1 && ptr2);
}

int main()
{
    using namespace std;

    case1();
    case2();

    cout << "unique_ptr demo" << endl;
}
