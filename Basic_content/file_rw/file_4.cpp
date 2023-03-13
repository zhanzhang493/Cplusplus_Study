#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 以二进制方式读文件 */
// 打开方式 ios::binary
// istream& read(char * buffer, int len)

class Person
{
    public:
        char m_name[64];
        int m_Age;
};

void test01()
{
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(p));

    cout << "姓名：" << p.m_name << endl;
    cout << "年龄：" << p.m_Age << endl;

    ifs.close();
}

int main()
{
    test01();
    return 0;
}