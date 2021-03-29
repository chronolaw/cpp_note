// Copyright (c) 2021 by Chrono
//
// g++ others.cpp -std=c++17 -o a.out;./a.out
// g++ others.cpp -std=c++20 -o a.out;./a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

inline namespace tmp{
    auto x = 0L;
    auto str = "hello";
}

void case1()
{
    using namespace std;

    cout << x << endl;
    cout << tmp::str << endl;
}

namespace a::b::c {
    auto str = "namespace";
}

void case2()
{
    using namespace std;

    cout << a::b::c::str << endl;
}

enum class Company {
    Apple, Google, Facebook
};

void case3()
{
    using namespace std;

    //Company x = 1;

    auto v = Company::Apple;

    //int i = v;
    auto i = static_cast<int>(v);

    cout << i << endl;
}

void case4()
{
    using namespace std;

    for(int i = 0;i < 3;i++) {
        cout << "hello world" << endl;
    }
}


int main()
{
    using namespace std;

    case1();
    case2();
    case3();
    case4();

    cout << "others deom" << endl;
}
