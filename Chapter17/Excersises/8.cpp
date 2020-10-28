// 8. Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store (string knows
//    how to use the free store for you).

#include <iostream>

void add_char(std::string* s, char c) {
	*s += c;
}

int main() {

	std::string* input = new std::string;
	char c;

	while(std::cin >> c && c != '!') {

		add_char(input, c);
		
	}
	
	std::cout << *input;

	delete input;

	return 0;
}