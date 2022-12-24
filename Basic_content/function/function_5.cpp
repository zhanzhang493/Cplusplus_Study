#include <iostream>
using namespace std;
#include "swap.h" // 关联头文件

/* 函数的分文件编写 */
// 函数的分文件编写一般为4个步骤：
//1. 创建后缀名为.h的头文件
//2. 创建后缀名为.cpp的源文件
//3. 在头文件中写函数的声明
//4. 在源文件中写函数的定义

int main()
{
    int a = 10, b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// cmd: g++ function_5.cpp swap.cpp

