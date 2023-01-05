#include <iostream>
#include <string>
using namespace std;

/* 运算符重载 */
// 对于内置数据类型，编译器知道如何进行运算
// 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 两种重载方式： class内成员函数重载、全局重载

/* 关系运算符重载 */
class Person
{   
    friend ostream & operator << (ostream & cout, Person & p);
    public:

        Person(): m_a(0), m_b(0) 
        {   
            m_age = new int(0);
            cout << "Person的无参(默认)构造函数调用." << endl;
        }

        Person(int a, int b, int c): m_a(a), m_b(b) 
        {
            m_age = new int(c);
            cout << "Person的有参构造函数调用." << endl;
        }

        Person(const Person & p) 
        {
            cout << "Person的拷贝构造函数调用." << endl;
            m_a = p.m_a;
            m_b = p.m_b;
            m_age = new int(*p.m_age);
        }

        ~Person()
        {   
            delete m_age;
            cout << "Person的析构函数调用." << endl;
        }

        Person & operator= (Person &p) // 若为void, 则不可以a=b=c
        {
            // 编译器提供浅拷贝

            // 应该先判断是否有属性在堆区，如果有先释放，然后再深拷贝
            if (m_age != NULL)
            {
                delete m_age;
                m_age = NULL;
            }
            // 深拷贝
            m_a = p.m_a;
            m_b = p.m_b;
            m_age = new int(*p.m_age);
            return *this;
        }

        bool operator==(Person & p)
        {
            if (this->m_a == p.m_a && this->m_b == p.m_b && *this->m_age == *p.m_age)
            {
                return true;
            }else{
                return false;
            }
        }

        bool operator!=(Person & p)
        {
            if (this->m_a == p.m_a && this->m_b == p.m_b && *this->m_age == *p.m_age)
            {
                return false;
            }else{
                return true;
            }
        }

    private:
        int m_a;
        int m_b;
        int *m_age;
};

ostream & operator << (ostream & cout, Person & p) // class内成员函数重载
{   
    cout << "m_a = " << p.m_a << endl;
    cout << "m_b = " << p.m_b << endl;
    cout << "age = " << *p.m_age << endl;
    return cout;
}

void test01()
{   
    cout << "test01()." << endl;
    Person p1(2, 20, 18);

    Person p2(4, 40, -10);

    Person p3;
    if (p1 == p2)
    {

    }else{
    p3 = p1 = p2;
    }

    cout << p1 << "end." << endl;
    cout << p2 << "end." << endl;
    cout << p3 << "end." << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
}

int main()
{
    test01();
    return 0;
}