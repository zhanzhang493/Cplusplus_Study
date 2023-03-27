#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* vector预留容器 */
// 减少vector在动态扩展容量时的扩展次数
// reserve(int len), 容器预留len个元素，预留位置不初始化，元素不可访问

template<typename T>
void printVector(vector<T> & v)
{
    // for (typename vector<T>::iterator it=v.begin(); it != v.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;
}

void test01()
{
    cout << "预留前：-----------------------" << endl;
    vector<int> v1;
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++){
        v1.push_back(i);
        if (p != &v1[0]){
            p = &v1[0];   // 动态扩容
            num ++;
        }
    }
    printVector(v1);
    cout << "动态扩容了" << num << "次" << endl;

    cout << "预留后：-----------------------" << endl;
    vector<int> v2;
    v2.reserve(100000);
    
    num = 0;
    p = NULL;

    for (int i = 0; i < 100000; i++){
        v2.push_back(i);
        if (p != &v2[0]){
            p = &v2[0];   // 动态扩容
            num ++;
        }
    }
    printVector(v2);
    cout << "动态扩容了" << num << "次" << endl;
}

int main()
{
    test01();
    return 0;
}