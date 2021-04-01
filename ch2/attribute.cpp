// Copyright (c) 2020 by Chrono
//
// g++ attribute.cpp -Werror -std=c++17 -o a.out;./a.out
// g++ attribute.cpp -Werror -std=c++20 -o a.out;./a.out
// g++ attribute.cpp -Wno-deprecated-declarations -std=c++17 -o a.out;
// g++ attribute.cpp -Wno-deprecated-declarations -std=c++20 -o a.out;
//

#include <cassert>

#include <typeinfo>
#include <string>
#include <iostream>
#include <stdexcept>


//[[gnu::deprecated]] // c+11 or later
[[deprecated("deadline:2021-12-31")]]      // c++14 or later
int old_func()
{
    //[[gnu::deprecated("I hate this")]]
    int value = 0;

    return value;
}

[[gnu::constructor]]
void first_func()
{
    // can not use cout!
    printf("before main()\n");
}

[[gnu::destructor]]
void last_func()
{
    // can not use cout!
    printf("after main()\n");
}

//[[gnu::const]]
//[[gnu::always_inline]] inline
[[using gnu : const, always_inline]] inline
int get_num()
{
    return 42;
}

[[noreturn]]
int case1(bool flag)
{
    throw std::runtime_error("XXX");
}

void case2()
{
    using namespace std;

    [[maybe_unused]] //[[gnu::unused]]
    int nouse;

    cout << "case2" << endl;
}

[[gnu::hot]]
void case3()
{
    using namespace std;

    cout << "case3" << endl;
}

int main()
{
    using namespace std;

    old_func();
    get_num();

    case2();
    case3();

    cout << "attribute demo" << endl;
}
