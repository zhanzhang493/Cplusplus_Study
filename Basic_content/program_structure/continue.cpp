#include<iostream>
using namespace std;

/* continue: 在循环语句中，跳过当前循环，继续下一次循环 */

int main()
{
    for (int i = 0; i < 10; i++){
        if ((i%2) == 0)
        {
            continue;
        }
        cout << i << endl;
    }
}