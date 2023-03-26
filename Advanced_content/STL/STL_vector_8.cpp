#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* vector数据存取 */
// at(int idx)
// operator[]
// front()
// back()



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
    printVector(v1);

    v1[1] = 20;
    printVector(v1);

    v1.at(3) = 100;
    printVector(v1);

    cout << v1.front() << " " << v1.back() << endl;
}

int main()
{
    test01();
    return 0;
}