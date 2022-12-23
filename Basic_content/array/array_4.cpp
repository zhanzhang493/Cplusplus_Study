#include <iostream>
using namespace std;

/* 2-dimensional array */
// 数组名可以统计整个数组在内存中的长度
// 数组名可以获取数组在内存中的首地址

void print_2array(int **, int, int);

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print_2array((int **)arr, 2, 3);

    cout << "int类型占内存大小: " << sizeof(int) << endl;
    cout << "arr数组占内存大小: " << sizeof(arr) << endl;
    cout << "arr中元素的个数: " << sizeof(arr) / sizeof(int) << endl;

    cout << "arr数组第一行占内存大小: " << sizeof(arr[0]) << endl;
    cout << "arr中第一行元素的个数: " << sizeof(arr[0]) / sizeof(int) << endl;

    cout << "arr的地址: " << arr << endl;
    cout << "arr的首地址: " << arr << endl;
    cout << "arr的第一行的首地址: " << arr[0] << endl;
    cout << "arr的第一行第一个元素的首地址: " << &arr[0][0] << endl;
    cout << "arr的第一行第二个元素的首地址: " << *(arr + 0)+1 << endl;

    cout << "arr的第二行的首地址: " << arr+1 << endl;
    cout << "arr的第二行的首地址: " << arr[1] << endl;

    cout << "arr的第二行第二个元素的首地址: " << &arr[1][1] << endl;
    cout << "arr的第二行第二个元素的首地址: " << *(arr + 1)+1 << endl;

}

void print_2array(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (j == col-1){
                cout << *((int*)arr + i*col + j) << endl;
            }else{
                cout << *((int*)arr + i*col + j)<< ", ";
            }
        }
    }
}