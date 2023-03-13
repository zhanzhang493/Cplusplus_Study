#include <iostream>
using namespace std;

/* 模板 */
// 泛型编程
// 建立通用的磨具，大大提高复用性
// 模板不能直接使用，它只是一个框架
// 通用但不是万能的

// 两种模板机制：函数模板、类模板

/* 函数模板 */
// 函数模板的作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表
// 语法：
// template<typename T>
// 函数声明或定义
// template: 声明创建模板
// typename: 表明后面的符号是一种数据类型，可以用class代替
// T: 通用的数据类型，名称可以替换，通常为大写字母

// 两种方式使用模板
// 1. 自动类型推导
// 2. 显示指定类型

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 3;
    int b = 4;
    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

template<typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test02()
{
    cout << "Template" << endl;

    double a = 3.14;
    double b = 2.33;

    // myswap(a, b); // method 1

    myswap<double>(a, b);  // method 2

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{   
    test01();
    test02();
    return 0;
}