#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/* 构造赋值 */
// vector & operator=(const vector &vec);
// assign(beg, end);
// assign(n, elem);

template<typename T>
void printVector(vector<T> & v)
{
    for (typename vector<T>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<double> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector<double>(v1);

    vector<double> v2;
    v2 = v1;
    printVector(v2);

    vector<double> v3;
    v3.assign(v1.begin()+2, v1.end()-3);
    printVector(v3);
}

int main()
{
    test01();
    return 0;
}