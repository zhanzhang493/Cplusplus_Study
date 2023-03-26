#include <iostream>
#include <string>
using namespace std;

/*string类的本质*/
// string是C++风格的字符串，而string本质上是一个类
// char * 是一个指针
// string是一个类，类内封装了char *，管理这个字符串，是一个char*型的容器
// string类内部封装了很多成员方法
// 例如：查找find，拷贝copy，删除delete，替换replace，插入insert
// string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

/*string构造函数*/
// string();  空字符串
// string(const char * s); 使用字符串s初始化
// string(const string & str); 使用一个string对象初始化另一个string对象
// string(int n, char C); 使用n个字符C初始化

void test01()
{
    string s1;    // 默认构造

    const char * str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;
    cout << *(s3.end()-1) << endl;
    
    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;

}

int main()
{
    test01();
    return 0;
}

