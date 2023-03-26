#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* vector容量和大小 */
// 对vector容量和大小的操作
// empty() 是否为空
// capacity() 容器的容量
// size() 返回容器中元素的个数
// resize(int num) 重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除
// resize(int num, elem) 重新指定容器的长度为num，若容器变长，则以elem填充新位置；若容器变短，则末尾超出容器长度的元素被删除

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
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    

    if (v1.empty()){
        cout << "v1为空" << endl;
    }else{
        cout << "v1不为空" << endl;
    }
    printVector(v1);

    v1.resize(15);
    printVector(v1); // 用0填充

    v1.resize(17, 199);
    printVector(v1); //用199填充

    v1.resize(5);
    printVector(v1); // 删除多余的
}

int main()
{
    test01();
    return 0;
}