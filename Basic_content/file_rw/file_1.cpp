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

/* 写文件 */
// 包含头文件
// #include <fstream>
// 创建流对象
// ofstream ofs;
// 打开文件
// ofs.open("文件路径"， 打开放式)；
// 写入数据
// ofs << "写入的数据"；
// 关闭文件
// ofs.close();

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
    ofstream ofs;

    ofs.open("test.txt", ios::out | ios::binary);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++){
        ofs << a[i] << endl;
    }

    ofs.close();
}
int main()
{
    test01();
    return 0;
}