#include <iostream>
using namespace std;

/* 函数模板的局限性 */
// 模板的通用性不是万能的
// 利用具体化的模板，可以解决自定义类型的通用化
// 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板

class Person
{
    public:
        string m_name;
        int m_age;

        Person(string name, int age): m_name(name), m_age(age) {}


};

template<typename T> // 不能处理部分自定义数据类型，数组类型
bool f(T &a, T &b)
{
   return a > b;
}

bool f(Person &a, Person &b) // 提供具体化函数
{
    return a.m_age > b.m_age;
}

void test01()
{
    int a = 4;
    int b = 5;
    cout << f(a, b) << endl;;

    Person p1("zhangzhan", 20);
    Person p2(" Fay", 18);
    cout << f(p1, p2) << endl;
}

int main()
{
    test01();
    return 0;
}