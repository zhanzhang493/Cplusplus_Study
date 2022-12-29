#include <iostream>
#include <string>
using namespace std;

/* 静态成员 */
// 静态成员就是在成员变量和成员函数之前加上static，称为静态成员

/* 静态成员变量 */
// 静态成员变量不属于某个对象，所有对象共享同一份数据
// 在编译阶段分配内存
// 类内声明，类外初始化
// 普通的成员变量是定义初始化的时候才会进行内存的申请，因为static类型的变量都是随类的，因此不能随着对象的创建而申请内存，所以需要单独的进行类外定义，在定义的时候C++编译器会申请内存给静态指针。
// 静态成员变量有两种访问方式：通过对象进行访问、通过类名进行访问
// 静态成员变量也是有访问权限的

/* 静态成员函数 */
// 所有对象共享一个函数
// 静态成员函数，只能访问静态成员变量
// 静态成员函数有两种访问方式：通过对象进行访问、通过类名进行访问
// 静态成员变量也是有访问权限的

class Person
{
    private:
        static int m_B;
        
    public:
        static int m_A; // 类内声明
        int m_C;

        Person();

        static void func()
        {
            m_A += 1;
            m_B -= 1;
            // m_C += 1; error, 不可以访问，非静态成员变量，无法区分到底是哪个对象的非静态成员变量
            cout << "static void func 调用." << endl;
            cout << "m_A = " << m_A << endl;
            cout << "m_B = " << m_B << endl;
        }
};

int Person::m_A = 0; // 必须类外初始化，否则编译器无法操作内存
int Person::m_B = 0;

Person::Person()
{
    m_C = 0;
    m_A += 10;
    m_B += 5;
    cout << "Person的无参(默认)构造函数调用." << endl;
}

void test01()
{
    Person p;
    p.func();

    Person::func();
}


int main()
{   
    Person p1;
    cout << p1.m_A << endl;

    Person p2;
    cout << p1.m_A << endl;
    
    cout << Person::m_A << endl;

    // cout << Person::m_B << endl; error，private权限

    test01();

    return 0;
}
