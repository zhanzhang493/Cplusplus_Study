#include <iostream>

using std::cout;
using std::endl;
/* 
Author: zhan.zhang493@qq.com 
Begin-Date: 2022-08-13       
Details: study 'array and pointer'   
*/


void array_init(){
	cout << "Topic 1: array's init." << endl;
	int a[] = {0, 1, 2};
	int *ptr = a;
	cout << "a[1] = " << a[1] << endl; 
	cout << "a[1] = " << ptr[1] << endl;
	cout << "a[1] = " << *(a + 1) << endl;
	cout << "a[1] = " << *(ptr + 1) << endl; 
	cout << "a[1] address is " << &a[1] << endl; 
	cout << "a[1] address is " << a + 1 << endl; 
	cout << "a[1] address is " << &ptr[1] << endl; 
	cout << "a[1] address is " << ptr + 1 << endl;

	cout << "a[3] = " << *(ptr + 3) << endl; // 不会warning, 但指针有可能会越界
	cout << "a[3] = " << *(a + 3) << endl; // 不会warning, 数组也有可能会越界
	cout << "a[3] = " << a[3] << endl; // 不会warning, 数组也有可能会越界
	/* Comments: 数组和指针可以互换操作；ptr+1为a[1]的地址*/
	
	#if 0
	int a_copy = a; 
	/* 不能用数组去初始化另外一个数组;
	报错：error: invalid conversion from 'int*' to 'int'*/
	#endif
}

void array_declare(){
	cout << "Topic 2: complex array's declare." << endl;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Arr address is " << arr << endl;
	cout << "Arr[1] address is " << &arr[1] << endl;
	cout << "Arr[2] address is " << arr + 2 << endl;  // arr + 2 = &arr[2] 取地址，指针操作
	cout << "Arr first value is " << *arr << endl;
	cout << " int is " << sizeof(int) << " bytes. " << endl;
	cout << " double is " << sizeof(double) << " bytes. " << endl;
	
	
	int *ptrs[10]; 
	/* ptrs 是一个含有10个整型指针的数组；
	从右往左绑定理解：
	1. 定义了一个大小为10的数组；
	2. 名字是ptrs；
	3. ptrs是指针
	3. 指向int的指针*/
	cout << ptrs[0] << endl;
	cout << ptrs[1] << endl;
	
	#if 0
	int &refs[10] = ptrs; // error: 数组的元素必须是对象，引用不是对象
	#endif
	
	int (*arrPtr)[10] = &arr;
	/* arrPtr 是一个指针，指向含有10整数的数组；
	先从括号内读，然后从右往左：
	1. arrPtr是个指针；
	2. 指向大小为10的数组的指针；
	3. 数组的元素是int */
	cout << "arrPtr address is "<< arrPtr << endl; // interesting, why?
	cout << "arrPtr address is "<< *arrPtr << endl; // interesting, why?
	cout << *(*arrPtr + 4) << endl;   // interesting, obtain arr[4], but why? 见twoDarray()
	/* comments:理解多维数组和指针的关系。见twoDarray()*/
	
	int (&arrRef)[10] = arr;
	/* arrRef 是一个引用，引用含有10整数的数组；
	先从括号内读，然后从右往左：
	1. arrRef是个引用；
	2. 引用对象是大小为10的数组；
	3. 数组的元素是int */
	cout << arrRef[3] << endl; // 取出arr[3]
	cout << *(arrRef+3) << endl;
	
	int *(&arry)[10] = ptrs;
	/* arry是数组的引用，该数组包含10个int型指针
	先从括号内读，然后从右往左：
	1. arry是个引用；
	2. 引用对象是大小为10的数组；
	3. 数组的元素是int型指针*/
}

void twoDarray(){
	cout << "Topic 3: two dimensional array and pointer." << endl;
	int ia[2][3] ={1, 2, 3, 4, 5, 6};
	cout << "2-d array ia address is:" << ia << endl;
	
	cout << "ia[0][0] =" << ia[0][0] << endl;
	cout << "ia[0][0] =" << **ia << endl;
	cout << "ia[0][0] address is" << &ia[0][0] << endl;
	
	cout << "ia[1][2] =" << ia[1][2] << endl;
	cout << "ia[1][2] =" << *(*(ia + 1) + 2) << endl;
	cout << "ia[1][2] =" << *(ia[1] + 2) << endl;
	cout << "ia[1][2] address is" << &ia[1][2] << endl;
	cout << "ia[1][2] address is" << (*(ia + 1) + 2) << endl;
	cout << "ia[1][2] address is" << (ia[1] + 2) << endl;
	
	cout << "ia[1] address is" << ia[1] << endl;
	cout << "ia[1] address is" << (ia+1)<< endl;
	cout << "ia[1] address is" << *(ia+1)<< endl;
	
	/* Comments: 
	1. 二维数组ia[2][3]，ia是该数组首元素地址，ia的首元素是{ia[0][0], ia[0][1], ia[0][2]},
	因此 ia + 1 = ia[1] 为ia第二个元素的地址；
	2. 为什么 ia[1] = ia + 1 = *(ia + 1), 
	ia[1] = ia + 1 表示ia[1]地址，
	*(ia + 1)表示ia[1]首元素的地址，即&ia[1][0],
	ia[1] 和 ia[1][0]具有相同的地址，因此得到的地址相同，但实际底层略有区别;
	3. ia[1][2] = *(*(ia + 1) + 2), 若以指针进行表示，需要解两次*/
	
	int (*ptr_2d)[3] = ia; 
	/* ptr_2d 指向一个包含3个int的数组，因此ptr_2d[1] == ptr_2d + 1, 
	从地址上看会越过这个包含3个int的数组，即这个包含3个int的数组是某个数组的首元素；
	与 int ptr[3] 的区别是，此时的ptr指向的是ptr的首元素，即ptr[0]*/
	cout << "ia[1][2] = " << *(*(ptr_2d + 1) + 2) << endl;
	cout << "ia[1][2] address is" << (*(ptr_2d + 1) + 2) << endl;
	cout << "ia[1][2] = " << ptr_2d[1][2] << endl;
	cout << "ia[1][2] address is" << &(ptr_2d[1][2]) << endl;
	
	cout << "ia[1] address is" << *(ptr_2d + 1) << endl;
	cout << "ia[1] address is" << ptr_2d + 1 << endl;
	cout << "ia[1] address is" << ptr_2d[1] << endl;
	/* Comments: 指针可以写为数组形式.*/
}


void sum_rows(int arr[][3], int rows);
void sum_rows(float [][3], int);
void sum_rows(double *(arr)[3], int rows);
/* Comments: 函数和多维数组，上述三种均ok*/

int main(){
	cout << endl;
	array_init();
	
	cout << endl;
	array_declare();
	
	cout << endl;
	twoDarray();
	
	cout << endl;
}
