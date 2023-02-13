#include <iostream>
#include <string>
using namespace std;

/* 多继承语法 */
// class 子类: 继承放式 父类1, 继承放式 父类2, ...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
// c++ 不建议多继承

class Base1
{
public:
    int m_A;

    Base1()
    {
        m_A = 100;
    }
};

class Base2
{
public:
    int m_A;

    Base2()
    {
        m_A = 200;
    }
};

///////////////////////////////////////////////////////////
/* public */
class Son1 : public Base1, public Base2
{
public:
    int m_C;
    int m_D;

    Son1()
    {
        m_C = 300;
        m_D = 400;
    }
};

void test01()
{
    Son1 s1;
    cout << "Sizeof Son1: " << sizeof(s1) << endl;
    cout << "Son1's Base1's m_A = " << s1.Base1::m_A << endl;
    cout << "Son1's Base2's m_A = " << s1.Base2::m_A << endl;
    cout << "Son1's m_C = " << s1.m_C << endl;
    cout << "Son1's m_D = " << s1.m_D << endl;
}


int main()
{
    test01();
    return 0;
}