#include <iostream>
using namespace std;

/* 指针 */
// * 对象：一块连续的存储区域
// * 变量名：某块内存的名字

int main()
{
    // 定义指针
    int a = 10;
    int* p = nullptr;
    p = &a;
    cout << "a的地址: " << p << endl;

    // 使用指针
    // 可以通过解引用的方式来找到指针指向的内存中的数据
    cout << "a的值: " << *p << endl;
    *p = 1000;
    cout << "a的值: " << a << endl;
    
}