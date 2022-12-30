#include <iostream>
#include <string>
using namespace std;

/* 友元 */
// 关键字 friend
// 有些私有属性，想让类外特殊的一些函数或者类进行访问，就需要友元的技术
// 友元的目的是让一个函数或者类访问另一个类中的私有成员

/* 友元的三种实现 */
// 全局函数做友元
// 类做友元
// 成员函数做友元

class Building
{   
    friend void good_friend(Building & b); // 友元声明
    public:
        Building(): m_sitting_room("客厅"), m_bed_room("卧室") {}

    public:
        string m_sitting_room;
        
    private:
        string m_bed_room;
};

// 全局函数
void normal_friend(Building & b)
{
    cout << "访问Building." << endl;
    cout << "访问" << b.m_sitting_room  << endl;
}

void good_friend(Building & b)
{
    cout << "朋友访问Building." << endl;
    cout << "朋友访问" << b.m_sitting_room  << endl;
    cout << "朋友访问" << b.m_bed_room  << endl;
}

void test01()
{
    Building b;
    normal_friend(b);
    good_friend(b);
}

int main()
{
    test01();
    return 0;
}