// Copyright (c) 2021 by Chrono
//
// g++ ptree.cpp -std=c++17 -o a.out;./a.out
// g++ ptree.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
using namespace boost::property_tree;

inline namespace detail{

auto conf_str = R"({
    "enable" : true,
    "env" : "test",
    "timeout" : 10,
    "secret" : {
        "crt" : "ccc",
        "key" : "kkk"
    },
    "uri" : ["a", "b", "c"]
    })";

stringstream conf_stream{conf_str};
}

void case1()
{
    ptree pt;

    read_json(conf_stream, pt);

    cout << pt.get<bool>("enable") << endl;
    cout << pt.get<string>("env") << endl;
    cout << pt.get<int>("timeout") << endl;

    cout << pt.get<string>("secret.crt") << endl;
    cout << pt.get<string>("secret.key") << endl;

    for(auto& [i, x] : pt.get_child("uri")) {
        cout << x.data() << endl;
    }
}

int main()
{
    case1();

    cout << "property_tree demo" << endl;
}
