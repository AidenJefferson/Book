// This drill has two parts.The first exercises / builds your understanding of free - store - allocated arrays and contrasts arrays with
// vectors :
// 1. Allocate an array of ten ints on the free store using new.
// 2. Print the values of the ten ints to cout.
// 3. Deallocate the array(using delete[]).
// 4. Write a function print_array10(ostream & os, int* a) that prints out the values of a(assumed to have ten elements) to os.
// 5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.;and print out its values.
// 6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.;and print out its values.
// 7. Write a function print_array(ostream & os, int* a, int n) that prints out the values of a(assumed to have n elements)
//    to os.
// 8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.;and print out its values.
// 9. Did you remember to delete the arrays ? (If not, do it.)
// 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().

#include <iostream>

// 4
void print_array10(std::ostream& os, int* a) {
	for (int i = 0; i < 10; i++) {
		os << a[i] << ", ";
	}

	os << std::endl;
}

//7
void print_array(std::ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++) {
		os << a[i] << ", ";
	}

	os << std::endl;
}


int main() {

	// 1
	int* ten_ints = new int[10]{ 0,0,0,0,0,0,0,0,0,0 };

	// 2
	for (int i = 0; i < 10; i++) {
		std::cout << ten_ints[i] << ", ";
	}
	std::cout << std::endl;

	// 3
	delete[] ten_ints;

	// 5
	int* ten_ints2 = new int[10]{ 100,101,102,103,104,105,106,107,108,109 };
	print_array10(std::cout, ten_ints2);

	delete[] ten_ints2;

	// 6
	int* ele_ints = new int[11]{ 100,101,102,103,104,105,106,107,108,109,110 };
	print_array10(std::cout, ele_ints);

	delete[] ele_ints;

	// 8
	int* twe_ints = new int[20];
	int insert{ 100 };
	for (int i = 0; i < 20; i++) {
		twe_ints[i] = insert;
		insert++;
	}
	print_array(std::cout, twe_ints, 20);

	delete[] twe_ints;

	return 0;
}


