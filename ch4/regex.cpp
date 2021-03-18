// Copyright (c) 2021 by Chrono
//
// g++ regex.cpp -std=c++17 -o a.out;./a.out
// g++ regex.cpp -std=c++20 -o a.out;./a.out
// g++ regex.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <regex>

static
auto make_regex = [](const auto& txt)
{
    return std::regex(txt);
};

static
auto make_match = []()
{
    return std::smatch();
};

void case1()
{
    using namespace std;

    //using sregex = std::regex;
    //using cregex = std::regex;

    auto str = "neir:automata"s;

    auto reg  = make_regex(R"(^(\w+)\:(\w+)$)");
    auto what = make_match();

    assert(regex_match(str, what, reg));

    for(const auto& x : what) {
        cout << x << ',';
    }
    cout << endl;
}

void case2()
{
    using namespace std;

    auto str = "god of war"s;

    auto reg  = make_regex(R"((\w+)\s(\w+))");
    auto what = make_match();

    auto found = regex_search(
                    str, what, reg);

    assert(found);
    assert(!what.empty());
    assert(what[1] == "god");
    assert(what[2] == "of");

    auto new_str = regex_replace(
        str,
        make_regex(R"(\w+$)"),
        "peace"
    );

    cout << new_str << endl;
}



int main()
{
    case1();
    case2();

    using namespace std;

    cout << "regex demo" << endl;
}
