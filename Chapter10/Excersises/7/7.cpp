// Write a program that accepts two file names and produces a new file that is the contents of the first file followed by the
// contents of the second; that is, the program concatenates the two files.

#include <iostream>
#include <fstream>

int main(){
    std::string input1, input2, output, data;

    std::cout << "enter filnames of files to merge:" << std::endl;
    std::cin >> input1 >> input2;
    std::ifstream if1{input1};
    if(!if1) return 1;
    std::ifstream if2{input2};
    if(!if2) return 2;

    std::cout << "enter filnames of output file:" << std::endl;
    std::cin >> output;
    std::ofstream ofs{output};
    if(!ofs) return 3;

    while(getline(if1, data)) ofs << data << " ";
    while(getline(if2, data)) ofs << data << " ";
    
    return 0;
}
