#include <iostream>
using namespace std;

/* 2-dimensional array */
// 数据类型 数组名[][列数] = {{}, {}}

void print_2array(int **, int, int);

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print_2array((int **)arr, 2, 3);

    // arr = {1, 3, 4, 5, 6, 7}; // 错误
    int arr2[2][3] = {1, 3, 4, 5, 6, 7}; 
    print_2array((int **)arr2, 2, 3);

    int arr3[][3] = {1, 0, 4, 5, 6}; 
    print_2array((int **)arr3, 2, 3);
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