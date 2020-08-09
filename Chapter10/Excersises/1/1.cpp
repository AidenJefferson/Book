// Write a program that produces the sum of all the numbers in a file of whitespace-separated integers

#include <iostream>
#include <fstream>

int main(){
    int sum{0};
    std::ifstream ifs{"sum.txt"};

    for(int number; ifs >> number;){
        sum += number;
    };

    std::cout << "Sum of all number in sum.txt is " << sum << std::endl;
}
