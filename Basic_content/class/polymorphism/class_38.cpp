#include <iostream>
#include <string>
using namespace std;

/* 多态的底层原理 */
// virtual函数：vfptr- virtual function pointer -> vftable表，表内记录了虚函数的地址
// 当子类重写父类虚函数，子类中的虚函数表，内部会替换成子类的虚函数地址
// 当父类的指针或引用指向子类对象时，会发生多态



class Animal
{
public:
    int m_0;
    // void speak() // 静态多态 - doSpeak 绑定了animal的speak函数
    virtual void speak() // 动态多态
    {
        cout << "Animal speaking." << endl;
    }
};

class Cat : public Animal
{
public:
    int m_A;
    void speak()
    {
        cout << "Cat speaking." << endl;
    }
};

class Dog : public Animal
{
public:
    double m_B;
    void speak()
    {
        cout << "Dog speaking." << endl;
    }
};

void doSpeak(Animal &animal) // Animal & animal = cat
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

void test02()
{
    cout << "sizeof Animal: " << sizeof(Animal) << endl;
    cout << "sizeof Cat: " << sizeof(Cat) << endl;
    cout << "sizeof Dog: " << sizeof(Dog) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}