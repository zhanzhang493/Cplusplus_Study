#include <iostream>
#include <string>
using namespace std;

/* 类模板 */
// 建立一个通用类，类中的成员 数据类型可以不具体定制，用一个虚拟的类型来代表
// 语法
// template<typename T>
// class {...};

template<typename T1, typename T2>
class Person
{
    public:
        T1 m_Name;
        T2 m_Age;

        Person(T1 name, T2 age): m_Name(name), m_Age(age) {}

        void showinfo()
        {
            cout << "name: " << this->m_Name << endl;
            cout << "name: " << m_Age << endl;
        } 
};

void test01()
{
    Person<string, int> p1("zhangzhan", 19);
    p1.showinfo();
}

int main()
{
    test01();
    return 0;
}