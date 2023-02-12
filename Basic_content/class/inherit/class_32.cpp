#include <iostream>
#include <string>
using namespace std;

/* 继承中同名成员的处理方式 */
// 同名成员和成员函数
// 访问子类同名成员，直接访问即可
// 访问父类同名成员，需要加作用域，实例.父类域::同名成员

class Base
{
    public:
        int m_A;

        Base()
        {
            cout << "Base构造函数." << endl;
            m_A = 100;
        }

        ~Base()
        {
            cout << "Base的析构函数." << endl;
        }

        void func()
        {
            cout << "Base func." << endl;
        }
};

///////////////////////////////////////////////////////////
/* public */
class Son1: public Base
{
    public:
        int m_A;

        Son1()
        {
            cout << "Son1构造函数." << endl;
            m_A = 200;
        }

        ~Son1()
        {
            cout << "Son1的析构函数." << endl;
        }

        void func()
        {
            cout << "Son1 func." << endl;
        }
};

void test01()
{   
    // Base b;

    Son1 s1;
    cout << "Son1's m_A = " << s1.m_A << endl;
    cout << "Base's m_A = " << s1.Base::m_A << endl;     // 调用父类同名成员的方式
}

void test02()
{
    Son1 s1;
    s1.func(); 
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    s1.Base::func();    // 调用父类同名成员函数的方式
}

int main()
{
    test01();
    test02();
    return 0;
}