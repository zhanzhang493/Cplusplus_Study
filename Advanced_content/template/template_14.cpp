#include <iostream>
#include <string>
using namespace std;

/* 类模板 与 友元 */
// 全局函数类内实现 - 直接在类内声明友元即可
// 全局函数类外是实现 - 需要提前让编译器知道全局函数的存在

// 全局函数类外是实现 - 提前让编译器知道Base类存在
template<typename T1, typename T2>
class Base;

// 全局函数 类外实现 函数模板的实现, 需要让编译器提前知道这个函数的存在
template<typename T1, typename T2>
void showBase(Base<T1, T2> p)
{
    cout << "name: " << p.m_Mame << endl;
    cout << "age: " << p.m_Age << endl;
}

template<typename T1, typename T2>
class Base
{
    // 全局函数类内实现
    friend void printBase(Base<T1, T2> p)
    {
        cout << "name: " << p.m_Mame << endl;
        cout << "age: " << p.m_Age << endl;
    }

    // 全局函数类外实现 声明,
    // 需要加上空模板的参数列表
    // 需要让编译器提前知道这个函数的存在
    // 需要提前让编译器知道Base类存在
    friend void showBase<>(Base<T1, T2> p);

    public:
        Base(T1 name, T2 age);

    private:
        T1 m_Mame;
        T2 m_Age;
        
};

template<typename T1, typename T2>
Base<T1, T2>::Base(T1 name, T2 age)
{
    this->m_Mame = name;
    this->m_Age = age;
}



void test01()
{
    Base<string, int> p("zhangzhan", 19);
    printBase(p);
    showBase(p);
}

int main()
{
    test01();
    return 0;
}