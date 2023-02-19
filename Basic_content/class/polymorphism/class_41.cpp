#include <iostream>
#include <string>
using namespace std;

/* 案例 */
// 制作饮料

class AbstractDrinking
{
    public:
        virtual void boil() = 0;
        virtual void brew() = 0;
        virtual void pourincup() = 0;
        virtual void putsmthing() = 0;

        void makeDrink()
        {
            cout << "制作饮料" << endl;
            boil();
            brew();
            pourincup();
            putsmthing();
        }
};

class Coffee: public AbstractDrinking
{
    public:
        virtual void boil()
        {
            cout << "煮水" << endl;
        }

        virtual void brew()
        {
            cout << "冲泡咖啡" << endl;
        }

        virtual void pourincup()
        {
            cout << "倒入杯中" << endl;
        }

        virtual void putsmthing()
        {
            cout << "加糖" << endl;
        }
};

class Tea: public AbstractDrinking
{
    public:
        virtual void boil()
        {
            cout << "煮水" << endl;
        }

        virtual void brew()
        {
            cout << "冲泡茶叶" << endl;
        }

        virtual void pourincup()
        {
            cout << "倒入杯中" << endl;
        }

        virtual void putsmthing()
        {
            cout << "加菊花" << endl;
        }
};




void func(AbstractDrinking &drinking)
{
    drinking.makeDrink();
}

void doDrink(AbstractDrinking *drinking)
{
    drinking->makeDrink();
    delete drinking;    // sometimes bug. 除非drink指向堆区
}

void test01()
{
    Coffee c;
    Coffee * c_ptr = &c;
    Tea t;
    func(c);
    func(t);
    doDrink(new Coffee);
    // doDrink(c_ptr);  // bug
}

int main()
{
    test01();
    return 0;
}