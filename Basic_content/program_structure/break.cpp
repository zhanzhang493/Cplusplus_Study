#include<iostream>
using namespace std;

/* break: 在循环语句中，退出当前循环 */

int main()
{
    /* 1. switch */
    cout << "Input 1, 2, or 3." << endl;
    int select = 0;
    cin >> select;
    switch (select){
        case 1:
            cout << "Your selection is easy."<< endl;
            break;
        case 2:
            cout << "Your selection is normal."<< endl;
            break;
        case 3:
            cout << "Your selection is difficult."<< endl;
            break;
        default:
            cout << "Your selection is normal."<< endl;
            break;
    }

    /* 2. for */
    for (int i = 0; i < 10; i++){
        if (i == 5){
            break;
        }
        cout << i << endl;
    }

    /* 3. Multi-For */
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j < 10; j++){
            cout << '*';
            if (j == 5){
                break; // 退出内层循环
            }
        }
        cout << endl;
    }
}