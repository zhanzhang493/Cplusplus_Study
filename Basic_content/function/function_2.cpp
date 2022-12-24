#include <iostream>
using namespace std;

/* 函数值传递 */
// 值传递的时候，函数的形参发生变化，并不会影响实参

void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    return;
}

int main()
{
    int a = 10, b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}