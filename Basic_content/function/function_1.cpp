#include <iostream>
using namespace std;

/* 函数 */
// 返回值类型
// 函数名
// 参数列表 --> 形参列表
// 函数体语句
// return 表达式

/*
return_type function_name( parameter list )
{
   body of the function
   return
}
*/

int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}


int main()
{
    int a = 10;
    int b = 20;  // a, b为实参
    int c = add(a, b); // 调用函数时，实参值会传递给形参

    cout << c << endl;
}