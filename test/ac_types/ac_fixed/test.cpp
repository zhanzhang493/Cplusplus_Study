#include <iostream>
#include <vector>
#include <string>
#include "ac_fixed.h"

using namespace std;

typedef ac_fixed<12, 1, true> TypeInput;

int main(){
    TypeInput a = -0.222;
	std::cout << a.to_string(AC_BIN, false, false) << std::endl;
    std::cout << a.to_string(AC_BIN, false, true) << std::endl;
	std::cout << a.to_string(AC_BIN, true, false) << std::endl;
	std::cout << a.to_string(AC_BIN, true, true) << std::endl;
}
