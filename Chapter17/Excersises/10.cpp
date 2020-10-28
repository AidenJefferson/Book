// 10. Look at your solution of exercise 7. Is there any way that input could get the array to overflow; that is, is there any way
//     you could enter more characters than you allocated space for (a serious error)? Does anything reasonable happen if you
//     try to enter more characters than you allocated?

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