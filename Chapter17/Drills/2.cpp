//	The second part focuses on pointers and their relation to arrays. Using print_array() from the last drill:
//
//	1.	Allocate an int, initialize it to 7, and assign its address to a variable p1.
//	2.	Print out the value of p1 and of the int it points to.
//	3.	Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
//	4.	Print out the value of p2 and of the array it points to.
//	5.	Declare an int* called p3 and initialize it with p2.
//	6.	Assign p1 to p2.
//	7.	Assign p3 to p2.
//	8.	Print out the values of p1 and p2 and of what they point to.
//	9.	Deallocate all the memory you allocated from the free store.
//	10.	Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
//	11. Allocate an array of ten ints, and assign its address to a variable p2.
//	12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
//	13. Repeat 10–12 using a vector rather than an array.

#include <iostream>

void print_array(std::ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++) {
		os << a[i] << ", ";
	}

	os << std::endl;
}

int main() {

	// 1
	int x = 7;
	int* p1 = &x;

	// 2
	std::cout << "Value of p1: " << p1 << std::endl
		<< "Value it points to: " << *p1 << std::endl;

	// 3
	int sev_ints[7]{ 1,2,4,8,16,32,64 };
	int* p2 = sev_ints;

	// 4
	print_array(std::cout, sev_ints, 7);
	print_array(std::cout, p2, 7);

	// 5
	int* p3 = p2;

	// 6
	p1 = p2;

	// 7
	p3 = p2;

	// 8
	print_array(std::cout, p1, 7);
	print_array(std::cout, p2, 7);

	// 9

	//	10
	int ten_ints[10]{ 1,2,4,8,16,32,64,128,256,512 };
	p1 = ten_ints;

	// 11
	int ten_ints2[10];
	p2 = ten_ints;
	
	// 12
	*p2 = *p1;
	print_array(std::cout, p2, 10);



	return 0;
}


