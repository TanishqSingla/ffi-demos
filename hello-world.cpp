#include <iostream>

/*
This file contains examples for hello world in shared libraries

print_hello - println takes in a string and prints the string in stdout 
*/

extern "C" {
	void print_hello() {
		std::cout << "Hello world";
	}
}
