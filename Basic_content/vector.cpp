#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
/* 
Author: zhan.zhang493@qq.com 
Begin-Date: 2022-08-12       
Details: study 'vector'   
*/


//////////////////////////////////////////////////
/* vector初始化，push_back末尾添加元素*/
void vector_init(){
	cout << "Topic 1: vector's init and push_back new component." << endl;
	vector<int> block_vec{1, 2, 3}; // 初始化
	
	block_vec.push_back(4);	//在末尾添加元素
	
	cout << "block_vec = ";
	for(int i = 1; i <= 4; i++)
	{
		cout << block_vec[i-1] << ";";
	}
	cout << endl;
}


//////////////////////////////////////////////////
/* vecotr赋值是拷贝 */
void vector_assign(){
	cout << "Topic 2: vector's assignment is a copy of original item." << endl;
	vector<int> block_vec{1, 2, 3};
	vector<int> block_vec_assign = block_vec;  // copy to a new place
	block_vec_assign.push_back(4);
	cout << "block_vec = ";
	for(int i = 0; i <= 2; i++)
	{
		cout << block_vec[i] << ";";
	}
	cout << endl;
	
	cout << "for int i : block_vec_assign, and i = i + 1" << endl;
	cout << "i = ";
	for(int i : block_vec_assign) // i copy the element in vector
	{
		i = i + 1;	// not change vector value
		cout << i << ";";
	}
	cout << endl;
	
	cout << "block_vec_assign = ";
	for(int i : block_vec_assign)  // show block_vec_assign
	{
		cout << i << ";";
	}
	cout << endl;
	
	cout << "for int &i : block_vec_assign, and i = i + 1" << endl;
	cout << "i = ";
	for(int &i : block_vec_assign) // i change --> block_vec_assign change
	{
		i = i + 1;	// not change vector value
		cout << i << ";";
	}
	cout << endl;
	
	cout << "block_vec_assign = ";
	for(int i : block_vec_assign)  // show block_vec_assign
	{
		cout << i << ";";
	}
	cout << endl;
}

int main(){
	cout << endl;
	vector_init();
	
	cout << endl;
	vector_assign();
	
	return 0;
}