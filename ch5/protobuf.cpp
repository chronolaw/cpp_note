// Copyright (c) 2021 by Chrono
//
// sudo apt-get install protobuf-compiler
// sudo apt-get install libprotobuf-dev
// sudo apt-get install libprotoc-dev
//
// protoc --cpp_out=. sample.proto
//
// g++ protobuf.cpp -std=c++17 -lprotobuf -lpthread -o a.out;./a.out
// g++ protobuf.cpp -std=c++20 -lprotobuf -lpthread -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <vector>

// uncomment this to enable proto2
//#define PROTO2  2

// just for convient
//#include "sample.pb.h"
#include "sample.pb.cc"

using namespace std;

void case1()
{
    using vendor_t = sample::Vendor;

    vendor_t v;

#if PROTO2
    assert(!v.IsInitialized());
#endif

    v.set_id(1);
    v.set_name("sony");
    v.set_valid(true);
    v.clear_tel();

    assert(v.IsInitialized());
#if PROTO2
    assert(v.has_id() && v.id() == 1);
    assert(v.has_name() && v.name() == "sony");
    assert(v.has_valid() && v.valid());
#endif

    cout << v.DebugString() << endl;

    string enc;
    v.SerializeToString(&enc);

    vendor_t v2;

#if PROTO2
    assert(!v2.IsInitialized());
#endif

    v2.ParseFromString(enc);

    assert(v.id() == v2.id());
}

void case2()
{
    auto alloc_vendor = []()
    {
        return new sample::Vendor;
    };

    auto v = alloc_vendor();

    v->set_id(1);
    v->set_name("sony");
    v->set_valid(true);
    assert(v->IsInitialized());

    using product_t = sample::Product;

    product_t p;

    p.set_id(1);
    p.set_name("walkman");

    assert(p.tag_size() == 0);
    p.add_tag("fashion");
    p.add_tag("type_record");

#if PROTO2
    assert(!p.has_vendor());
#endif

    p.set_allocated_vendor(v);
}

int main()
{
    //GOOGLE_PROTOBUF_VERIFY_VERSION;

    case1();
    case2();

    cout << "protobuf demo" << endl;
}
