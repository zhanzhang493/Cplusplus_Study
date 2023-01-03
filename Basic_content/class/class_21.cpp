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

class Building;

class GoodGay
{
    public:
        GoodGay();

        void visit1();  // 访问Building中的属性, all
        void visit2();  // 访问Building中的属性，only public
    
    private:

        Building * building;
};

class Building
{   
    friend void GoodGay::visit1();
    public:
        Building(): m_sitting_room("客厅"), m_bed_room("卧室") {}

    public:
        string m_sitting_room;
        
    private:
        string m_bed_room;
};

GoodGay::GoodGay() // 为什么把成员函数写在类内会报错：非法使用class Building
{
    building = new Building;
}

void GoodGay::visit1()
{
    cout << "visit1访问Building." << endl;
    cout << building->m_sitting_room << endl;
    cout << building->m_bed_room << endl;
}

void GoodGay::visit2()
{
    cout << "visit2访问Building." << endl;
    cout << building->m_sitting_room << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit1();
    gg.visit2();
}

int main()
{
    test01();
    return 0;
}