#include <iostream>
using namespace std;

void print_array(int *, int);

void bubble_sort(int *, int);

int main()
{
    int digit[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(digit, 9);
}

void print_array(int grade[], int num)
{
    for (int i = 0; i < num; i++){
        if (i != num-1){
            cout << grade[i] << ", ";
        }else{
            cout << grade[i] << endl;
        }
    }
}

void bubble_sort(int grade[], int num)
{
    cout << "排序前：";
    print_array(grade, num);

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if (grade[j] > grade[j+1]){
                int temp = grade[j];
                grade[j] = grade[j+1];
                grade[j+1] = temp;
            }
        }
    cout << "第" << i+1 << "轮冒泡排序的结果: ";
    print_array(grade, num);
    }
}