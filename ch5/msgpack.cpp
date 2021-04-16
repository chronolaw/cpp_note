// Copyright (c) 2021 by Chrono
//
// sudo apt-get install libmsgpack-dev
//
// /usr/include/msgpack
//
// g++ msgpack.cpp -std=c++17 -o a.out;./a.out
// g++ msgpack.cpp -std=c++20 -o a.out;./a.out
//
// source include
// g++ msgpack.cpp -std=c++17 -I../common/include -o a.out;./a.out

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <msgpack.hpp>

#if MSGPACK_VERSION_MAJOR < 2
#   error "msgpack  is too old."
#endif

using namespace std;

void case1()
{
    auto serialize = [](const auto& x) {
        msgpack::sbuffer sbuf;
        msgpack::pack(sbuf, x);

        cout << sbuf.size() << endl;
    };

    serialize(99);
    serialize(3.14);
    serialize("hello msgpack"s);
    serialize(vector{1,2,3});
    serialize(tuple{1,"str"s, true});
}

void case2()
{
    vector<int> v = {1,2,3,4,5};

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, v);

    cout << sbuf.size() << endl;

    auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
    auto obj = handle.get();
    cout << obj << endl;

    //decltype(v) v2;
    vector<int> v2;
    obj.convert(v2);

    assert(std::equal(begin(v), end(v), begin(v2)));
}

void case3()
{
    msgpack::sbuffer sbuf;
    //msgpack::packer<decltype(sbuf)> packer(sbuf);
    msgpack::packer packer(sbuf);

    packer.pack(10).pack("monado"s)
          .pack(vector<int>{1,2,3});

    cout << sbuf.size() << endl;

    for(decltype(sbuf.size()) offset = 0;
        offset != sbuf.size();){

        auto handle = msgpack::unpack(
                sbuf.data(), sbuf.size(), offset);
        auto obj = handle.get();
        cout << obj << endl;
    }

#if 0
    cout << "lambda " << endl;
    for(decltype(sbuf.size()) offset = 0;
        offset != sbuf.size();){

        auto handle = msgpack::unpack(
                sbuf.data(), sbuf.size(), offset,

                [](auto type, auto len, auto data)
                {
                    cout << type << ":" << len << endl;
                    return true;
                }

                );
    }
#endif
}

class Book final
{
public:
    int         id;
    string      title;
    set<string> tags;
public:
    MSGPACK_DEFINE(id, title, tags);
};

void case4()
{
    Book book1 = {1, "1984", {"a","b"}};

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, book1);

    // may cause std::bad_cast error
    //auto obj = msgpack::unpack(sbuf.data(), sbuf.size()).get();

    auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
    auto obj = handle.get();

    Book book2;
    obj.convert(book2);
    //msgpack::unpack(sbuf.data(), sbuf.size()).get().convert(book2);


    assert(book2.id == book1.id);
    assert(book2.tags.size() == 2);
    cout << book2.title << endl;
}

void case5()
{
    auto txt = ""s;

    try
    {
        auto handle = msgpack::unpack(
            txt.data(), txt.size());
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();

    cout << msgpack_version() << endl;
    cout << "msgpack demo" << endl;
}
