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

    using namespace std::regex_constants;
    regex reg1 {"xyz", icase|optimize};
    regex reg2 {R"(a*b{2,3})"};

    auto reg  = make_regex(R"(^(\w+)\:(\w+)$)");

    assert(regex_match("a:b", reg));
    assert(!regex_match("a,b", reg));

    auto str = "neir:automata"s;

    auto what = make_match();

    assert(regex_match(str, what, reg));

    assert(what[1] == "neir");
    assert(what[2] == "automata");

    for(const auto& x : what) {
        cout << x << ',';
    }
    cout << endl;

    //str = "a,b";
    //assert(!regex_match(str, what, reg));
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


    auto reg1 = make_regex(R"(^unix)");
    auto reg2 = make_regex(R"(com$)");

    assert(regex_search("unix_time", reg1));
    assert(regex_search("abc.com", reg2));

    assert(!regex_search("win_os", reg1));
    assert(!regex_search("abc.org", reg2));
}

void case3()
{
    using namespace std;

    auto str = "god of war"s;

    auto reg  = make_regex(R"((\w+)\s(\w+))");

    auto new_str = regex_replace(
        str,
        make_regex(R"(\w+$)"),
        "peace"
    );

    cout << new_str << endl;

    cout << regex_replace(
        "   xxx  ",
        make_regex("^\\s+"), ""
        ) << endl;

    cout << regex_replace(
        "   xxx---",
        make_regex("\\-+$"), ""
        ) << endl;

    cout << regex_replace(
                regex_replace(
                    str,
                    make_regex("\\w+$"),
                    "peace"
                ),
                make_regex("^\\w+"),
                "godness"
        ) << endl;

    cout << regex_replace(
        "hello mike",
        make_regex(R"((\w+)\s(\w+))"),
        "$2-says-$1 ($&)"
        ) << endl;
}

void case4()
{
    //auto reg = make_regex(R"(\w+)");

    for (int i = 0;i < 100; i++) {
        auto reg = make_regex(R"(\w+)");
        regex_match("123", reg);
    }
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    using namespace std;

    cout << "regex demo" << endl;
}
