// 4.	Write a function, char* strdup(const char*), that copies a C - style string into memory it allocates on the free store.
//		Do not use any standard library functions.

#include <iostream>

char* sttrdup(const char* input) {

	int count{ 1 }, index{ 0 };
	
	// find length of input
	while (input[index] != 0) {
		count++;
		index++;
	}

	// allocate memory in free store

	char* string = new char[count];

	// copy and return string
	for (int i = 0; i < count; i++) {
		string[i] = input[i];
	}
	

	return string;
}


int main() {

	char* string = new char[6]{ 'A','I','D','E','N' };
	char* output;

	output = sttrdup(string);
	
	for (int i = 0; i < 6; i++) {
		std::cout << output[i];
	}

	return 0;
}