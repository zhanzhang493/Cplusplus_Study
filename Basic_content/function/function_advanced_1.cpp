#include <iostream>
using namespace std;

/* 函数默认参数 */
// 函数的形参是可以由默认值的
// 语法： 返回值类型 函数名(参数=默认值){}
// 如果某个参数是默认参数，那么它后面的参数必须是默认参数
// 默认参数可以放在声明、或者定义中，但是只能二者选一

int func(int a, int b = 20, int c = 30);

int main()
{
    cout << func(10, 30) << endl;

    return 0;
}

int func(int a, int b, int c)
{
    return a + b + c;
}