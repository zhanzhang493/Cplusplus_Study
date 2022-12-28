#include <iostream>
#include <string>
using namespace std;

/* 构造函数的调用规则 */
// 默认情况下，c++编译器至少给一个类添加3个函数
// 默认构造函数（无参，函数体为空）
// 默认析构函数（无参，函数体为空）
// 默认拷贝构造函数，对属性进行值拷贝

// 构造函数调用规则如下：
// 如果用户定义有参构造函数，c++不在提供默认无参构造函数，但会提供默认拷贝构造函数
// 如果用户定义拷贝构造函数，c++不在提供其他构造函数

class Person
{
    public:
        Person();

        Person(string name, int a);

        Person(const Person & p);

        ~Person();

        void show_info();

    private:
        string m_name;
        int m_age;

};

Person::Person()
{
    cout << "Person的无参(默认)构造函数调用." << endl;
}

Person::Person(string name, int a)
{
    m_name = name;
    m_age = a;
    cout << "Person的有参构造函数调用." << endl;
}

Person::Person(const Person & p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    cout << "Person的拷贝构造函数调用." << endl;
}

Person::~Person()
{
    cout << "Person的析构函数调用." << endl;
}

void Person::show_info()
{
    cout << "Name: " << m_name << endl;
    cout << "Age: " << m_age << endl;
}

void test01()
{
    Person p1("ZHAN", 28);
    Person p2(p1);
    p2.show_info();
}

int main()
{
    test01();
    return 0;
}