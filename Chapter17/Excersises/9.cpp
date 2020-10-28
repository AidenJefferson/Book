// 9.	Which way does the stack grow: up(toward higher addresses) or down(toward lower addresses)? Which way does the
//		free store initially grow(that is, before you use delete) ? Write a program to determine the answers.

#include <iostream>

int main() {
	
	int first{ 0 };
	int second{ 0 };

	if (&first > &second) {
		std::cout << "Stack grows down" << std::endl;
	}
	else std::cout << "Stack grows up" << std::endl;


	int* firstp = new int{ 0 };
	int* secondp = new int{ 0 };

	if (first > second) {
		std::cout << "Free store grows down" << std::endl;
	}
	else std::cout << "Free store grows up" << std::endl;

	return 0;
}