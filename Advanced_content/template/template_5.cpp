#include <iostream>
using namespace std;

/* 普通函数和函数模板的调用规则 */
// 如果函数模板和普通函数都可以实现，优先调用普通函数
// 可以通过 空模板参数列表 来强制调用函数模板
// 函数模板也可以发生重载
// 如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b)
{
    cout << "普通函数 myPrint run" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
    cout << "函数模板 myPrint run" << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "重载函数模板 myPrint run" << endl;
}

void test01()
{
    int a = 10, b = 20;

    // 如果函数模板和普通函数都可以实现，优先调用普通函数
    myPrint(a, b);

    // 空模板参数列表
    myPrint<>(a, b);

    // 函数模板也可以发生重载
    myPrint(a, b, 10);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    myPrint('c', 'b');

}

int main()
{
    test01();
    return 0;
}