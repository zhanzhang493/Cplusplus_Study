#include <iostream>
#include <string>
using namespace std;

/* 类模板 成员函数 类外实现 */
// 类外实现 类模板的成员函数

template<typename T1, typename T2>
class Base
{
    public:
        T1 m_Mame;
        T2 m_Age;

        Base(T1 name, T2 age);

        void showPerson();
        
};

// 构造函数类外实现
template<typename T1, typename T2>
Base<T1, T2>::Base(T1 name, T2 age)
{
    this->m_Mame = name;
    this->m_Age = age;
}

template<typename T1, typename T2>
void Base<T1, T2>::showPerson()
{
    cout << "name: " << this->m_Mame << endl;
    cout << "age: " << this->m_Age << endl;
}


void test01()
{
    Base<string, int> p("zhangzhan", 19);
    p.showPerson();

}

int main()
{
    test01();
    return 0;
}