#include <iostream>
#include <string>
using namespace std;

/* 继承中的构造和析构顺序 */
// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 先构造父类，再构造子类，析构的顺序与构造的顺序相反

class Base
{
    public:
        Base()
        {
            cout << "Base构造函数." << endl;
        }

        ~Base()
        {
            cout << "Base的析构函数." << endl;
        }
};

///////////////////////////////////////////////////////////
/* public */
class Son1: public Base
{
    public:
        Son1()
        {
            cout << "Son1构造函数." << endl;
        }

        ~Son1()
        {
            cout << "Son1的析构函数." << endl;
        }
};

void test01()
{   
    // Base b;

    Son1 s1;
}

int main()
{
    test01();
    return 0;
}