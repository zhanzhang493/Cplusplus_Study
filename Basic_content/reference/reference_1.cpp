#include <iostream>
#include <string>
using namespace std;

/* 引用 */
// 给变量起个别名
// 语法： 数据类型 &别名 = 原名
// 引用必须初始化
// 引用初始化后，不可以改变

int main()
{
    int a = 10;
    int & b = a;
    int c = 100;

    // int & d = 10; error, 引用必须引用一块合法的内存空间
    
    b = 20;
    cout << "a的值: " << a << endl;

    b = c;
    cout << "a, b的值: " << b << endl;
}