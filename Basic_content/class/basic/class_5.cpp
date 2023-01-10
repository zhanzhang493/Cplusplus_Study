#include <iostream>
#include <string>
using namespace std;

/* 访问权限 */
// 类的访问权限有三种
// public:    成员，类内可以访问，类外可以访问
// protected: 成员，类内可以访问，类外不可以访问，派生类（即子类）可以访问。
// private:   成员，类内可以访问，类外不可以访问，派生类（即子类）不可以访问。

/* 成员属性私有化 */
// 优点：可以自己控制读写权限
// 优点：对于写权限，我们可以检测数据的有效性

class Person
{
    public:

    protected:

    private:
        string m_Name;  // 可读可写
        int m_Age;  // 可读可写
        string m_Lover; // 只写

    

    public:
    Person()
    {
        m_Name = "ZHAN";
        m_Age = 18;
        m_Lover = "Fay";
    }

    void set_info(string name)
    {
        m_Name = name;

    }

    void set_name(string name)
    {
        m_Name = name;
    }

    string get_name()
    {
        return m_Name;
    }

    void set_age(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "Error." << endl;
            m_Age = 0;
            return;
        }
        m_Age = age;
        return;
    }

    int get_age()
    {
        return m_Age;
    }

    void set_lover(string lover)
    {
        m_Lover = lover;
    }

    void show_info()
    {
        cout << "Name: " << m_Name << endl; // 私有属性，成员函数可以直接访问
        cout << "Age: " << m_Age << endl;
        // cout << "Lover: " << m_Lover << endl;
    }



};

int main()
{
    Person p1;

    p1.set_name("ZHAN");
    p1.set_age(29);

    cout << "Name: " << p1.get_name() << endl;
    cout << "Age: " << p1.get_age() << endl;

    p1.set_lover("Fay Wang");
    p1.show_info();

    return 0;
}