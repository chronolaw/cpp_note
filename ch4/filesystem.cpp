// Copyright (c) 2021 by Chrono
//
// g++ filesystem.cpp -std=c++17 -lstdc++fs -o a.out;./a.out
// g++ filesystem.cpp -std=c++20 -o a.out;./a.out

#include <cassert>

#include <iostream>

#if __has_include(<filesystem>)
#include <filesystem>
using namespace std::filesystem;
#else
#include <experimental/filesystem>
using namespace std::experimental::filesystem;
#endif


void case1()
{
}

int main()
{
    case1();

    using namespace std;

    cout << "filesystem demo" << endl;
}
