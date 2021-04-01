// Copyright (c) 2021 by Chrono
//
// g++ others.cpp -std=c++17 -o a.out;./a.out
// g++ others.cpp -std=c++20 -o a.out;./a.out
//

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <set>

inline namespace tmp{
    auto x = 0L;
    auto str = "hello";
}

void case1()
{
    using namespace std;

    cout << x << endl;
    cout << tmp::str << endl;
}

namespace a::b::c {
    auto str = "namespace";
}

void case2()
{
    using namespace std;

    cout << a::b::c::str << endl;
}

enum class Company {
    Apple, Google, Facebook
};

void case3()
{
    using namespace std;

    //Company x = 1;

    auto v = Company::Apple;

    //int i = v;
    auto i = static_cast<int>(v);

    cout << i << endl;
}

void case4()
{
    using namespace std;

    for(int i = 0;i < 3;i++) {
        cout << "hello world" << endl;
    }

    vector<int> v {1,2,3};
    if (auto pos = v.end(); !v.empty()) {
        cout << pos - v.begin() << endl;
    }

    for (auto pos = v.end(); !v.empty();) {
        cout << pos - v.begin() << endl;
        break;
    }
}

void case5()
{
    using namespace std;

    auto a = 10;
    auto b = 010;
    auto c = 0x10;

    assert(a == 10 && b == 8 && c == 16);
    cout << a << b << c << endl;

    auto x = 0b11010010;
    //cout << x << endl;
    assert(x == 0xD2);
}

void case6()
{
    using namespace std;

    auto a = 0b1011'0101;
    auto b = 07'6'6;
    auto c = 1'000'000;
    auto d = 0xFA'BE'03;
    auto e = 9'777'1'88'10;

    cout << a << b << c << d << endl;
}


int main()
{
    using namespace std;

    case1();
    case2();
    case3();
    case4();
    case5();
    case6();

    cout << "others demo" << endl;
}
