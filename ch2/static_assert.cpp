// Copyright (c) 2021 by Chrono
//
// g++ static_assert.cpp -Werror -std=c++17 -o a.out;./a.out
// g++ static_assert.cpp -Werror -std=c++20 -o a.out;./a.out
//

#include <cassert>

#include <typeinfo>
#include <iostream>
#include <type_traits>

void case1()
{
    int     i = 10;
    int    *p = &i;

    assert(i > 0 && "i must be greater than zero");
    assert(p != nullptr);

    std::string str = "hello";
    assert(!str.empty());
}

void case2()
{
    static_assert(sizeof(int) == 4, "int must be 32bit");
    static_assert(sizeof(long) >= 8, "must run on x64");
}

template<typename T>
void check_type(T v)
{
    using namespace std;

    //static_assert(is_integral_v<T>, "int");
    static_assert(is_pointer_v<T>, "ptr");
    //static_assert(is_default_constructible_v<T>, "is_default_constructible");

    cout << "static_assert : " << typeid(v).name() << endl;

    cout << is_void_v<void> << endl;
}

int main()
{
    using namespace std;

    case1();
    case2();

    //check_type(10);
    check_type((void*)0);

    cout << "static_assert demo" << endl;
}
