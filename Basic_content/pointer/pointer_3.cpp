#include <iostream>
using namespace std;

/* 空指针和野指针 */
// 空指针：指针变量指向内存中编号为0的空间
// 用途：初始化指针变量
// 注意：空指针指向的内存是不可以访问的

// 野指针：指向的是非法的内存，编译不出错，但是运行有风险


int main()
{   

    int * p = NULL; // int *p;

    int * q = (int *)0x1100; // 野指针

    return 0;
}