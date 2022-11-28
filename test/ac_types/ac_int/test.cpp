#include <iostream>
#include <stdio.h>
#include "../../include/ac_types/ac_int.h"

using namespace std;

int main(){
	typedef ac_int<5, true> int5;
	int5 a = 3;
	int5 b = -13;
	std::cout << a.to_string(AC_BIN, false, true) << std::endl;
	std::cout << b.to_string(AC_BIN, false, true) << std::endl;
	return 0;
}
