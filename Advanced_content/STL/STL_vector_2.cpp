#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

// vector中存放自定义数据类型

class Person
{
    public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    // 创建容器，数组
    vector<Person> v;

    Person p1("a1", 10);
    Person p2("a2", 20);
    Person p3("a3", 30);
    Person p4("a4", 40);
    Person p5("a5", 50);

    // 向后插入数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 方法2
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*it).m_Name << ", " << "age: " << (*it).m_Age << endl;
        cout << "name: " << it->m_Name << ", " << "age: " << it->m_Age << endl;
    }
}

// 存放自定义数据类型 的 指针
void test02()
{
    vector<Person *> v;

    Person p1("a1", 10);
    Person p2("a2", 20);
    Person p3("a3", 30);
    Person p4("a4", 40);
    Person p5("a5", 50);

    // 向后插入数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 方法2
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Address: " << &(*it) << ", ";
        cout << "name: " << (*it)->m_Name << ", " << "age: " << (*it)->m_Age << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}