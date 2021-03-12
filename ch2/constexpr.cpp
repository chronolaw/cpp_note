// Copyright (c) 2021 by Chrono
//
// g++ constexpr.cpp -Werror -std=c++17 -o a.out;./a.out
// g++ constexpr.cpp -Werror -std=c++20 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#if __cplusplus < 201402
# error "c++ is too old"
#endif

#include <iostream>

constexpr
int fib(int n)
{
    if (n <= 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    using namespace std;

    for(int i = 0;i <= 5; i++)
    {
        cout << fib(i) << endl;
    }

    cout << fib(10) << endl;

    cout << "constexpr demo" << endl;
}
