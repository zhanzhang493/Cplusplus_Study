#include <iostream>
using namespace std;

/* 函数声明 */
// 函数可以声明多次，但只能定义一次
// 函数声明提前告诉编译器函数的存在，可以利用函数的声明

// 函数声明
int max(int, int);

int main()
{
    int a = 10, b = 20;
    cout << max(a, b) << endl;
}

// 函数定义
int max(int a, int b)
{
    return a > b ? a : b;
}