// Copyright (c) 2021 by Chrono
//
// g++ variant.cpp -std=c++17 -o a.out;./a.out
// g++ variant.cpp -std=c++20 -o a.out;./a.out
// g++ variant.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;

void case1()
{
    union {
        int     n;
        float   f;
        double  d;
    } x;

    x.d = 3.14;
    x.n = 10;
    assert(x.n == 10);

}

void case2()
{
    variant<int, float, double> v;

    v = 42;
    assert(v.index() == 0);
    assert(get<0>(v) == 42);

    v = 3.14f;
    assert(v.index() == 1);

    v = 2.718;
    assert(v.index() == 2);

    auto x = get<double>(v);
    cout << x << endl;

    auto p = get_if<int>(&v);
    assert(p == nullptr);
}

void case3()
{
    variant<int, string> v;

    auto vistor = [](auto& x) {
        x = x + x;
        cout << x << endl;
    };

    v = 10;
    std::visit(vistor, v);

    v = "ok";
    std::visit(vistor, v);
}

void case4()
{
    struct Swan final {
        void fly() {
            cout << "swan flies" << endl;
        }
    };

    struct Ostrich final {
        void fly() {
            cout << "ostrich can't fly" << endl;
        }
    };

    struct Phoenix final {
        void fly() {
            cout << "phoenix flies high" << endl;
        }
    };

    variant<Swan, Ostrich, Phoenix> bird;
    auto fly_it = [](auto& x) {
        x.fly();
    };

    bird = Swan();
    std::visit(fly_it, bird);

    bird = Ostrich();
    std::visit(fly_it, bird);
}


int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "variant demo" << endl;
}
