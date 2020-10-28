// 5. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C - style string x in s.

#include <iostream>

char* findx(const char* s, const char* x){

	int count_s{ 1 }, count_x{ 1 }, index{ 0 };
	int char_found{ 0 };

	while (s[index] != 0) { // find length of s
		count_s++;
		index++;
	}
	
	index = 0;

	while (x[index] != 0) { // find length of x
		count_x++;
		index++;
	}
	
	char* output = new char[count_x];

	if (count_x > count_s) { 
		return nullptr; 
	}
	else {

		for (int i = 0; i < (count_s - count_x); i++) {
			if (s[i] == x[0]) {
				
				output[0] = s[i];
				char_found++;

				for (int j = 1; j < count_x; j++) {
					if (s[i + j] == x[j]) {
						
						output[j] = s[i + j];
						char_found++;

					}
					if (char_found == count_x) break;
				}

			}
		}

	}
	return output;

}


int main() {

	char* string = new char[10]{ 'A','I','D','E','N','T','E','S','T' };
	char* search = new char[5]{ 'D','E','N','T' };
	char* output;

	output = findx(string, search);
	
	for (int i = 0; i < 4; i++) {
		std::cout << output[i];
	}

	delete[] string;
	delete[] search;
	delete[] output;

	return 0;
}