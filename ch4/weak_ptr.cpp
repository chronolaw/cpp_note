// Copyright (c) 2021 by Chrono
//
// g++ weak_ptr.cpp -std=c++17 -o a.out;./a.out
// g++ weak_ptr.cpp -std=c++20 -o a.out;./a.out
// g++ weak_ptr.cpp -std=c++17 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <memory>
#include <string>


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

void case1()
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

class SharedSelf final :
    public std::enable_shared_from_this<SharedSelf>
{ };

void case2()
{
    using namespace std;

    auto ptr1 = make_shared<SharedSelf>();
    assert(ptr1.use_count() == 1);

    auto ptr2 = ptr1->shared_from_this();
    assert(ptr2.use_count() == 2);

    auto ptr3 = ptr1->weak_from_this();
    assert(!ptr3.expired() && ptr1.use_count() == 2);
}

int main()
{
    using namespace std;

    case1();
    case2();

    cout << "weak_ptr demo" << endl;
}
