#include <iostream>
using namespace std;

/* 类和对象 */
// c++面向对象的三大特性：封装、继承、多态
// c++认为万事万物皆为对象，对象上有其属性和行为

/* 封装 */
// 封装的意义：
// 将属性和行为作为一个整体，表现生活中的事物
// 将属性和行为加以权限控制
// 语法： class 类名 {访问权限： 属性 / 行为};

// example: 设计一个圆类，求圆周长
// 周长公式： 2 * /pi * r

const double PI = 3.1415926;

class Circle
{
    /* 访问权限 */
    public: // 公共权限
        /* 属性 */ 
        int m_r; // 半径

        /* 行为 */
        // 获取圆的周长
        double calculateZC()
        {
            return 2 * PI * m_r;
        }
};

int main()
{
    // 通过圆类，创建具体的圆（对象）--> 实例化
    Circle c1;
    // 给圆对象的属性进行赋值
    c1.m_r = 2;
    cout << "圆的周长: " << c1.calculateZC() << endl;
    return 0;
}