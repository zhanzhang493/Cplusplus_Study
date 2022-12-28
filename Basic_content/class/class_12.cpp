#include <iostream>
#include <string>
using namespace std;

/* 初始化列表 */
// C++提供了初始化列表语法，用来初始化属性
// 语法： 构造函数(): 属性1(值1), 属性2(值2), ... {}

class Person
{
    public:
        Person(): m_name("TINA"), m_age(18)     // 初始化列表
        {
            m_height = new int(180);
            cout << "Person的无参(默认)构造函数调用." << endl;
        }

        Person(string name, int a, int height): m_name(name), m_age(a)   // 初始化列表
        {
            m_height = new int(height);
            cout << "Person的有参构造函数调用." << endl;
        }

        Person(const Person & p);    // 如果利用系统默认的浅拷贝构造函数，堆区的内存会被重复释放，bug

        ~Person();

        void show_info();

    private:
        string m_name;
        int m_age;
        int * m_height;

};

Person::Person(const Person & p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    // m_height = p.m_height; error: 编译器默认实现这行代码
    m_height = new int(*p.m_height);
    cout << "Person的拷贝构造函数调用." << endl;
}

Person::~Person()
{   
    if (m_height != NULL){
        delete m_height;    // 释放内存
        m_height = NULL;
    }
    cout << "Person的析构函数调用." << endl;
}

void Person::show_info()
{
    cout << "Name: " << m_name << endl;
    cout << "Age: " << m_age << endl;
    cout << "Height: " << * m_height << endl;
}

void test01()
{
    Person p1("ZHAN", 18, 178);
    p1.show_info();

    Person p2;
    p2.show_info();
    // p2 = Person(p1);  // error

    Person p3 = Person(p1); // correct
    p3.show_info();
}

int main()
{
    test01();
    return 0;
}