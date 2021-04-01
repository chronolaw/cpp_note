// Copyright (c) 2021 by Chrono
//
// g++ format.cpp -std=c++20 -o a.out;./a.out
//
// g++ format.cpp -std=c++17 -lspdlog -lpthread -o a.out;./a.out
// g++ format.cpp -std=c++20 -lspdlog -lpthread -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>

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
#endif

    cout << "C++20 format" << endl;

    cout << format("{}", 100L) << endl;
    cout << format("{:6}", "hello") << endl;
    //cout << format("{:04}, {:+04}", 100L) << endl;
    //cout << format("{1}-{1}", "hello") << endl;

    cout << format("{{xxx}}") << endl;

}

int main()
{
    case1();

    using namespace std;

    cout << "format demo" << endl;
}
