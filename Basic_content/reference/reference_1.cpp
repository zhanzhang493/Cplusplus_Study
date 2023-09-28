#include <iostream>
#include <string>

/* 引用 */
// * 给变量起个别名
// * 语法： 数据类型 &别名 = 原名
// * 引用必须初始化
// * 引用初始化后，不可以改变
// * 引用, 必须引用一块合法的内存空间

int main()
{
    int a = 10;
    int& b = a;
    std::cout << "b是a的引用." << std::endl;

    // int& d = 10; error, "引用必须引用一块合法的内存空间"
    
    b = 20;
    std::cout << "修改b的值为: " << b << ", 此时a的值为: " << a << std::endl;
}