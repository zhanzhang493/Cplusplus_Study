#include <iostream>
#include <string>
using namespace std;

/* 空指针访问成员函数 */
// c++中空指针也是可以调用成员函数，但是要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性

class Person
{
    public:
        void show_class_name()
        {
            cout << "This is person class." << endl;
        }

        void show_person_age()
        {
            if (this == NULL) // 避免空指针调用报错，提高健壮性
            {
                return;
            }
            cout << "Age: " << m_age << endl; // 默认 this->m_age
        }

        int m_age;
};

void test01()
{
    Person * p = NULL;
    p->show_class_name();
    p->show_person_age(); // 报错原因是因为传入的指针是NULL

    Person p1;  // 默认初始化构造函数
    Person * ptr = &p1; // 不再是空指针
    cout << ptr->m_age << endl;
    ptr->show_class_name();
    ptr->show_person_age(); // 报错原因是因为传入的指针是NULL
}

int main()
{   
    test01();
    return 0;
}