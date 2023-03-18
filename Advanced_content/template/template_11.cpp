#include <iostream>
#include <string>
using namespace std;

/* 类模板 与 继承*/
// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// 如果不指定，编译器无法给出子类分配的内存
// 如果想要灵活指定出父类中T的类型，子类也需要变为类模板

template<typename T1>
class Base
{
    public:
        T1 m_name;

        Base(T1 name): m_name(name) {}

        virtual void showInfo()
        {
            cout << "name: " << m_name << endl;
        }
};

// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// class Son: public Base // error
class Son: public Base<string>
{
    public:
        Son(string name): Base(name) {}    
};

// 如果想要灵活指定出父类中T的类型，子类也需要变为类模板
template<class T1, class T2>
class Wife: public Base<T2>
{
    public:
        T1 m_age;
        Wife(T1 age, T2 name): Base<T2>(name)
        {
            this->m_age = age;
        }

        virtual void showInfo()
        {
            cout << "name: " << this->m_name << endl;
            cout << "age: " << this->m_age << endl;
        }
};

void test01()
{
    Son s1("zhang");
    s1.showInfo();
    Wife<int, string> w1(18, "fay");
    w1.showInfo();
}

int main()
{
    test01();
    return 0;
}