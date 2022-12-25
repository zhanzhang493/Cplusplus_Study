#include <iostream>
#include <string>
using namespace std;

/* 常量引用 */
// 常量引用主要是用来修饰形参，防止误操作
// 在形参列表中，可以用const修饰

void showValue(const int &);

int main()
{
    // int & a = 10; error, 引用必须引用一块合法的内存空间
    const int & ref = 10; // 只读
    // 加上const后，编译器将代码改为： int temp = 10; const int & ref = temp;

    int a = 20;
    cout << "a = " << a << endl;
    showValue(a);
    cout << "a = " << a << endl;
    return 0;
}

void showValue(const int & value) // const防止修改value对应的内存的值，只读
{
    // value = 100; 
    cout << "Val = " << value << endl;
}