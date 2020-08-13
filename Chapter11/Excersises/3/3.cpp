// Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc
// pn tm!. Surprisingly often, the result is still readable; try it on your friends.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

        std::string line, temp;
        while(std::getline(ifs, line)){
            std::stringstream ss{line};
            for(std::string s; ss >> s;){
                temp = "";
                for(int i=0; i < s.size(); i++){
                    switch(s[i]){
                        case 'a': case 'e': case 'i': case 'o': case 'u':
                        case 'A': case 'E': case 'I': case 'O': case 'U':
                            break;
                        default:
                            temp += s[i];
                    }
                    std::cout << "TEST: " << temp << std::endl;
                }
                ofs << temp << " "; 
            }
            ofs << std::endl;
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
