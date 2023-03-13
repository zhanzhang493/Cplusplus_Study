#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 以二进制方式写文件 */
// 打开方式 ios::binary
// ostream& write(const char * buffer, int len)

class Person
{
    public:
        char m_name[64];
        int m_Age;
};

void test01()
{
    ofstream ofs;
    ofs.open("person.txt", ios::out | ios::binary);

    // 下面的方式和上两句等效
    // ofstream ofs("person.txt", ios::out | ios::binary);

    Person p = {"zhangzhan", 18};
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

int main()
{
    test01();
    return 0;
}