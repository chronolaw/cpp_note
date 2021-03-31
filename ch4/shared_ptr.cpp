// Copyright (c) 2021 by Chrono
//
// g++ shared_ptr.cpp -std=c++17 -o a.out;./a.out
// g++ shared_ptr.cpp -std=c++20 -o a.out;./a.out
// g++ shared_ptr.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <memory>
#include <string>

void case1()
{
    using namespace std;

    shared_ptr<int> ptr1(new int(10));
    assert(*ptr1 = 10);

    shared_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");

    auto ptr3 = make_shared<int>(42);
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_shared<string>("zelda");
    assert(!ptr4->empty());
}

void case2()
{
    using namespace std;

    auto ptr1 = make_shared<int>(42);
    assert(ptr1 && ptr1.use_count() == 1 );
    //assert(ptr1 && ptr1.unique() );

    auto ptr2 = ptr1;
    assert(ptr1 && ptr2);

    assert(ptr1 == ptr2);
    assert(ptr1.use_count() == 2);
    assert(ptr2.use_count() == 2);
}

class DemoShared final
{
public:
    DemoShared() = default;
   ~DemoShared()
   {
       // do some blocking thing ...
   }
};

int main()
{
    using namespace std;

    case1();
    case2();

    cout << "smart_ptr demo" << endl;
}
