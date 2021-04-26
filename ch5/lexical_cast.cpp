// Copyright (c) 2021 by Chrono
//
// g++ lexical_cast.cpp -std=c++17 -o a.out;./a.out
// g++ lexical_cast.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <type_traits>

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

void case1()
{
    auto n1 = lexical_cast<short>("42");
    auto n2 = lexical_cast<int>("100");
    auto n3 = lexical_cast<long>("64000", 2);

    auto f1 = lexical_cast<float>("1.414");
    auto f2 = lexical_cast<double>("2.718");

    assert(n1 == 42);
    assert(n2 == 100);
    assert(n3 == 64);

    auto x = stol("99L");
    assert(x == 99L);
}

void case2()
{
    auto s1 = lexical_cast<string>(42);
    auto s2 = lexical_cast<string>(0x64);
    auto s3 = lexical_cast<string>(0.618);

    assert(s1 == "42");
    assert(s2 == "100");
    //assert(s3 == "0.618");
    //cout << s3 << endl;

    assert(to_string(0x64) == "100");
}

void case3()
{
    try
    {
        lexical_cast<long>("-100");
        lexical_cast<long>("1024L");
        lexical_cast<long long>("999LL");
    }
    catch(bad_lexical_cast& e)
    {
        cout << e.what() << endl;
    }


    //cout << stol("-100") << endl;
    //cout << stol("1024L") << endl;
    //cout << stoll("999LL") << endl;

    assert(stoi("-100") == -100);
    assert(stol("1024L") == 1024L);
    assert(stoll("999LL") == 999LL);
}

template<typename T, typename U>
T std_lexical_cast(const U& arg)
{
    if constexpr (std::is_same_v<T, int>) {
        return std::stoi(arg);
    }

    if constexpr (std::is_same_v<T, long>) {
        return std::stol(arg);
    }

    if constexpr (std::is_same_v<T, long long>) {
        return std::stoll(arg);
    }

    if constexpr (std::is_same_v<T, double>) {
        return std::stod(arg);
    }

    if constexpr (std::is_same_v<T, std::string>) {
        return std::to_string(arg);
    }

    return T {};
}

void case4()
{
    assert(std_lexical_cast<int>("+42") == 42);
    assert(std_lexical_cast<long>("100L") == 100);
    std_lexical_cast<double>("0.618");

    assert(std_lexical_cast<string>(999) == "999");
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "lexical_cast demo" << endl;
}
