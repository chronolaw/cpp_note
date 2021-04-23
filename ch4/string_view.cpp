// Copyright (c) 2021 by Chrono
//
// g++ string_view.cpp -std=c++17 -o a.out;./a.out
// g++ string_view.cpp -std=c++20 -o a.out;./a.out
// g++ string_view.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void case1()
{
    using namespace std;

    string_view sv;
    assert(sv.empty());

    sv = "fantasy"s;
    assert(sv.size() == 7);

    sv = "c++";
    assert(sv.size() == 3);

    string_view sv2("std c++", 3);
    assert(sv2 == "std");

    // enable literal suffix 'sv'
    using namespace std::literals;
    auto sv3 = "viewit"sv;
}

void case2()
{
    using namespace std;
    using namespace std::literals;

    string_view sv {"god of war"s};

    assert(!sv.empty());
    assert(sv.size() == 10);
    assert(sv.front() == 'g');
    assert(sv[2] == 'd');
    assert(sv.find('w') != string_view::npos);

#if __cplusplus > 201703
    assert(sv.starts_with("god"));
    assert(sv.ends_with("war"));
#endif
}

void case3()
{
    using namespace std;

    string_view sv {"god of war"};

    assert(sv.substr(4, 2) == "of");

    sv.remove_prefix(3);
    assert(sv == " of war");

    sv.remove_suffix(4);
    assert(sv == " of");
}

int main()
{
    case1();
    case2();
    case3();

    using namespace std;

    cout << "string_view demo" << endl;
}
