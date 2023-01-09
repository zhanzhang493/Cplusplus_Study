#include <iostream>
#include <string>
using namespace std;

/* 运算符重载 */
// 对于内置数据类型，编译器知道如何进行运算
// 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 两种重载方式： class内成员函数重载、全局重载

/* 函数调用运算符 */
// 函数调用运算符 () 也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活

class MyPrint
{
    public:
        // 重载函数调用运算符
        void operator() (string test)
        {
            cout << test << endl;
        }
};

class MyAdd
{
    public:
        int operator() (int a, int b)
        {
            return a + b;
        }
};

void test01()
{
    MyPrint my_print;
    my_print("hello world.");   // 由于重载后使用的方式非常像函数的调用，因此称为仿函数
}

void test02()
{
    MyAdd my_add;
    int ret = my_add(10, 12);
    cout << "ret = "<< ret << endl;

    // 匿名函数对象，见class_8.cpp
    cout << MyAdd()(100, 200) << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}