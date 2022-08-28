#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

/* 
Author: zhan.zhang493@qq.com 
Begin-Date: 2022-08-18       
Details: study 'struct and class'   
*/

////////////////////////////////////
/* Comments:
C++ 中的struct:
1. C++结构体中不仅可以定义数据，还可以定义函数。
2. C++结构体中可以使用访问修饰符，如：public、protected、private 。
3. C++结构体使用可以直接使用不带struct。
4. C++继承
5. 若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候只能用带struct的！
*/

///////////////////////////////////
/* const 成员函数 和 const 对象 */
struct Student_info{
	// 数据成员
	std::string student_name;
	std::string student_id;
	double math_score = 0;
	
	// 成员函数
	std::string name() const { return student_name; } // const 成员函数
	double current_score();
	Student_info& update_name(const std::string &);
};

/* Comments:
std::string name() 等价于 std::string name(&zhang_zhan) {return this -> student_name}

this是隐形形参，编译器将zhang_zhan的地址传递给this，this是一个常量指针，但指向的类类型不是const (important);
因此，std::string name() const, 这个const位于参数列表后，是将this改为指向const类类型的指针，即const 类类型 *const this
若参数列表后没有const，则等效于 类类型 *const this;
const 类类型 *const this 可以指向 const对象，也可以指向非const对象，因此任何对象都可以访问const 成员函数
但是 类类型 *const this 不能指向 const对象，也就是说，const对象只能访问const 成员函数。

任何不会修改数据成员的函数都应该声明为const类型，即std::string name() const
等价于 std::string Student_info::name(const Student_info *const this)

std::string name() 等价于 std::string Student_info::name(Student_info *const this)
*/

Student_info& Student_info::update_name(const std::string &name){
	student_name = name;
	return *this; 
}
/* Comments:
查阅函数返回值，使用引用的原因：待补充；
*this 返回调用该函数的对象*/


int main(){
	struct Student_info zhang_zhan;
	zhang_zhan.update_name("zhang zhan");
	cout << zhang_zhan.student_name << endl;
	
}
