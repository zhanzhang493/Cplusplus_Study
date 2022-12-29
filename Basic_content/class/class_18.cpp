#include <iostream>
#include <string>
using namespace std;

/* const修饰成员函数 */
// 成员函数后加const后，称为常函数
// 常函数内不可以修改成员属性
// 成员属性声明时加上关键字mutable后，在常函数中依然可以修改

/* 常对象 */
// 声明对象前加const，称该对象为常对象
// 常对象只能调用常函数


class Person
{
    public:
        // this 指针的本质是指针常量 Person * const this，指针的指向是不可以修改的，参考pointer_4.cpp
        Person()
        {
            m_A = 20;
            m_B = 80;
        }

        void show_person() const // 相当于 const Person * const this, 即常量指针，即指针指向的值也不可以修改
        // void show_person()
        {
            // m_A = 100; = this->m_A = 100; error
            m_B += 100;
            cout << "This is person." << endl;
            cout << "m_A: " << m_A << endl;
            cout << "m_B: " << m_B << endl;
            // this = NULL; error
        }

        void show_info()
        {}

        int m_A;
        mutable int m_B;  // 可以用关键字mutable

};

void test01()
{
    Person p1;
    p1.show_person();
}

void test02()
{
    const Person p; // 在对象前加const， 变为常对象
    // p.m_A = 100; error, 不可修改
    p.m_B -= 1;
    cout << "m_A: " << p.m_A << endl;
    cout << "m_B: " << p.m_B << endl;

    p.show_person();   // 常对象只能调用常函数
    // p.show_info(); error 

}
int main()
{
    test01();
    test02();
    return 0;
}