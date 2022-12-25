#include <iostream>
#include <string>
using namespace std;

/* 堆区 */
// 由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
// 在c++中主要利用new在堆区开辟内存
// 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
// 语法: new 数据类型
// 利用new创建的数据，会返回该数据对应类型的指针


int * func_1();
void test01();
void test02();

int main()
{
    test01();
    test02();
}

void test02()
{
    int * arr = new int[10]; // 10 代表数组有10个元素
    for (int i = 0; i < 10; i++){
        *(arr+i) = i + 100;
    }

    for (int i = 0; i < 10; i++){
        cout << *(arr+i) << endl;
    }

    delete[] arr; // 释放堆区数组， 要加[]才可以
}

void test01()
{
    int * p = func_1();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    delete p;
    // cout << *p << endl; error, 再次访问会报错
}

int * func_1() 
{
    int * p = new int(10); // 利用new关键字，将数据开辟到堆区
    // 指针本身是个局部变量，只是指针保存的数据是堆区内存的地址
    return p;
}

