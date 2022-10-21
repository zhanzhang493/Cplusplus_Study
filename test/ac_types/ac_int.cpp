#include <iostream>
#include <stdio.h>
#include "../../include/ac_types/ac_int.h"

using std::cout;
using std::endl;



int main(){
	typedef ac_int<5, true> int5;
	int5 a = 3;
	cout << a << endl;
	return 0;
}
