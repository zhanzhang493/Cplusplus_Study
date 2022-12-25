#include <iostream>
#include <string>
using namespace std;

/* 引用做函数参数 */
// 函数传参时，可以利用reference技术让形参修饰实参
// 可以简化指针修改实参

void swap(int & a, int & b);

int main()
{
    int data1 = 10;
    int data2 = 20;
    
    cout << "data1 = " << data1 << endl;
    cout << "data2 = " << data2 << endl;

    swap(data1, data2);

    cout << "data1 = " << data1 << endl;
    cout << "data2 = " << data2 << endl;
    return 0;
}

void swap(int & a, int & b)
{
    cout << "交换前：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "交换后：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}