// 3. Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their
// lowercase equivalents. For example, Hello, World! becomes hello, world!. Do not use any standard library
// functions. A C - style string is a zero - terminated array of characters, so if you find a char with the value 0 you are at the
// end.

#include <iostream>

void to_lower(char* s) {
	int index{ 0 };

	while (s[index] != 0) {
		
		if (s[index] >= 'A' && s[index] <= 'Z') {
			s[index] += 32; // 32 will turn upper case to lower case
		}

		index++;
	}
}


int main() {

	char* string = new char[6]{ '@','I','D','3','N' };
	
	for (int i = 0; i < 6; i++) { // print string
		std::cout << string[i];
	}
	std::cout << std::endl;

	to_lower(string);

	for (int i = 0; i < 6; i++) { // print string
		std::cout << string[i];
	}
	std::cout << std::endl;
	

	return 0;
}