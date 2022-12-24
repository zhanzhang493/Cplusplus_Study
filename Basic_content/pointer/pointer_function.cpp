#include <iostream>
using namespace std;

/* 指针和函数 */
// 地址传递：
// 用指针可以操作数组

void swap(int *, int *);

int main()
{
    int a = 10;
    int b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void swap(int * p1, int * p2)
{   
    cout << "交换前：" << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "交换后：" << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
}