#include <iostream>
#include <string>
using namespace std;

/* 深拷贝和浅拷贝 */
// 浅拷贝: 简单的赋值拷贝操作，指针指向的地址被简单的拷贝操作，并未开辟新的内存空间，因此会造成堆区的内存会重复释放
// 深拷贝: 在堆区重新申请空间，进行拷贝操作
// Interesting
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

class Person
{
    public:
        Person();

        Person(string name, int a, int height);

        Person(const Person & p);    // 如果利用系统默认的浅拷贝构造函数，堆区的内存会被重复释放，bug

        ~Person();

        void show_info();

    private:
        string m_name;
        int m_age;
        int * m_height;

};

Person::Person()
{
    cout << "Person的无参(默认)构造函数调用." << endl;
}

Person::Person(string name, int a, int height)
{
    m_name = name;
    m_age = a;
    m_height = new int(height);
    cout << "Person的有参构造函数调用." << endl;
}

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
    Person p2(p1);
    p2.show_info();
}

int main()
{
    test01();
    return 0;
}