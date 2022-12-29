#include <iostream>
#include <string>
using namespace std;

/* c++的this指针 */
// 每一个非静态成员函数只会生成一份实例，也就是说多个同类型的对象会共有一块代码
// 那么问题是，这一块代码如何区分哪个对象调用自己的呢
// c++通过提供特殊的对象指针，this指针，来解决上述问题
// this指针指向被调用的成员函数所属的对象
// this指针是隐含在每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可
// 用途
// 当形参和成员变量同名时，可以用this指针来区分
// 在类的非静态成员函数中返回对象本身，可以使用 return * this


class Person
{
    public:
        Person(int age)
        {
            // age = age; error
            this->age = age;   // 当形参和成员变量同名时，可以用this指针来区分
        }
        int age;

        // Person Person_add_age(Person & p) // 返回的是值，创建的是新的对象
        Person & Person_add_age(Person & p) // 返回的是本体，必须加上引用&，参考reference/reference_function_2.cpp
        {   
            cout << "Person add age." << endl;
            this->age += p.age;
            cout << "P->age: " << this->age << endl;
            return *this;
        }

};

void test01()
{
    Person p1(18);
    cout << "P1的年龄为: " << p1.age << endl;
}

void test02()
{
    Person p1(18);
    Person p2(20);
    p2.Person_add_age(p1).Person_add_age(p1).Person_add_age(p1);    // 链式编程思想
    cout << "P2的年龄为: " << p2.age << endl;
}


int main()
{
    test01();
    test02();
    return 0;
}