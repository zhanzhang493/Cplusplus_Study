#include <iostream>
#include <string>
using namespace std;


/* 结构体 */
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
// 语法：
// struct 结构体名 {结构体成员列表};

// 声明结构体
struct Student
{
    string name;
    int age;
    float score;
}s3; // 声明的同时定义了一个变量

void print_Student(Student);

int main()
{   
    // 三种定义结构体变量的方式
    // 1.
    struct Student s1;
    s1.name = "Fay"; // 通过.来访问结构体的属性
    s1.age = 18;
    s1.score = 100;
    print_Student(s1);

    // 2.
    Student s2 = {"Zhan", 20, 100};
    print_Student(s2);

    // 3.
    s3 = {"Tian", 30, 60};
    print_Student(s3);

    return 0;
}

void print_Student(Student s)
{
    cout << "---------------" << endl;
    cout << "name: " << s.name << endl;
    cout << "age: " << s.age << endl; 
    cout << "score: " << s.score << endl;
}