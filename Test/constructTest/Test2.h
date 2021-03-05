#ifndef TEST_2_H
#define TEST_2_H

#include "Test1.h"

class Test2
{
public:
    Test1 test1;
    Test2(Test1& t1)
    {
        test1 = t1;
    }
};

#endif