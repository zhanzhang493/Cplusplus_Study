#include <iostream>
#include <string>
using namespace std;

/* 运算符重载 */
// 对于内置数据类型，编译器知道如何进行运算
// 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 两种重载方式： class内成员函数重载、全局重载


/* 左移运算符重载 */
class Person
{   
    friend ostream & operator << (ostream & cout, Person & p);
    public:

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

        Person operator+ (Person &p) // class内成员函数重载
        {
            cout << "Person的+重载." << endl;
            Person temp;
            temp.m_a = this->m_a + p.m_a;
            temp.m_b = this->m_b + p.m_b;
            return temp;
        }

        private:
            int m_a;
            int m_b;
};

ostream & operator << (ostream & cout, Person & p) // class内成员函数重载
{   
    cout << "m_a = " << p.m_a << endl;
    cout << "m_b = " << p.m_b << endl;
    return cout;
}

void test01()
{
    Person p1(2, 20);

    cout << p1 << "end." << endl;

}

int main()
{
    test01();
    return 0;
}