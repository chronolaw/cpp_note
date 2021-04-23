// Copyright (c) 2021 by Chrono
//
// g++ string.cpp -std=c++17 -o a.out;./a.out
// g++ string.cpp -std=c++20 -o a.out;./a.out
// g++ string.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>

void case1()
{
    using namespace std;

    string str = "abc";

    assert(str.length() == 3);
    assert(str < "xyz");
    assert(str.substr(0, 1) == "a");
    assert(str[1] == 'b');
    assert(str.find("1") == string::npos);
    assert(str + "d" == "abcd");
    auto p = str.c_str();
    cout << p << endl;

#if __cplusplus > 201703
    assert(str.starts_with("ab"));
    assert(str.ends_with("c"));
#endif

    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    assert(v.front() == 'a');
}

void case2()
{
    // enable literal suffix 's'
    using namespace std::literals;

    using std::string;

    auto str = "std string"s;

    assert(str.length() > 0);

    assert("time"s.size() == 4);
}

void case3()
{
    using namespace std;

    auto str = R"(nier:automata)";

    auto str1 = R"(char""'')";
    auto str2 = R"(\r\n\t\")";
    auto str3 = R"(\\\$)";
    auto str4 = "\\\\\\$";

    auto str5 = R"==(R"(xxx)")==";

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
}

void case4()
{
    using namespace std;

    assert(stoi("42") == 42);
    assert(stol("253") == 253L);
    assert(stod("2.0") == 2.0);

    assert(to_string(1984) == "1984");
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    using namespace std;

    cout << "string demo" << endl;
}
