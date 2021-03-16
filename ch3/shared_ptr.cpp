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

class Node final
{
public:
    using this_type     = Node;
    //using shared_type   = std::shared_ptr<this_type>;
    using shared_type   = std::weak_ptr<this_type>;
public:
    shared_type     next;
public:
    Node() = default;
   ~Node()
    {
       using namespace std;
       cout << "node dtor" << endl;
    }
};

void case3()
{
    using namespace std;

    auto n1 = make_shared<Node>();
    auto n2 = make_shared<Node>();

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    n1->next = n2;
    n2->next = n1;

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    if (!n1->next.expired()) {
        auto ptr = n1->next.lock();
        assert(ptr == n2);
    }

    //assert(n1.use_count() == 2);
    //assert(n2.use_count() == 2);
}

int main()
{
    using namespace std;

    case1();
    case2();
    case3();

    cout << "smart_ptr demo" << endl;
}
