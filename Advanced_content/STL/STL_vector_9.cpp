#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* vector互换容器 */
// 两个容器内元素进行互换
// v1.swap(v2)
// swap可以收缩内存空间


template<typename T>
void printVector(vector<T> & v)
{
    for (typename vector<T>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;
}

void test01()
{
    cout << "交换前：" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 0; i < 5; i++){
        v2.push_back(i*2);
    }
    printVector(v2);

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    cout << "利用swap()收缩内存：" << endl;
    v2.resize(2);
    printVector(v2);

    vector<int>(v2).swap(v2);  // 匿名对象v, 用v2初始化v，然后和v2进行交换，当前行之行完毕之后，v被回收
    printVector(v2);
}

int main()
{
    test01();
    return 0;
}