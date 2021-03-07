#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;
int main()
{
    uint32_t a = 0x12345678;
    char *p = (char*)&a;

    // c++变量为小端存储
    if(*p == 0x12 && *(p+1) == 0x34)
        cout << "大端存储" << endl;
    if(*p == 0x78 && *(p+1) == 0x56)
        cout << "小端存储" << endl;

    uint32_t a_ = ((a << 8) & 0xFF00FF00 ) | ((a >> 8) & 0xFF00FF);
    a_ = (a_ << 16) | (a_ >> 16);
    p = (char*)&a_;

    if(*p == 0x12 && *(p+1) == 0x34)
        cout << "大端存储" << endl;
    if(*p == 0x78 && *(p+1) == 0x56)
        cout << "小端存储" << endl;

    return 0;
}


// // 这些类型的头文件 #include <stdint.h>
// typedef unsigned char uint8_t 

// typedef unsigned int uint16_t 

// typedef unsigned long int uint32_t 

// typedef unsigned long long int uint64_t 

// typedef signed char int8_t 

// typedef signed int int16_t 

// typedef signed long int int32_t 

// typedef signed long long int int64_t 