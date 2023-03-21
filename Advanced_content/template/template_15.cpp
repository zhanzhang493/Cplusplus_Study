#include <iostream>
#include <string>
using namespace std;

#include "myArray.hpp"

/* 案例 */
// 实现一个通用的数组类
// 可以对内置数据类型以及自定义数据类型的数据进行存储
// 将数组中的数据存储到堆区
// 构造函数中可以传入数组的容量
// 提供对应的拷贝构造函数以及operator=防止浅拷贝
// 提供尾插法和尾删法对数组中的数据进行增加和删除
// 可以通过下标的方式访问数组中的元素
// 可以获取数组中当前元素的个数和数组的容量

class Person
{
    public:
        Person() {} // 必须要提供无参构造函数， 否则myArray无法调用Person
        Person(string name, int age): m_Name(name), m_Age(age) {}

        string m_Name;
        int m_Age;
};

template<typename T>
void printArray(MyArray<T> & arr)
{   
    cout << "arr中数据为: ";
    for (int i = 0; i < arr.getSize(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout << "arr中capacity: " << arr.getCapacity() << endl;
    cout << "arr中size: " << arr.getSize() << endl;
}

void test01()
{
    cout << "Test 01 -------------------" << endl; 
    MyArray<int> arr1(5);

    MyArray<int> arr2(arr1);

    MyArray<int> arr3(100);
    arr3 = arr1;
}

void test02()
{
    cout << "尾插 -------------------" << endl; 
    MyArray<int> arr1(5);

    for (int i = 0; i < 5; i++){
        arr1.Push_Back(i);
    }
    printArray(arr1);

    cout << "尾删 -------------------" << endl; 
    arr1.Pop_Back();
    printArray(arr1);

    cout << arr1[4] << endl;

}

void printPersonArray(MyArray<Person> & arr)
{
    cout << "arr中数据为: " << endl;
    for (int i = 0; i < arr.getSize(); i++){
        cout << "name: " << arr[i].m_Name << ", ";
        cout << "age: " << arr[i].m_Age << ", " << endl;
    }
    cout << "arr中capacity: " << arr.getCapacity() << endl;
    cout << "arr中size: " << arr.getSize() << endl;
}


void test03()
{
    cout << "Person 尾插 -----------------" << endl; 
    MyArray<Person> arr1(5);

    Person p1("zz", 19);
    Person p2("fay", 18);

    arr1.Push_Back(p1);
    arr1.Push_Back(p2);
    printPersonArray(arr1);

    cout << "尾删 -------------------" << endl; 
    arr1.Pop_Back();
    printPersonArray(arr1);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}