// Write a program that accepts two file names and produces a new file that is the contents of the first file followed by the
// contents of the second; that is, the program concatenates the two files.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(){
    std::string input1, input2, output;

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

    std::vector<std::string> words;
    for(std::string data; if1 >> data;){
        if(!if1) return 4;
        words.push_back(data);
    }
    for(std::string data; if2 >> data;){
        if(!if2) return 5;
        words.push_back(data);
    }

    std::sort(words.begin(), words.end());
    for(std::string s : words){
        ofs << s << " ";
    }
    
    return 0;
}
