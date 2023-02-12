#include <iostream>
#include <string>
using namespace std;

/* 继承中同名静态成员的处理方式 */
// 静态成员和非静态成员出现同名，处理方式一致
// 访问子类同名成员，直接访问即可
// 访问父类同名成员，需要加作用域，实例.父类域::同名成员

class Base
{
    public:
        static int m_A;

        Base()
        {
            m_A = m_A - 1;
        }

        static void func()
        {
            cout << "Base func." << endl;
        }
};

int Base::m_A = 100;

///////////////////////////////////////////////////////////
/* public */
class Son1: public Base
{
    public:
        static int m_A;

        Son1()
        {
            m_A = m_A + 1;
        }

        static void func()
        {
            cout << "Son1 func." << endl;
        }
};
int Son1::m_A = 200;

void test01()
{   
    // 通过对象访问
    Son1 s1;
    cout << "Son1's m_A = " << s1.m_A << endl;
    cout << "Base's m_A = " << s1.Base::m_A << endl;     // 调用父类同名成员的方式

    // 通过类名访问
    cout << "Son1's m_A = " << Son1::m_A << endl;
    cout << "Base's m_A = " << Son1::Base::m_A << endl;     // 调用父类同名成员的方式

}

void test02()
{   
    // 通过对象访问
    Son1 s1;
    s1.func(); 
    // 如果子类中出现和父类同名的静态成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    s1.Base::func();    // 调用父类同名成员函数的方式

    // 通过类名访问
    Son1::func();
    Son1::Base::func();
}

int main()
{
    test01();
    test02();
    return 0;
}