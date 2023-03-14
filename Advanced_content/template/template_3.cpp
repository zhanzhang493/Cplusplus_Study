#include <iostream>
using namespace std;

// 案例，实现通用数组排序的函数
// 从大到小排序
// 测试: int, double

template<class T> // typename = class, here
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void printArray(T *arr, int len)
{
    for (int i = 0; i < len; i++){
        cout << *(arr+i) << ", ";
    }
    cout << endl;
}

template<typename T>
void mySort(T *arr, int len)
{
    for (int i = 0; i < len; i++){
        int max = i; // 认定最大值的下标
        for (int j = i + 1; j < len; j++){
            if (*(arr+max) < *(arr+j)){
                max = j; // 更新最大值下标
            }
        }
        if (max != i){
            myswap(*(arr + max), *(arr+i));
        }
    }
}

void test01()
{
    int intArr[5] = {3, 5, 2, 1, 0}; 
    mySort(intArr, 5);
    printArray(intArr, 5);

    float floatArr[6] = {3.3, 4.4, 2.2, 1.1, 6.6, -0.2};
    mySort(floatArr, 6);
    printArray(floatArr, 6);
}

int main()
{
    test01();
    return 0;
}