#include <iostream>
#include <string>
using namespace std;

/* 访问权限 */
// 类的访问权限有三种
// public:    成员，类内可以访问，类外可以访问
// protected: 成员，类内可以访问，类外不可以访问，派生类（即子类）可以访问。
// private:   成员，类内可以访问，类外不可以访问，派生类（即子类）不可以访问。

class Person
{
    public:
        string m_Name;

    protected:
        string m_Car;

    private:
        int m_Password;

    public:
    void set_info(string name, string car, int password)
    {
        m_Name = name;
        m_Car = car;
        m_Password = password;
    }

    void show_info()
    {
        cout << "Name: " << m_Name << endl;
        cout << "Car: " << m_Car << endl;
        cout << "Password: " << m_Password << endl;
    }

};

int main()
{
    Person p1;
    p1.m_Name = "Matrix";
    p1.set_info("ZHANG ZHAN", "BMW", 941018);
    p1.show_info();
    // p1.m_Car = "BMW"; error: 不可访问
    // p1.m_Password = 123456; error: 不可访问
    


    return 0;
}