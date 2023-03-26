#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* 构造函数 */
// vector<T> v;  默认构造函数
// vector<T> v(v1.begin(), v1.end());  将v.begin()和v.end()区间中的元素拷贝给本身
// vector<T> v(n, elem);   构造函数将n个elem拷贝给本身
// vector<T> v(const vector &vec);  拷贝构造函数  

void printVector(vector<int> & v)
{
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);


    vector<int>v2(v1.begin(), v1.end()-1);
    printVector(v2);

    vector<int>v3(10, 100);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}