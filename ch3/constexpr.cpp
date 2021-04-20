// Copyright (c) 2021 by Chrono
//
// g++ constexpr.cpp -std=c++17 -o a.out;./a.out
// g++ constexpr.cpp -std=c++20 -o a.out;./a.out
// g++ constexpr.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include <bitset>

#include <type_traits>

constexpr
long mega_bits()
{
    return 1024*1024;
}

void case1()
{
    using namespace std;

    constexpr int MAX = 100;

    array<int, MAX> arr = {0};
    assert(arr.size() == 100);

    static_assert(mega_bits() == 1024*1024);
    bitset<mega_bits()> bits;
}

void case2()
{

    using namespace std;

    constexpr auto val = 100;
    constexpr auto str = "hello";
    constexpr array<int, 3> arr {1,2,3};

    //constexpr vector<int> vec {1,2,3};
    //constexpr string s = "str";
    //constexpr map<int,int> m;

}

constexpr
int fib(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

void case3()
{
    static_assert(fib(4) == 5);
    static_assert(fib(5) == 8);
}

constexpr
void case4()
{
#if __cplusplus > 201703

    using namespace std;

    //vector<int> vec {1,2,3};
    //string s = "str";

    auto x = new char[10];
    delete[] x;

    try {
        int a = 10;
    }
    catch(...)
    {
    }

#endif
}

int main()
{
    using namespace std;

    case1();
    case2();
    case3();

    cout << "constexpr demo" << endl;
}
