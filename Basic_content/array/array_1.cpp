#include <iostream>
using namespace std;

/* 1-dimensional array */
// 数组中的每个元素都是相同数据类型
// 数组存在越界风险，因为不会报错，也能正常使用程序
// 数组index: 0 ~ N-1

int main()
{
    int grade[10] = {90, 99, 100}; // array index: 0 ~ 9, 未全部初始化的，会用0进行初始化

    cout << grade[0] << "," << grade[9] << endl; 
    cout << grade[10] << endl; // 数组越界了grade[10]，但不会报错，因此存在巨大风险

    for (int i = 0; i < 10; i++){
        cout << grade[i] << endl;
    }
}