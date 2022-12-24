#include <iostream>
using namespace std;

/* 指针和数组 */
// 数组名可以看作指针，但不完全等同于指针
// 用指针可以操作数组

int main()
{
    /* 1 dimensional array and ptr */
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "arr的第一个元素: " << arr[0] << endl;

    int * p = arr;

    cout << "利用指针访问第一个元素: " << *p << endl;

    p++;

    cout << "利用指针访问第二个元素: " << *p << endl;


    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "sizeof(p): " << sizeof(p) << endl;

    /* 2 dimensional array and ptr */
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "arr2的第一行的第一个元素: " << arr2[0][0] << endl;

    cout << "利用arr2指针访问arr2的第二行的第三个元素: " << *(*(arr2+1)+2) << endl;

    int * q = *arr2;
    cout << "利用指针q访问arr2的第二行的第三个元素: " << *(q + 3 * 1 + 2) << endl;
}