#include <iostream>
#include <string>
using namespace std;

/*string赋值操作*/
// string& operator=(const char * s);
// string& operator=(const string &s);
// string& operator=(char c);
// string& assign(const char * s);
// string& assign(const char * s, int n); // 把字符串s的前n个字符赋给当前的字符串
// string& assign(const string &s);
// string& assign(int n, char c);

void test01()
{
    string s1;
    s1 = "hello world";
    cout << "s1 = " << s1 << endl;

    string s2;
    s2 = s1;
    cout << "s2 = " << s2 << endl;

    string s3;
    s3 = 'a';
    cout << "s3 = " << s3 << endl;

    string s4;
    s4.assign("hello world");
    cout << "s4 = " << s4 << endl;

    string s5;
    s5.assign("hello world", 5);
    cout << "s5 = " << s5 << endl;

    string s6;
    s6.assign(s5);
    cout << "s6 = " << s6 << endl;

    string s7;
    s7.assign(10, 'h');
    cout << "s7 = " << s7 << endl;
}

int main()
{
    test01();
    return 0;
}
