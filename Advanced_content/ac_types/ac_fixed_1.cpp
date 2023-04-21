#include <iostream>
#include <string>

#include "ac_fixed.h"
using namespace std;
typedef ac_fixed<12, 1, true> TypeInput;

int main(){
    float a = -1.0;
    TypeInput a_fixed = a;
    cout << a_fixed << endl;
    cout << std::hex << a_fixed << endl;
    cout << std::bin << a_fixed << endl;
	cout << a_fixed.to_string(AC_BIN, false, false) << endl;
    cout << a_fixed.to_string(AC_BIN, false, true) << endl;
	cout << a_fixed.to_string(AC_BIN, true, false) << endl;
	cout << a_fixed.to_string(AC_BIN, true, true) << endl;
}