#include <iostream>
using namespace std;

/* 普通函数和函数模板的区别 */
// 普通函数调用时，可以发生自动类型转换
// 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// 如果利用显示指定类型，可以发生隐式类型转换

int myAdd01(int a, int b)
{
    return a+b;
}

template<typename T>
T myAdd(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10, b = 23;
    char c = 'c';
    
    cout << "普通函数调用时，可以发生自动类型转换" << endl;
    cout << myAdd01(a, b) << endl;
    cout << myAdd01(a, c) << endl;

    cout << "函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换" << endl;
    cout << myAdd(a, b) << endl;
    // cout << myAdd(a, c) << endl; // error

    cout << "如果利用显示指定类型，可以发生隐式类型转换" << endl;
    cout << myAdd<int>(a, c) << endl;
}

int main()
{
    test01();
    return 0;
}