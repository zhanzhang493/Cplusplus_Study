#include <iostream>
#include <string>
using namespace std;

/* c++对象模型 */
// 成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象

class Person
{
    private:
        /* data */
    public:
        Person(/* args */);
        ~Person();

        int m_A;     // 非静态成员变量，属于类的对象上
        static int m_B;   // 静态成员变量，不属于类的对象上

        void func1() {}     // 非静态成员变量，不属于类的对象上
        static void func2() {}  // 静态成员函数，不属于类的对象上
};

int Person::m_B = 1;

Person::Person(/* args */)
{
    m_A = 0;
    cout << "Person的无参(默认)构造函数调用." << endl;
}

Person::~Person()
{
    cout << "Phone的析构函数调用." << endl;
}


void test01()
{
    Person p;
    // 空对象占用内存空间为：1
    // c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "size of Person: " << sizeof(p) << endl;
}

int main()
{
    test01();
    return 0;
}