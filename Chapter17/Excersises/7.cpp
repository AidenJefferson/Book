// 7. Write a program that reads characters from cin into an array that you allocate on the free store. Read individual
//    characters until an exclamation mark(!) is entered. Do not use a std::string. Do not worry about memory exhaustion.

#include <iostream>

char* add_char(char* s, char c) {
	
	int len{ 0 };
	
	while (s[len] != 0) {
		len++;
		std::cout << len << "\n";
	}
		
	char* temp = new char[len + 1];

	for (int i = 0; i < len; i++) {
		temp[i] = s[i];
	}

	temp[len] = c;

	delete[] s;

	return temp;
}

int main() {

	char* input = new char[0];
	int size{ 0 };
	char c;

	while(std::cin >> c && c != '!') {

		input = add_char(input, c);
		size++;
		
	}


	for (int i = 0; i < size; i++) {
		std::cout << input[i];
	}
	
	delete[] input;

	return 0;
}