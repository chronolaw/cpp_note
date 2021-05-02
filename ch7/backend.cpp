// Copyright (c) 2021 by Chrono
//
// apt-get update
// apt-get install libboost-system-dev -y
// libboost-dev libboost-all-dev
//
// if you have boost 1.72, thenneed not to link boost_system
//
// g++ backend.cpp -std=c++17 -lstdc++fs -lboost_system -pthread -I../common -o b.out;./b.out&
// g++ backend.cpp -std=c++20 -lstdc++fs -lboost_system -pthread -I../common -o b.out;./b.out&
//
// curl 127.1/cpp_note?token=cpp -d 'abcd' -H 'content-type: text/plain'

#include <iostream>

#include <cinatra.hpp>

using namespace std;
using namespace cinatra;

int main()
{
    cout << "http srv is running" << endl;

    http_server srv(1);

    srv.listen("0.0.0.0", "80");

    srv.set_not_found_handler(
        [](auto& req, auto& res) {
            res.set_status_and_content(
                status_type::forbidden, "code:403\n");
        });

    srv.set_http_handler<POST>(
        "/cpp_note",
        [](auto& req, auto& res) {
            auto token = req.get_query_value("token");

            if (token != "cpp" ||
                !req.has_body()) {
                res.set_status_and_content(
                    status_type::forbidden, "code:403\n");
                return;
            }

            cout << req.body() << endl;

            res.set_status_and_content(
                    status_type::ok, "ok");
        });

    srv.run();
}
