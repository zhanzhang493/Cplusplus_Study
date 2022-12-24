#include <iostream>
#include <string>
using namespace std;


/* 结构体与const */
// 用const防止误操作
// 保证了虽然传递了指针，但是形参是常量指针，不允许修改指针指向的内存的值

// 声明结构体
struct Student
{
    string name;
    int age;
    float score;
};

struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu;
};

void print_Student(const Student *);
void print_Teacher(const Teacher *);
void change_Teacher(Teacher *);

int main()
{
    Teacher t1 = {288, "Ricky", 45, {"zhan", 28, 100}};
    print_Teacher(&t1);
    change_Teacher(&t1);
    print_Teacher(&t1);
}

void print_Student(const Student * ptr)
{
    cout << "\t" << "name: " << ptr->name << endl;
    cout << "\t" << "age: " << ptr->age << endl; 
    cout << "\t" << "score: " << ptr->score << endl;
}

void print_Teacher(const Teacher * ptr)
{
    cout << "===============" << endl;
    cout << "结构体地址传递" << endl;
    cout << "id: " << ptr->id << endl;
    cout << "name: " << ptr->name << endl;
    cout << "age: " << ptr->age << endl; 
    cout << "His/her student:" << endl;
    print_Student(&ptr->stu);
}

void change_Teacher(Teacher * ptr) // 不能加const
{
    ptr->age++;
}