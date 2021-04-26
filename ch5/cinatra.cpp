// Copyright (c) 2021 by Chrono
//
// apt-get update
// apt-get install libboost-system-dev -y
// libboost-dev libboost-all-dev
//
// if you have boost 1.72, thenneed not to link boost_system
//
// g++ cinatra.cpp -std=c++17 -lstdc++fs -lboost_system -pthread -I../common -o a.out;./a.out&
// g++ cinatra.cpp -std=c++20 -lstdc++fs -lboost_system -pthread -I../common -o a.out;./a.out&

#include <iostream>

#include <cinatra.hpp>

using namespace std;
using namespace cinatra;

// curl '127.1/test?a=1&b=2'
void srv1()
{
    const int max_threads = 2;

    http_server srv(max_threads);

    srv.listen("0.0.0.0", "80");

    auto handler = [](auto& req, auto& res) {
        cout << req.raw_url() << endl;
        cout << "header: \n" << req.head() << endl;

        res.set_status(status_type::ok);
        res.set_content("hello http srv\n");
        res.build_response_str();

        //res.set_status_and_content(status_type::ok, "hello http srv");
    };

    srv.set_http_handler<GET>("/test", handler);

    srv.run();
}


// curl 127.1/api
// curl 127.1/api -X POST -d "abcde" -v -H "Content-type: text/plain"
void srv2()
{
    const auto max_threads = 2;
    const auto addr = "0.0.0.0"s;
    const auto port = 80;

    http_server srv(max_threads);

    if (srv.port_in_use(port)) {
        cout << "port_in_use" << endl;
        return;
    }

    srv.listen(addr, to_string(port));

    srv.set_http_handler<GET>(
        "/",
        [](auto& req, auto& res) {
            res.set_status_and_content(
                status_type::forbidden, "code:403\n");
        });

    srv.set_http_handler<GET, POST>(
        "/api",
        [](auto& req, auto& res) {
            auto method = req.get_method();

            if (method == "GET") {
                res.set_status_and_content(
                        status_type::not_found, "code:404\n");
                return;
            }

            assert(method == "POST");

            if (!req.has_body()) {
                res.set_status_and_content(
                        status_type::bad_request, "code:400\n");
                return;
            }

            //cout << "body: \n" <<  req.body() << endl;
            res.set_status_and_content(
                    status_type::ok,
                    "data:"s + string(req.body()) + "\n");
        });

    srv.run();
}

int main()
{
    cout << "cinatra http srv demo" << endl;

    //srv1();
    srv2();
}

