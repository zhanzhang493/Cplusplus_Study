#include <iostream>
#include <string>
using namespace std;

/* 类模板中成员函数的创建时机*/
// 普通类的成员函数一开始就可以创建
// 类模板中的成员函数在调用时才创建


class Person1
{
    public:
        void showPerson1()
        {
            cout << "Person1 show" << endl;
        }
};

class Person2
{
    public:
        void showPerson2()
        {
            cout << "Person2 show" << endl;
        }
};

template<class T>
class MyClass
{
    public:
        T obj;

        // 类模板中的成员函数
        void func1()
        {
            obj.showPerson1();
        }

        void func2()
        {
            obj.showPerson2();  // 如果没有调用，编译是不会出错的，成员函数在调用时才会创建
        }
};

void test01()
{
    MyClass<Person1> m;
    m.func1();
    // m.func2();  // 调用时才会创建
}


int main()
{
    test01();
    return 0;
}