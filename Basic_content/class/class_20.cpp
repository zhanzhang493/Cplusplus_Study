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
// 引用申明：告诉编译器这个类型已经存在了，但此时编译器并不知道需要给该类型的对象分配多少字节内存。
// 定义申明：描述了该类型的细节，编译器由此可以知道需要给该类型的对象分配多大的内存。
// 这个声明，有时称为前向声明(forward declaraton)，在声明之后、定义之前，类Building是一个不完全类型(incompete type)，即已知Building是一个类型，但不知道包含哪些成员。
// 不完全类型(incomplete type)只能以有限方式使用。不能定义该类型的对象。
// 不完全类型只能用于定义指向该类型的指针及引用，或者用于声明（而不是定义）使用该类型作为形参类型或返回类型的函数。

class GoodGay
{
    public:
        GoodGay();

        void visit(); // 访问Building中的属性
    
    private:

        Building * building;
};

class Building
{   
    friend class GoodGay;
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

void GoodGay::visit()
{
    cout << "访问Building." << endl;
    cout << building->m_sitting_room << endl;
    cout << building->m_bed_room << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();
    return 0;
}