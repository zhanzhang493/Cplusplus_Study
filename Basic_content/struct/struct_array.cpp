#include <iostream>
#include <string>
using namespace std;


/* 结构体数组 */
// 语法： struct 结构体名 数组名[元素个数]


// 声明结构体
struct Student
{
    string name;
    int age;
    float score;
};

void print_Student(Student);

int main()
{   
    Student arr[3] = {
        {"Fay", 18, 100},
        {"Zhan", 20, 99},
        {"Tian", 30, 94}
    };
    for (int i = 0; i < 3; i++){
        print_Student(arr[i]);
    }
}

void print_Student(Student s)
{
    cout << "---------------" << endl;
    cout << "name: " << s.name << endl;
    cout << "age: " << s.age << endl; 
    cout << "score: " << s.score << endl;
}