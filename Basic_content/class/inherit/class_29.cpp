#include <iostream>
#include <string>
using namespace std;

/* 继承方式 */
// 有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。
// 1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private
// 2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private
// 3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private
// 但无论哪种继承方式，上面两点都没有改变：
// 1.private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；
// 2.protected 成员可以被派生类访问。

class Base
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;

    public:
        virtual void func()
        {
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
            cout << "m_c = " << m_c << endl;
        }
};

///////////////////////////////////////////////////////////
/* public */
class Son1: public Base
{
    public:
        void func()
        {
            m_a = 10; // 正确，基类的public成员，在派生类中仍是public成员。
            m_b = 2; // 正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            // m_c = 1; // 错误，基类的private成员不能被派生类访问。
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
        }
};

///////////////////////////////////////////////////////////
/* protected */
class Son2: protected Base
{
    public:
        void func()
        {
            m_a = 100; // 正确，基类的public成员，在派生类中是protected成员。
            m_b = 20; // 正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            // m_c = 1; // 错误，基类的private成员不能被派生类访问。
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
        }
};

///////////////////////////////////////////////////////////
/* private */
class Son3: private Base
{
    public:
        void func()
        {
            m_a = 1000; // 正确，基类的public成员，在派生类中是private成员。
            m_b = 200; // 正确，基类的protected成员，在派生类中是private以被派生类访问。
            // m_c = 1; // 错误，基类的private成员不能被派生类访问。
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
        }
};

void test01()
{
    Son1 s1;
    s1.m_a = 23; // m_a在子类为public
    s1.func();
    // s1.m_b = 3; // m_b在子类为private

    Son2 s2;
    s2.func();
    // s2.m_a = 33; // m_a在子类为protected

    Son3 s3;
    s3.func();
    // s2.m_a = 33; // m_a在子类为private
}

int main()
{
    test01();
    return 0;
}