#include <iostream>
#include <string>
using namespace std;

/* 虚析构和纯虚析构 */
// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决办法：将父类中的析构函数改为虚析构和纯虚析构
// 共性：
// 可以解决父类指针释放子类对象的问题
// 都需要有具体的函数实现
// 区别：
// 如果是纯虚析构，该类属于抽象类，无法实例化对象
// 语法
// virtual ~类名

class Animal
{
    public:
        virtual void speak() = 0;
        Animal()
        {
            cout << "Animal构造函数调用" << endl;
        }

//         virtual ~Animal()   // 利用虚析构可以解决 父类指针释放子类对象时不干净的问题
//         {
//             cout << "Animal虚析构函数调用" << endl;
//         }
        virtual ~Animal() = 0;  // 特点：需要声明，也需要实现
};

Animal::~Animal()   // 纯虚析构必须要有具体的实现
{
    cout << "Animal纯虚析构函数调用" << endl;
}
        

class Cat: public Animal
{
    public:
        Cat(string name)
        {
            cout << "Cat构造函数调用" << endl;
            m_Name = new string(name);
        }

        virtual void speak()
        {
            cout << *m_Name << " Cat speaking" << endl;
        }

        string * m_Name;

        ~Cat()
        {
            if (m_Name != NULL)
            {
                cout << "Cat析构函数调用" << endl;
                delete m_Name;
                m_Name = NULL;
            }
        }
};

void func(Animal &a)
{
    a.speak();
}

void test01()
{
    Animal * animal = new Cat("Henry");
    animal->speak();
    // 父类指针在析构时候，不会调用子类中析构函数，导致子类中如果有堆区属性，会出现内存泄漏
    delete animal;

    Cat c("Tom");
    func(c); 
}

int main()
{
    test01();
    return 0;
}