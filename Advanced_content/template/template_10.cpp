#include <iostream>
#include <string>
using namespace std;

/* 类模板对象做函数参数 */
// 类模板实例化出的对象，向函数传参的方式

// 三种方式
// 1. 指定传入的类型 -- 直接显示对象的数据类型
// 2. 参数模板化 -- 将对象中的参数变为模板进行传递
// 3. 整个类模板化 -- 将这个对象的类型，模板化进行传递


template<class T1, class T2>
class Person
{
    public:
        T1 m_Name;
        T2 m_Age;

        Person(T1 name, T2 age): m_Name(name), m_Age(age) {}

        void showPerson()
        {
            cout << "Name: " << this->m_Name << endl;
        }

};

// 1. 指定传入的类型 -- 直接显示对象的数据类型
void pringPerson1(Person<string, int> &p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int> p1("zhangzhan", 19);
    pringPerson1(p1);
}

// 2. 参数模板化 -- 将对象中的参数变为模板进行传递
template<typename T1, typename T2>
void pringPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1: " << typeid(T1).name() << endl;
    cout << "T1: " << typeid(T2).name() << endl;
}

void test02()
{
    Person<string, int> p2("fay", 18);
    pringPerson2(p2);
}

// 3. 整个类模板化 -- 将这个对象的类型，模板化进行传递
template<typename T1>
void pringPerson3(T1 &p)
{
    p.showPerson();
    cout << "T1: " << typeid(T1).name() << endl;
}

void test03()
{
    Person<string, int> p3("XXX", 20);
    pringPerson3(p3);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}