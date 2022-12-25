#include <iostream>
#include <string>
using namespace std;

/* 引用做函数返回值 */
// 可以作为函数的返回值
// 注意：不要返回局部变量的引用
// 如果函数的返回值是引用，这个函数调用可以作为左值

int * test01();
int & test02();

int main()
{
    int * ref1 = test01();
    cout << "ref1指向的地址: " << ref1 << endl;
    cout << "ref1的指向的值: " << *ref1 << endl;

    * ref1 = 500;
    cout << "ref1指向的地址: " << ref1 << endl;
    cout << "ref1的指向的值: " << *ref1 << endl;

    delete ref1;

    int & ref2 = test02();
    cout << "ref2的值是: " << ref2 << endl;
    cout << "ref2的值是: " << ref2 << endl;

    test02() = 1000; // 左值
    cout << "ref2的值是: " << ref2 << endl;
    cout << "ref2的值是: " << ref2 << endl;
    return 0;
}

int * test01()
{
    // int a = 10; // 局部变量存放在栈区
    int * ptr = new int(10); // 局部变量存放在堆区
    cout << "堆区内存的地址: " << ptr << endl;
    return ptr;
}

int & test02()
{
    static int a = 20; // 静态变量存放在全局区
    return a;
}