#include <iostream>
using namespace std;

/* 函数占位参数 */
// 函数的形参列表里可以有占位参数，用来做占位，调用函数时，必须填补该位置
// 占位参数还可以有默认参数

void func(int);

int main()
{
    func(10);

    return 0;
}

void func(int a)
{
    cout << "This is func." << endl;
}