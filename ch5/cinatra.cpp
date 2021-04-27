// Copyright (c) 2021 by Chrono
//
// apt-get update
// apt-get install libboost-system-dev -y
// libboost-dev libboost-all-dev
//
// if you have boost 1.72, thenneed not to link boost_system
//
// g++ cinatra.cpp -std=c++17 -lstdc++fs -lspdlog -lssl -lcrypto -lboost_system -pthread -I../common -o a.out;./a.out&
// g++ cinatra.cpp -std=c++20 -lstdc++fs -lspdlog -lssl -lcrypto -lboost_system -pthread -I../common -o a.out;./a.out&

#include <iostream>

#if __has_include(<format>)
#include <format>
#elif __has_include(<spdlog/fmt/fmt.h>)
#define SPDLOG_COMPILED_LIB
#include <spdlog/fmt/fmt.h>
#else
#error "no format lib for demo"
#endif

#define CINATRA_ENABLE_SSL
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
// curl 127.1/api -d "abcde" -v -H "Content-type: text/plain"
void srv2()
{
#if defined(SPDLOG_COMPILED_LIB)
    using namespace fmt;
#endif

    const auto max_threads = 2;
    const auto addr = "0.0.0.0"s;
    const auto port = 80;

    http_server srv(max_threads);

    if (srv.port_in_use(port)) {
        cout << "port_in_use" << endl;
        return;
    }

    srv.set_keep_alive_timeout(30);
    srv.listen(addr, to_string(port));

    srv.set_not_found_handler(
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

            res.add_header("Metroid", "Prime");

            //cout << "body: \n" <<  req.body() << endl;
            res.set_status_and_content(
                    status_type::ok,
                    format("host:{}\ndata:{}\n",
                            req.get_header_value("host"),
                            req.body()));
        });

    srv.run();
}

// curl 'https://127.0.0.1' -k
// curl --resolve a.com:443:127.0.0.1 'https://a.com' -kv
void srv3()
{
    http_ssl_server srv(1);

    srv.set_ssl_conf({"./a.com.crt", "./a.com.key"});

    srv.listen("0.0.0.0", "443");

    srv.set_http_handler<GET>(
        "/",
        [](auto& req, auto& res) {

            cout << "host: "
                 << req.get_header_value("host") << endl;

            res.set_status_and_content(
                status_type::ok, "hello https srv\n");
        }
    );

    srv.run();
}

int main()
{
    cout << "cinatra http srv demo" << endl;

    //srv1();
    //srv2();
    srv3();
}

