// Use the program from the previous exercise to make a dictionary (as an alternative to the approach in §11.7). Run the
// result on a multi-page text file, look at the result, and see if you can improve the program to make a better dictionary.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

void remove_punct(std::string& s){
    for(int i=0; i < s.length(); i++){
        switch(s[i]){
            case '.': case ';': case '?': case ',':
                s[i] = ' ';
                break;
            case '-':
                if(std::isalpha(s[i-1]) && std::isalpha(s[i+1])) {}
                else s[i] = ' ';
                break;
            case '\'':
                s[i-1] = ' ';
                s[i] = 'n';
                s[i+1] = 'o';
                s += 't';
                break;
        }
    }
}

int main(){
    try{
        std::string i_file_name, o_file_name;
        std::cout << "Please enter a file name for text:" << std::endl;
        std::cin >> i_file_name;
        std::ifstream ifs{i_file_name};
        if(!ifs) throw std::runtime_error("Could not open input file");

        std::cout << "Please enter output file name:" << std::endl;
        std::cin >> o_file_name;
        std::ofstream ofs{o_file_name};
        if(!ofs) throw std::runtime_error("Could not open input file");

        std::string previous;
        for(std::string s; ifs >> s;){
            if(s != previous){
                remove_punct(s);
                ofs << s << std::endl;
            }
            previous = s;
        }

        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown error." << std::endl;
        return 2;
    }
}
