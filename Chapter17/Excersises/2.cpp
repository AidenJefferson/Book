// 2. How many bytes are there in an int ? In a double ? In a bool ? Do not use sizeof except to verify your answer.

#include <iostream>

int main() {

	std::cout << sizeof(int) << std::endl; // 4 bites
	std::cout << sizeof(double) << std::endl; // 8 bites
	std::cout << sizeof(bool) << std::endl; // 1 bite

	return 0;
}