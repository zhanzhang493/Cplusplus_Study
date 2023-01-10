#include <iostream>
#include <string>
using namespace std;

/* 类对象作为类的成员 */
// C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
// 当创建B(Person)对象时，A(手机)与B的构造和析构顺序是谁先谁后

class Phone
{
    public:
        Phone(): p_name("Iphone")
        {
            cout << "Phone的无参(默认)构造函数调用." << endl;
        };

        Phone(string name): p_name(name)
        {
            cout << "Phone的有参构造函数调用." << endl;
        };

        Phone(const Phone & p)
        {
            p_name = p.p_name;
            cout << "Phone的拷贝构造函数调用." << endl;
        }

        ~Phone()
        {
            cout << "Phone的析构函数调用." << endl;
        }

        void set_phone_name(string name)
        {
            p_name = name;
        }

        string get_phone_name()
        {
            return p_name;
        }

    private:
        string p_name;
};

class Person
{
    public:
        Person(): m_name("TINA"), m_age(18)     // 初始化列表
        {
            cout << "Person的无参(默认)构造函数调用." << endl;
        }

        Person(string name, int a, string phone_name): m_name(name), m_age(a), m_phone(phone_name)   // 初始化列表
        {
            cout << "Person的有参构造函数调用." << endl;
        }

        Person(const Person & p)
        {
            m_name = p.m_name;
            m_age = p.m_age;
            // 私有的m_phone如何赋值?
            cout << "Person的拷贝构造函数调用." << endl;
        }

        ~Person()
        {
            cout << "Person的析构函数调用." << endl;
        }

        void show_info()
        {
            cout << "Name: " << m_name << endl;
            cout << "Age: " << m_age << endl;
            cout << "Phone name: " << m_phone.get_phone_name() << endl;
        }

    private:
        string m_name;
        int m_age;
        Phone m_phone;
};

void test01()
{
    Person p1("Zhan", 28, "Huawei");
    p1.show_info();


    Person p2;
    p2.show_info();

    Person p3(p2);
    p3.show_info();
}

int main()
{
    test01();
    return 0;
}