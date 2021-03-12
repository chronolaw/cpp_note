// Copyright (c) 2021 by Chrono
//
// g++ fab.cpp -Wall -Werror -std=c++17 -o a.out;./a.out
// g++ fab.cpp -Wall -Werror -std=c++20 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#if __cplusplus < 201402
# error "c++ is too old"
#endif

#include <iostream>

template<int N>
struct fib
{
    static_assert(N >= 0, "N must be postive");

    static const int value =
        fib<N - 1>::value + fib<N - 2>::value;
};

template<>
struct fib<0>
{
    static const int value = 1;
};

template<>
struct fib<1>
{
    static const int value = 1;
};

constexpr
int const_fib(int n)
{
    if (n <= 1) {
        return 1;
    }

    return const_fib(n - 1) + const_fib(n - 2);
}

int main()
{
    using namespace std;

    cout << fib<2>::value << endl;
    cout << fib<3>::value << endl;
    cout << fib<4>::value << endl;
    cout << fib<5>::value << endl;

    cout << const_fib(10) << endl;

    cout << "fab demo" << endl;
}
