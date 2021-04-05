// Copyright (c) 2021 by Chrono
//
// g++ tuple.cpp -std=c++17 -o a.out;./a.out
// g++ tuple.cpp -std=c++20 -o a.out;./a.out
// g++ tuple.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void case1()
{
    tuple<int, double, string> t1 {0, 1, "x"};

    assert(get<0>(t1) == 0);
    assert(get<1>(t1) == 1);
    assert(get<string>(t1) == "x");

    auto t2 = make_tuple(1L, "string"s);
    assert(get<long>(t2) == 1);

    get<1>(t2) = "hi";
    assert(get<1>(t2) == "hi");
}

void case2()
{
    using Student = tuple<int, string, double>;

    //struct Student {
    //    int id;
    //    string name;
    //    double score;
    //};

    auto f = []() {
        return make_tuple(true, "ok"s);
    };

    auto [flag, msg] = f();
    assert(flag && msg == "ok");

}

int main()
{
    case1();
    case2();

    cout << "tuple demo" << endl;
}
