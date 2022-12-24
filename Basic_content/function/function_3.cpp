#include <iostream>
using namespace std;

/* 函数的常见样式 */
// 无参无返
// 有参无返
// 无参有返
// 有参有返


void test01()
{
    cout << "This is test01." << endl;
}

void test02(int a)
{
    cout << "This is test02: a = " << a << endl;
}

int test03()
{
    cout << "This is test03." << endl;
    return 1000;
}

int test04(int a)
{
    cout << "This is test04: a = " << a << endl;
    return a + 10;
}

int main()
{
    test01();

    test02(100);

    int num1 = test03();
    cout << "num1 = " << num1 << endl;

    int num2 = test04(20);
    cout << "num2 = " << num2 << endl;
}