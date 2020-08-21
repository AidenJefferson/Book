// Write a program that produces the sum of all the whitespace-separated integers in a text file. For example, bears: 17
// elephants 9 end should output 26.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main(){
    std::string inputf,  outputf;

    std::cout << "enter filename of input file:" << std::endl;
    std::cin >> inputf;
    std::ifstream ifs{inputf};
    if(!ifs) return 1;

    std::cout << "enter filename of output file:" << std::endl;
    std::cin >> outputf;
    std::ofstream ofs{outputf};
    if(!ofs) return 2;

    int sum{0};
    for(std::string data; ifs >> data;){
        if(!ifs) return 3;
        if(isdigit(data[0]))
             sum += stoi(data);
    }

    std::cout << "The sum of all the integers in the file " << outputf << " is:\t" << sum << std::endl; 

    return 0;
}
