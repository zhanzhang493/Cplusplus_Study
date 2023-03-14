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
// 1. 自动类型推导: 必须推导出一致的数据类型T,才可以使用
// 2. 显示指定类型
// 模板必须确定出T的数据类型，才可以使用

template<class T> // typename = class, here
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    cout << "Template" << endl;

    double a = 3.14;
    int b = 2.33;
    double c = 4.55;

    // myswap(a, b); // error, 不一致的数据类型
    myswap(a, c);

    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
}

template<typename T>
void func()
{
    cout << "func run." << endl;
}

void test02()
{
    func<int>();    // ok
    // func(); // 自动推导失效
}

int main()
{
    test01();
    test02();
    return 0;
}