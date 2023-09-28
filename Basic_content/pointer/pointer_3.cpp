#include <iostream>
using namespace std;

/* 空指针和野指针 */
// * 空指针：指针变量指向内存中编号为0的空间
// * 用途：初始化指针变量
// * 注意：空指针指向的内存是不可以访问的

// * 野指针：指向的是非法的内存，编译不出错，但是运行有风险


int main()
{   
    int * p = nullptr; // int *p;
    std::cout << "nullptr address: " << p << std::endl;
    int * q = (int *)0x1100; // 野指针
    std:: cout << "野指针q的地址: " << q << std::endl;
    // std:: cout << "野指针q的值: " << *q << std::endl;  // 编译正确，运行错误

    return 0;
}