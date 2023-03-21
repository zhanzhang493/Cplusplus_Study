#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray
{
    public:
    // 构造函数
    MyArray(int capacity)
    {
        cout << "MyArray有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    
    // 拷贝构造
    MyArray(const MyArray & arr)
    {
        cout << "MyArray拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL){
            cout << "MyArray析构" << endl;
            delete [] this->pAddress;
            this->pAddress = NULL;
        }

    }

    // operator =
    MyArray& operator=(const MyArray& arr)
    {
        cout << "MyArray operator= " << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return * this;
    } 


    // 利用下标访问数组中的元素
    T& operator[](int index) // arr[0] = 100
    {
        return this->pAddress[index];
    }


    // 尾插
    void Push_Back(const T & val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Size){
            return;
        }

        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // 尾删
    void Pop_Back()
    {
        // 让用户访问不到最后一个元素，即为尾删
        if (this-m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }


    // 获取数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 获取数组大小
    int getSize()
    {
        return this->m_Size;
    }

    private:
        T * pAddress; // 指针指向堆区开辟的真实数组

        int m_Capacity;

        int m_Size;

};