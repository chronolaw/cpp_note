// Copyright (c) 2021 by Chrono
//
// g++ const.cpp -std=c++17 -o a.out;./a.out
// g++ const.cpp -std=c++20 -o a.out;./a.out
// g++ const.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <utility>
#include <type_traits>

void case1()
{
    using namespace std;

    //const int MAX_LEN       = 1024;
    const volatile int MAX_LEN       = 1024;
    const std::string NAME  = "metroid";

    //auto ptr = (int*)(&MAX_LEN);
    auto ptr = const_cast<int*>(&MAX_LEN);
    *ptr = 2048;
    cout << MAX_LEN << endl;

}

void case2()
{
    using namespace std;

    int x = 100;

    const int& rx = x;
    const int* px = &x;

    cout << rx << *px << endl;

    string name = "uncharted";

    const string* ps1 = &name;
    //*ps1 = "spiderman";

    cout << *ps1 << endl;

    string* const ps2 = &name;
    *ps2 = "spiderman";

    cout << *ps2 << endl;

    const string* const ps3 = &name;

    //auto&& s = std::as_const(name);
    decltype(auto) s = std::as_const(name);
    assert(std::is_const_v<
            std::remove_reference_t<decltype(s)>
           >);
    assert(std::is_reference_v<decltype(s)>);
}

class DemoClass final
{
private:
    using mutex_type = int; // dummy type
private:
    mutable mutex_type  m_mutex;

    const long  MAX_SIZE = 256;
    int         m_value = 100;
public:
    int get_value() const
    {
        return m_value;
    }

    void incr()
    {
        m_value++;
    }

    void save_data() const
    {
        m_mutex++;
        //m_value++;
    }
};

void case3()
{
    using namespace std;

    DemoClass obj;
    //const auto& cobj = obj;
    //decltype(auto) cobj = std::as_const(obj);
    auto&& cobj = std::as_const(obj);

    cout << cobj.get_value() << endl;
    //cobj.incr();
    cobj.save_data();
}


int main()
{
    using namespace std;

    case1();
    case2();
    case3();

    cout << "const demo" << endl;
}
