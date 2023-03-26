#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* vector插入、删除操作 */
// push_back()
// pop_back()
// insert(const_interator pos, ele)
// insert(const_interator pos, int count, ele)
// erase(const_iterator pos)
// erase(const_iterator start, const_iterator end)
// clear()



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

    v1.push_back(110);
    printVector(v1);

    v1.pop_back();
    printVector(v1);

    v1.insert(v1.begin(), 32);
    printVector(v1);

    v1.insert(v1.begin(), 2, 32);
    printVector(v1);

    v1.erase(v1.end()-2);
    printVector(v1);

    v1.erase(v1.end()-3, v1.end()-1);
    printVector(v1);

    v1.clear();
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}