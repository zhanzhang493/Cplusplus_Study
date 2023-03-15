#include <iostream>
#include <string>
using namespace std;

/* 类模板 与 函数模板 的区别*/
// 类模板没有自动类型推导的使用方式
// 类模板在模板参数列表中可以有默认参数

template<typename T1, typename T2 = int>
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
    // Person p0("zhangzhan", 19);

    Person<string> p1("zhangzhan", 19);
    p1.showinfo();

    Person<string, double> p2("zhangzhan", 19.5);
    p2.showinfo();
}

int main()
{
    test01();
    return 0;
}