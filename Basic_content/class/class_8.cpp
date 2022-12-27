#include <iostream>
#include <string>
using namespace std;

/* 构造函数 */
// 两种分类方式
// 按参数分类： 有参构造和无参构造(默认构造)
// 按类型：普通构造和拷贝构造
// 三种调用方式：
// 括号法
// 显示法
// 隐式转换法

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
    cout << "Person的无参构造函数调用." << endl;
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

int main()
{   
    // 括号法
    Person p1;
    Person p2("ZHAN", 28);
    Person p3(p2);

    p3.show_info();

    // 注意事项：调用默认构造函数时候，不要加()
    // Person p4(); error
    // 编译器会认为是一个函数的声明，不会认为在创建对象

    // 显示法
    Person c1;
    Person c2 = Person("Henry", 20);
    Person c3 = Person(c2);
    c3.show_info();

    Person("Henry", 20); // 匿名对象，特点：当前执行结束后，系统会立刻回收掉匿名对象

    // 注意事项：不要利用拷贝构造函数，初始化匿名对象
    // Person(c3); error
    // 编译器会认为Person(c3) === Person c3, 重声明


    // 隐式转换法
    Person f1 = {"Tay", 28}; // 相当于写了 Person f1 = Person("Tay", 28)
    Person f2 = f1; // 相当于写了 Person f1 = Person("Tay", 28)
    return 0;
}

