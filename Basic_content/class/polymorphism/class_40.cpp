#include <iostream>
#include <string>
using namespace std;

/* 纯虚函数和抽象类 */
// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 语法：virtual 返回值类型 函数名 (参数列表) = 0
// 当类中有了纯虚函数，这个类也称为抽象类

// 抽象类的特定
// 无法实现实例化对象
// 子类必须重写抽象类中的纯虚函数，否则也属于抽象类


class Base
{
    public:
    virtual void func() = 0;

};

class Son: public Base
{
    virtual void func()
    {
        cout << "Son func." << endl;
    }
};

class Father: public Base
{
    virtual void func()
    {
        cout << "Father func." << endl;
    }
};


void func(Base &person)
{
    person.func();
}

void test01()
{
    Son s;
    Father f;
    func(s);
    func(f);
}

int main()
{
    test01();
    return 0;
}