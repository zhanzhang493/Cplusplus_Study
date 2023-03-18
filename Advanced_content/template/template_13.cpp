#include <iostream>
#include <string>
using namespace std;


/* 类模板 分文件编写 */
// 类模板成员函数创建时机是在调用阶段，导致分文件编写时，链接不到

// 解决办法1：直接包含在.cpp文件中
// #include "Base.cpp"

// 解决办法2：将声明和实现写在同一个文件中，并更改后缀名为.hpp，.hpp是约定的名称，并不是强制
#include "Base.hpp"

void test01()
{
    Base<string, int> p("zhangzhan", 19);
    p.showPerson();

}

int main()
{
    test01();
    return 0;
}