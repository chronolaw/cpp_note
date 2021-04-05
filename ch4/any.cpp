// Copyright (c) 2021 by Chrono
//
// g++ any.cpp -std=c++17 -o a.out;./a.out
// g++ any.cpp -std=c++20 -o a.out;./a.out
// g++ any.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <any>

using namespace std;

void case1()
{
    any a;

    a = 10;
    a = 0.618;
    a = "hello any"s;
    a = vector<int>(10);

    //cout << a.type().name() << endl;

}

void case2()
{
    auto a = make_any<long>(99);
    assert(a.has_value());

    a.reset();
    assert(!a.has_value());
}

void case3()
{
    any a;

    a = 100L;
    assert(any_cast<long>(a) == 100);

    auto& v = any_cast<long&>(a);
    v = 200L;
    assert(any_cast<long>(a) == 200);

    a = "any"s;

    auto p = any_cast<string>(&a);
    //cout << *p << endl;
    assert(p && p->size() == 3);

    //any_cast<int>(a);
    assert(any_cast<int>(&a) == nullptr);
}

void case4()
{
    any a;

    a = 10;
    assert(a.type() == typeid(int));

    a = "string"s;
    assert(a.type() == typeid(string));

    if (a.type() == typeid(long)) {
        cout << "do with long"<< endl;
    }

    a = 100L;

    if (auto p = any_cast<long>(&a); p) {
        cout << *p << endl;
    }
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "any demo" << endl;
}
