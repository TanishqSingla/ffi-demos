/*
This file contains examples for functions that recieves 
and return data.

sum - A function that recieves 2 int arguments and returns sum of those
      values

println - println takes in a string and prints the string in stdout 
*/

#include <iostream>
extern "C" {
	int sum (int a, int b) {
		return a + b;
	}

	void println(const char* str) {
		std::cout << str;
	}
}
