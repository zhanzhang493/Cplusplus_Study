#include <iostream>
#include <string>
using namespace std;

/* 运算符重载 */
// 对于内置数据类型，编译器知道如何进行运算
// 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 两种重载方式： class内成员函数重载、全局重载


/* 加号运算符重载 */
class Person
{
    public:
        int m_a;
        int m_b;

        Person(): m_a(0), m_b(0) 
        {
            cout << "Person的无参(默认)构造函数调用." << endl;
        }

        Person(int a, int b): m_a(a), m_b(b) 
        {
            cout << "Person的有参构造函数调用." << endl;
        }

        Person(const Person & p) 
        {
            cout << "Person的拷贝构造函数调用." << endl;
            m_a = p.m_a;
            m_b = p.m_b;
        }

        ~Person()
        {
            cout << "Person的析构函数调用." << endl;
        }

        Person Person_add_Person(Person &p)
        {
            cout << "Person_add_Person." << endl;
            Person temp;
            temp.m_a = this->m_a + p.m_a;
            temp.m_b = this->m_b + p.m_b;
            return temp;
        }

        Person operator+ (Person &p) // class内成员函数重载
        {
            cout << "Person的+重载." << endl;
            Person temp;
            temp.m_a = this->m_a + p.m_a;
            temp.m_b = this->m_b + p.m_b;
            return temp;
        }

        void show_person()
        {
            cout << "m_a = " << m_a << endl;
            cout << "m_b = " << m_b << endl;
        }
};


Person operator+ (Person &p, int ab) // 全局函数重载
{
    cout << "全局+重载." << endl;
    Person temp;
    temp.m_a = p.m_a + ab;
    temp.m_b = p.m_b + ab;
    return temp;
}

void test01()
{
    Person p1(2, 20), p2(4, 30);

    // Person p3;
    // p3 = p1 + p2;
    // p3.show_person();

    // different
    Person p3 = p1 + p2;
    p3.show_person();

    p3 = p3 + 20;
    p3.show_person();

}

int main()
{
    test01();
    return 0;
}