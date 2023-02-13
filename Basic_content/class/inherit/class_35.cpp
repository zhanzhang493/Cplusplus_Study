#include <iostream>
#include <string>
using namespace std;

/* 菱形继承 */
// 两个派生类继承同一个基类, Base -> Son1, Son2
// 又有某个类同时继承两个派生类 Son1, Son2 --> Gson1

// Son1，Son2继承了base的数据，而Gson1使用数据时，就会产生二义性
// Gson1继承自base的数据，有两份，实际上，只需要一份就可以了

class Base
{
public:
    int m_A;

    Base()
    {
        m_A = 100;
    }
};


class Son1: public Base 
{
    public:
        Son1()
        {
            m_A = 200;
        }
    };

class Son2: public Base
{
    public:
        Son2()
        {
            m_A = 300;
        }
};

class Gson1: public Son1, public Son2
{
};

void test01()
{
    Gson1 gs1;
    cout << "Sizeof Gson1: " << sizeof(gs1) << endl;
    cout << "gs1's m_A = " << gs1.Son1::m_A << endl;
    cout << "gs1's m_A = " << gs1.Son2::m_A << endl;
}

int main()
{
    test01();
    return 0;
}