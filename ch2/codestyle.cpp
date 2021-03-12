// Copyright (c) 2021 by Chrono
//
// g++ codestyle.cpp -std=c++17 -o a.out;./a.out
// g++ codestyle.cpp -std=c++20 -o a.out;./a.out
//

#include <iostream>
#include <string>

using std::string;

#define  MAX_PATH_LEN  256

int g_sys_flag;

namespace linux_sys {
  void get_rlimit_core();
}

class FilePath final
{
public:
  void set_path(const string& str);
private:
  string m_path;
  int    m_level;
};


// author   : chrono
// date     : 2021-xx-xx
// purpose  : get inner counter value of generic T
// notice   : T must have xxx member
// notice   : return value maybe -1, means xxx, you should xxx
template<typename T>
int get_value(const T& v);

int main()
{
    using namespace std;

    cout << "show your code style." << endl;
}
