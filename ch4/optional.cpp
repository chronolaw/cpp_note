// Copyright (c) 2021 by Chrono
//
// g++ optional.cpp -std=c++17 -o a.out;./a.out
// g++ optional.cpp -std=c++20 -o a.out;./a.out
// g++ optional.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <optional>

using namespace std;

void case1()
{
    optional<int> op;
    assert(!op.has_value());

    op = 10;

    if (op.has_value()) {
        cout << "value is valid" << endl;
    }
}

void case2()
{
    optional<int> op1 = 42;

    if (op1.has_value()) {
        cout << op1.value() << endl;
    }

    optional<int> op2;
    cout << op2.value_or(99) << endl;
}

void case3()
{
    optional<string> op {"zelda"};
    assert(op);
    assert(!op->empty() && *op == "zelda");

    op.reset();
    assert(!op);
}

void case4()
{
    auto op1 = make_optional<int>();
    auto op2 = make_optional<string>();

    assert(op1 && op2);
    assert(op1 == 0);
    assert(op2->empty());

    auto op3 = make_optional<string>("hi");
    auto op4 = make_optional<vector<int>>({1,2,3});

    assert(op3->size() == 2);
    assert(op4->at(0) == 1);
}

void case5()
{
    auto safe_sqrt = [](double x) {
        optional<double> v;

        if (x < 0) {
            return v;
        }

        v  = ::sqrt(x);
        return v;
    };

    assert(!safe_sqrt(-1));
    assert(safe_sqrt(9).value() == 3);
}

void case6()
{
    optional<bool> op {false};

    if (op) {
        cout << "misuse of optional" << endl;
    }

    if (op && op.value()) {
        cout << "right use" << endl;
    }
}


int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();

    cout << "optional demo" << endl;
}
