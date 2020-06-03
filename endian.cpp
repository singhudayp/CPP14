#include <iostream>

#define B_ENDIAN 0
#define L_ENDIAN 1
 
//Method one
int CheckByteOrder() {
        short int word = 0x0001;
        char *b = (char *)&word;
        return (b[0] ? L_ENDIAN : B_ENDIAN);
}
 
//method 2
int endian() {
	union {
		int one;
		char ch;
	} endn;

	endn.one = 1;
	return endn.ch;
}
int main() {
	// Using Method 1
        if(CheckByteOrder()) {
        	std::cout << "Little Endian" << std::endl;
	} else {
		std::cout << "Big Endian" << std::endl;
	}
	
	// Using Method 2 
	if(endian()) { 
        	std::cout << "Little Endian" << std::endl;
	} else {
		std::cout << "Big Endian" << std::endl;
	}

       return 0;
}
