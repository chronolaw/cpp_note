// Copyright (c) 2021 by Chrono
//
// g++ fmt.cpp -std=c++20 -o a.out;./a.out
//
// g++ fmt.cpp -std=c++17 -lspdlog -lpthread -o a.out;./a.out
// g++ fmt.cpp -std=c++20 -lspdlog -lpthread -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>

//#if __has_include(<format>)
//#include <format>
//#else
//#error "no std::format"
//#endif

#if __has_include(<format>)
#include <format>
#elif __has_include(<spdlog/fmt/fmt.h>)
#define SPDLOG_COMPILED_LIB
#include <spdlog/fmt/fmt.h>
#else
#error "no format lib for demo"
#endif


void case1()
{
    using namespace std;

#if defined(SPDLOG_COMPILED_LIB)
    using namespace fmt;
    cout << "using fmtlib implement" << endl;
#endif

    cout << "C++20 format" << endl;

    cout << format("{}", 100L) << endl;
    cout << format("{0}-{0}, {1} {2}",
                   "hello", 2.718, 3.14) <<endl;

    cout << format("{:>10}", "hello") << endl;
    cout << format("{:04}, {:+04}", 100L, 88) << endl;
    cout << format("{0:x}, {0:#X}", 100L) << endl;
    cout << format("{:04o}, {:04b}", 7, 5) << endl;

    cout << format("see:{{xxx}}") << endl;

}

int main()
{
    case1();

    using namespace std;

    cout << "format demo" << endl;
}
