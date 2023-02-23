#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 文件操作 */
// 通过文件可以将数据持久化
// 文件类型分为两种：
// 文本文件，文本的ASCII码形式进行存储
// 二进制文件，二进制形式

// 操作文件的三大类
// ofstream: write
// ifstream: read
// fstream: read and write

/* 读文件 */
// 包含头文件
// #include <fstream>
// 创建流对象
// ifstream ifs;
// 打开文件, 判断是否打开成功
// ifs.open("文件路径"， 打开放式)；
// 读入数据
// ofs << "写入的数据"；
// 关闭文件
// ifs.close();

// 打开放式
// ios::in, 为读文件而打开文件
// ios::out, 为写文件而打开文件
// ios::ate, 初始位置: 文件末尾
// ios::app, 追加方式写文件
// ios::trunc, 如果文件存在，先删除，再创建
// ios::binary, 二进制放式

// 用二进制方式写文件，ios::binary | ios::out

void test01()
{
    ifstream ifs;

    ifs.open("test.txt", ios::in);

    if (!ifs.is_open()){
        cout << "wrong open file." << endl;
        return;
    }
    
    // method 1
    char buf1[1024] = {0};
    while (ifs >> buf1){
        cout << buf1 << endl;
    }

    ifs.close();
}

void test02()
{
    ifstream ifs;

    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "wrong open file." << endl;
        return;
    }

    // method 2
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    }

    ifs.close();
}

void test03()
{
    ifstream ifs;

    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "wrong open file." << endl;
        return;
    }

    // method 3
    string a;
    while (getline(ifs, a))
    {
        cout << a << endl;
    }

    ifs.close();
}

void test04()
{
    ifstream ifs;

    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "wrong open file." << endl;
        return;
    }

    // method 4
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    ifs.close();
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}