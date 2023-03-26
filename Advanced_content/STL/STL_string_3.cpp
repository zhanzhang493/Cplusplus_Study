#include <iostream>
#include <string>
using namespace std;

/*string字符串的拼接*/
// string& operator+=(const char * s);
// string& operator+=(const string &s);
// string& operator+=(const char c);
// string& append(const char * s);
// string& append(const char * s, int n); // 把字符串s的前n个字符拼接到当前的字符串
// string& append(const string &s);
// string& append(const string &s, int pos, int n); 截取s的起始位置pos，截取长度n

void test01()
{
    string s1 = "hello ";
    s1 += "C++ ";
    cout << "s1 = " << s1 << endl;

    s1 += ':';
    cout << "s1 = " << s1 << endl;

    string s2 = "LOL";
    s1 += s2;
    cout << "s1 = " << s1 << endl;

    s1.append("fake");
    cout << "s1 = " << s1 << endl;

    s1.append("gameabcd", 4);
    cout << "s1 = " << s1 << endl;

    s1.append(s2);
    cout << "s1 = " << s1 << endl;

    s1.append(s1, 3, 4);
    cout << "s1 = " << s1 << endl;
}

int main()
{
    test01();
    return 0;
}