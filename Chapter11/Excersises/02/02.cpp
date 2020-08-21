// Write a program that given a file name and a word outputs each line that contains that word together with the line
// number. Hint: getline().

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){
    try{
        std::string i_file_name, word;
        int line_number{0};

        std::cout << "Please enter the text file name:" << std::endl;
        std::cin >> i_file_name;
        std::ifstream ifs{i_file_name};
        if(!ifs) throw std::runtime_error("cannot open input file");

        std::cout << "Please enter the word to be found:" << std::endl;
        std::cin >> word;

        std::string line;
        while(std::getline(ifs, line)){
            line_number++;
            std::stringstream ss{line};
            for(std::string s; ss >> s;){
                if(s == word){
                    std::cout << "Line No. " << line_number << "\t" << line << std::endl;
                }
            }
        }

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cout << "unknown error." << std::endl;
        return 2;
    }
}
