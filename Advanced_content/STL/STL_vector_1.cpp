#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

// 容器：vector
// 算法 for_each
// 迭代器 vector<int>::iterator

void myPrint(int val)
{
    cout << val << endl;
}


void test01()
{
    // 创建容器，数组
    vector<int> v;

    // 向后插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 方法1：通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end(); // 起始迭代器，指向容器中最后一个元素的下一个元素位置

    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin ++;
    }

    // 方法2
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 方法3：利用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);

}

int main()
{
    test01();
    return 0;
}