#include <iostream>
#include <string>
using namespace std;


/* 结构体指针 */
// 利用操作符 -> 可以通过结构体指针访问结构体属性


// 声明结构体
struct Student
{
    string name;
    int age;
    float score;
};

void print_Student(Student);
void print_Student(Student *);

int main()
{   
    /* 结构体指针 */
    struct Student s1;
    s1.name = "Fay"; // 通过.来访问结构体的属性
    s1.age = 29;
    s1.score = 90;
    print_Student(s1);

    Student * p = &s1;
    print_Student(p);

    /* 结构体数组指针 */
    Student arr[3] = {
        {"Fay", 18, 100},
        {"Zhan", 20, 99},
        {"Tian", 30, 94}
    };

    Student * q = arr;
    for (int i = 0; i < 3; i++){
        print_Student(q);
        q++;
    }

}

void print_Student(Student s)
{
    cout << "---------------" << endl;
    cout << "结构体值传递" << endl;
    cout << "name: " << s.name << endl;
    cout << "age: " << s.age << endl; 
    cout << "score: " << s.score << endl;
}

void print_Student(Student * ptr)
{
    cout << "---------------" << endl;
    cout << "结构体地址传递" << endl;
    cout << "name: " << ptr->name << endl;
    cout << "age: " << ptr->age << endl; 
    cout << "score: " << ptr->score << endl;
}