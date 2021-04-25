// Copyright (c) 2021 by Chrono
//
// g++ string_algo.cpp -std=c++17 -o a.out;./a.out
// g++ string_algo.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

void case1()
{
    auto str = "hello c++"s;

    assert(starts_with(str, "he"));
    assert(ends_with(str, "c++"));
    assert(!ends_with(str, "C++"));
    assert(contains(str, "llo"));

    auto ustr = to_upper_copy(str);
    assert(ustr == "HELLO C++");
    assert(iends_with(str, "c++"));
    assert(icontains(ustr, "llo"));
    assert(iequals(str, ustr));

    auto tstr = trim_copy_if(
        str, [](auto& c) {
                return c == '+';
        });
    assert(tstr == "hello c");

    trim_right_if(str, [](auto& c) {
        return c < 'l';
    });
    assert(str == "hello");
    //cout << str << endl;
}

void case2()
{
    auto str = "apple google facebook"s;

    replace_head(str, 3, "App");
    cout << str << endl;

    replace_tail(str, 4, "cook");
    cout << str << endl;

    replace_first(str, "oo", "xx");
    cout << str << endl;

    ireplace_all(str, "LE", "GE");
    cout << str << endl;

    ireplace_nth(str, "ge", 1, "MM");
    cout << str << endl;
}

void case3()
{
    auto str = "123,456,999, 1024";

    //vector<string> res;
    //unordered_set<string> res;
    set<string> res;

    res = split(res, str,
            [](const auto& c) {
                return c == ',' || c == ' ';
            }, token_compress_on);

    for(auto&& x: res) {
        cout << '[' << x << "]";
    }
    cout << endl;
}

void case4()
{
    vector<string> v = {"apple", "pear", "tomato"};

    cout << join(v, "**") << endl;

    cout << join_if(v, "++",
            [](auto& x) {
                return std::size(x) >= 5;
            }) << endl;
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "string_algo demo" << endl;
}
