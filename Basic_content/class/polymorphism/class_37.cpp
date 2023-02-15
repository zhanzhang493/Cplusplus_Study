#include <iostream>
#include <string>
using namespace std;

/* 多态 */
// 多态分为两类
// 静态多态：函数重载和运算符重载属于静态多态，复用函数名
// 动态多态：派生类和虚函数实现运行时多态

// 静态多态和动态多态的区别
// 静态多态的函数地址早绑定 - 编译阶段确定函数地址
// 动态多态的函数地址晚绑定 - 运行阶段确定函数地址 - virtual

// 动态多态的条件：
// 有继承关系
// 子类需要重写，virtual可写可不写
// 重写： 函数返回值类型， 函数名， 参数列表， 完全相同

// 动态多态的使用
// 父类的指针或引用，指向子类对象

class Animal
{
    public:
        // void speak() - 静态多态 - doSpeak 绑定了animal的speak函数
        virtual void speak() // 动态多态
        {
            cout << "Animal speaking." << endl;
        }
};

class Cat: public Animal
{
    public:
        void speak()
        {
            cout << "Cat speaking." << endl;
        }
};

class Dog : public Animal
{
    public:
        void speak()
        {
            cout << "Dog speaking." << endl;
        }
};

void doSpeak(Animal & animal) // Animal & animal = cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main()
{
    test01();
    return 0;
}