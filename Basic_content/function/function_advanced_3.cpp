#include <iostream>
using namespace std;

/* 函数重载 */
// 作用: 函数名可以相同，提高复用性
// 函数重载满足条件: 1. 同一个作用域下; 2. 函数名称相同; 3. 函数参数类型不同，或者个数不同，或者顺序不同
// 函数返回值不可以作为函数重载条件

/* 注意事项 */
// 引用作为重载条件
// 函数重载和默认参数 -> 容易出现问题，编译器找不到正确的函数入口

void func(int &);
void func(const int &);
void func(float);
void func(double);

int main()
{   
    func((float)10);
    func((double)10);

    /* reference */
    int a = 10;
    func(a);
    const int b = 10;
    func(b);

    func(10);   // const int &a = 10; 
    // 加上const后，编译器将代码改为： int temp = 10; const int & ref = temp;

    return 0;
}

// 都在全局作用域下
void func(int & a)
{
    cout << "This is func_int ref result: " << a << endl;
}

void func(const int & a)
{
    cout << "This is const func_int ref result: " << a << endl;
}

void func(float a)
{
    cout << "This is func_float result: " << a << endl;
}

void func(double a)
{
    cout << "This is func_double result: " << a << endl;
}