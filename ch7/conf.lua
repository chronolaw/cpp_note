-- copyright (c) 2021 chrono

-- lua is more flexible than json
-- you can use comment/expression
-- and more lua pragram

config = {

    -- should be same as client
    -- you could change it to ipc
    zmq_ipc_addr = "tcp://127.0.0.1:5555",

    http_addr = "http://localhost/cpp_note?token=cpp",

    time_interval = 5,  -- seconds

    keyword = "super",

    sold_criteria = 100,

    revenue_criteria = 1000,

    best_n  = 3,

    max_buf_size = 4 * 1024,

}

-- more config
others = {
    -- add more
}

-- debug: luajit conf.lua

--print(config.http_addr)
