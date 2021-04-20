// Copyright (c) 2021 by Chrono
//
// apt-get update
// apt-get install libboost-system-dev -y
// libboost-dev libboost-all-dev
//
// if you have boost 1.72, thenneed not to link boost_system
//
// g++ http_srv.cpp -std=c++17 -lstdc++fs -lboost_system -pthread -I../common -o a.out;./a.out
// g++ http_srv.cpp -std=c++20 -lstdc++fs -lboost_system -pthread -I../common -o a.out;./a.out

#include <iostream>

#include <cinatra.hpp>

using namespace std;
using namespace cinatra;

int main()
{
    int max_threads = 2;

    http_server srv(max_threads);

    srv.listen("0.0.0.0", "8080");

    srv.set_http_handler<GET>("/",
        [](request& req, response& res) {

            res.set_status_and_content(status_type::ok, "hello cinatra");
        }
    );

    srv.run();
}

