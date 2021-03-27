// Copyright (c) 2021 by Chrono
//
// g++ auto.cpp -std=c++17 -o a.out;./a.out
// g++ auto.cpp -std=c++20 -o a.out;./a.out
// g++ auto.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <functional>

#include <type_traits>

#include <signal.h>

void case1()
{

    int     i = 0;
    double  x = 1.0;

    std::string str = "hello";
    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};

    std::map<int, std::string>::const_iterator iter = m.begin();

    //using namespace std;
    //cout << i << x;
}

void case2()
{
    using namespace std;

    auto  i = 0;
    //auto  i{0} ;
    auto  x = 1.0;

    auto  str = "hello"s;
    //auto  str = "hello";
    //decltype("hello")  str = "hello";

    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};

    auto  iter = m.begin();

    //auto  f = bind1st(std::less<int>(), 2);
    using namespace std::placeholders;
    auto  f = bind(std::less<int>(), _1);

    //using namespace std;
    //cout << typeid(str).name() << endl;
}

void case3()
{
    auto x = 0L;
    auto y = &x;
    auto z {&x};
}

class X final
{
    //auto a = 10;
    int a = 10;
};

void case4()
{
    auto    x = 10L;

    auto&       x1 = x;
    auto*       x2 = &x;
    const auto& x3 = x;
    auto        x4 = &x3;
    auto&&      x5 = x;

    using namespace std;

    cout << *x2 << endl;
    cout << *x4 << endl;
    //cout << typeid(x4).name() << endl;
    //cout << typeid(x5).name() << endl;
    static_assert(is_reference_v<decltype(x3)>);
    static_assert(is_pointer_v<decltype(x4)>);
    static_assert(is_reference_v<decltype(x5)>);
}

void case5()
{
    int x = 0;

    decltype(x)     x1;
    decltype(x)&    x2 = x;
    decltype(x)*    x3;
    decltype(&x)    x4;
    decltype(&x)*   x5;
    decltype(x2)    x6 = x2;
    auto            x7 = x2;

    using int_ptr = decltype(&x);
    using int_ref = decltype(x)&;
}

void case6()
{
    int x = 0;

    decltype(auto)     x1 = (x);
    decltype(auto)     x2 = &x;
    decltype(auto)     x3 = x1;

    assert(std::is_lvalue_reference_v<decltype(x1)>);
    assert(std::is_pointer_v<decltype(x2)>);
    assert(std::is_lvalue_reference_v<decltype(x3)>);
}

auto get_a_set()
{
    std::set<int> s = {1,2,3};

    return s;
}

void case7()
{
    using namespace std;

    vector<int> v = {2,3,5,7,11};

    for(const auto& i : v) {
        cout << i << ",";
    }
    cout << endl;

    for(auto& i : v) {
        i++;
        cout << i << ",";
    }
    cout << endl;

    //tuple<int, string, double> x {1, "x", 0.1};
    tuple x {1, "x"s, 0.1};
    auto [a, b, c] = x;

    //int a; string b; double c;
    //std::tie(a, b, c) = x;

    assert(a == 1 && b == "x");

    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};

    for (auto& [k,v] : m) {
        cout << k << "=>" << v << endl;
    }
}

class DemoClass final
{
public:
    using sig_func_ptr_t = decltype(&signal) ;
public:
    using set_type      = std::set<int>;

private:
    set_type    m_set;

    using iter_type = decltype(m_set.begin());
    iter_type   m_pos;
};

int main()
{
    using namespace std;

    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    case7();

    cout << "auto/decltype demo" << endl;
}
