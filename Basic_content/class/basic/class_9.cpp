#include <iostream>
#include <string>
using namespace std;

/* 拷贝构造函数调用时机 */
// 拷贝构造函数的调用时机分三种情况
// 使用一个已经创建完成的对象来初始化一个新对象
// 值传递的方式给函数参数传值
// 以值方式返回局部对象

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

void dowork(Person p)
{
    cout << "dowork" << endl;
}

void test01()
{
    cout << "test 01" << endl;
    Person p;
    dowork(p);
}

Person do_work()
{   
    cout << "do_work" << endl;
    Person p1;
    cout << "do_work end" << endl;
    return p1;
}

void test02()
{
    cout << "test 02" << endl;
    Person p(do_work());
    cout << "test 02 end" << endl;
}

int main()
{
    // 使用一个已经创建完成的对象来初始化一个新对象
    Person p1("ZHAN", 28);
    Person p2(p1);
    p1.show_info();
    p2.show_info();

    // 值传递的方式给函数参数传值
    test01();

    // 以值方式返回局部对象
    test02();
    // 这里默认情况下一般会被编译器优化，减少不必要的拷贝构造，所以，具体的返回值可能会因编译器及编译选项的不同而不同。
    // 使用g++编译器，关闭优化g++ xxx.cpp -fno-elide-constructors后执行结果如下（-fno-elide-constructors选项就是用来关闭拷贝优化的）
    // g++ class_9.cpp -fno-elide-constructors
    return 0;
}