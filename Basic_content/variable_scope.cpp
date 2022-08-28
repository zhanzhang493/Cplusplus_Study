#include <iostream>

int gloable_var = 100;

int main(){
	std::cout << "Topic: variable scope study notes." << std::endl;
	int main_var = 100;
	
	for(int i = 1; i <= 10; i++){
		int block_var = 100;
		if(i != 1){
			int block_var2 = 100;
			
			block_var = block_var - i;
			block_var2 = block_var2 - i;
			std::cout << block_var2 << std::endl;
		}
		std::cout << block_var << std::endl;
		#if 0
		std::cout << block_var2 << std::endl; // error, block_var2 is not defined in this block
		#endif
	}
	#if 0
	std::cout << block_var << std::endl; // error, block_var is not defined in this block
	#endif
}
