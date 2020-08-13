// Write a program that reads a text file and converts its input to all lower case, producing a new file.

#include <iostream>
#include <fstream>
#include <string>

int main(){
    try{
        std::string i_file_name, o_file_name;

        std::cout << "Please enter the text file name:" << std::endl;
        std::cin >> i_file_name;
        std::ifstream ifs{i_file_name};
        if(!ifs) throw std::runtime_error("cannot open input file");

        std::cout << "Please enter the output file name:" << std::endl;
        std::cin >> o_file_name;
        std::ofstream ofs{o_file_name};
        if(!ofs) throw std::runtime_error("cannot open output file");

        std::string line;
        while(std::getline(ifs, line)){
            for(char& x : line){
                x = std::tolower(x);
                ofs << x;
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
