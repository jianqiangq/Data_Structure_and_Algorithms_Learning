#ifndef TEST_1_H
#define TEST_1_H

#include <iostream>

using namespace std;

class Test1
{
public:
    int a;

    Test1()
    {
        cout << "构造函数" << endl;
    }

    Test1(const Test1& t1)
    {
        this->a = t1.a;
        cout << "拷贝构造函数" << endl;
    }

    Test1& operator=(const Test1& t1)
    {
        this->a = t1.a;
        cout << "赋值运算" << endl;
        return *this;
    }
};

#endif