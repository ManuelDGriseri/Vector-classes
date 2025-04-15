#include "vect.h"
#include<iostream>  // Pas nécessaire
using namespace m1;
int main() {
	try {
		Vect v1(3);
		Vect v2(3);
		v1[0] = 3; v1[1] = 5; v1[2] = 2;
		v2[0] = 0; v2[1] = 1; v2[2] = 3;
		std::cout << "v1 = " << v1 << std::endl;
		std::cout << "v1 + v2 = " << v1+v2 << std::endl;
		std::cout << "<v1,v2> = " << v1*v2 << std::endl;
		std::cout << "5*v1 = " << 5*v1 << std::endl;
		std::cout << "||v2||3 = " << v2.norm(3) << std::endl;
		v1[3] = 5;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}