#include <iostream>
#include <string>
using namespace std;

/* 继承中的对象类型 */

#define FUNC 1

class Base
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;    // 私有成员只是被隐藏了
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性，是被编译器隐藏，因此是访问不到的，但是确实被继承下去了

#if FUNC
    public:
        virtual void func()
        {
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
            cout << "m_c = " << m_c << endl;
        }
#endif
};

///////////////////////////////////////////////////////////
/* public */
class Son1: public Base
{
    public:
        int m_d;
#if FUNC
        void func()
        {
            m_a = 10; // 正确，基类的public成员，在派生类中仍是public成员。
            m_b = 2; // 正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            m_d = 30;
            // m_c = 1; // 错误，基类的private成员不能被派生类访问。
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
            cout << "m_d = " << m_d << endl;
        }
#endif
};

void test01()
{   
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of Base: " << sizeof(Base) << endl;
    Son1 s1;
    s1.m_a = 23; // m_a在子类为public
    // s1.func();
    // s1.m_b = 3; // m_b在子类为private
    cout << "size of son1: " << sizeof(s1) << endl;
}

int main()
{
    test01();
    return 0;
}