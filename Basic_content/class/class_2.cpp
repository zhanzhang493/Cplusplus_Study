#include <iostream>
#include <string>
using namespace std;

/* 类和对象 */
// c++面向对象的三大特性：封装、继承、多态
// c++认为万事万物皆为对象，对象上有其属性和行为

/* 封装 */
// 封装的意义：
// 将属性和行为作为一个整体，表现生活中的事物
// 将属性和行为加以权限控制
// 语法： class 类名 {访问权限： 属性 / 行为};

// example: 设计一个学生类
// 可以给姓名和学号赋值，可以显示学生的姓名和学号

class Student
{
    /* 访问权限 */
    public: // 公共权限
    // 类中的属性和行为，我们统一称为成员
    // 属性：也称为成员属性、成员变量
    // 行为：也称为成员函数、成员方法

        /* 属性 */ 
        string m_name; // 姓名
        int m_ID; // ID

        /* 行为 */
        // 显示姓名和学号
        void showStudent()
        {
            cout << "name: " << m_name << endl;
            cout << "ID: " << m_ID << endl;
        }

        // 给姓名赋值
        void set_name(string name)
        {
            m_name = name; 
        }

        // 给学号赋值
        void set_ID(int id)
        {
            m_ID = id;
        }
};

int main()
{
    // 实例化
    Student s1;
    Student s2;
    // 给学生对象的属性进行赋值
    s1.set_name("ZHAN ZHANG");
    s1.set_ID(1);

    s2.m_name = "Fay Wang";
    s2.m_ID = 2;

    // 显示学生信息
    s1.showStudent();
    s2.showStudent();

    return 0;
}