// Write a program that reads strings and for each string outputs the character classification of each character, as defined by
// the character classification functions presented in §11.6. Note that a character can have several classifications (e.g., x is
// both a letter and an alphanumeric).

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void output_classification(std::ofstream& ofs, const std::string& s){

    ofs << std::endl << "Classification in string " << s << ":" << std::endl;
    for(int i=0; i < s.length(); i++){
        ofs << s[i] << ":" << std::endl;
        if(std::isspace(s[i])) ofs << "\tSPACE" << std::endl;
        if(std::isalpha(s[i])) ofs << "\tALPHA" << std::endl;
        if(std::isdigit(s[i])) ofs << "\tDIGIT" << std::endl;
        if(std::isxdigit(s[i])) ofs << "\tHEX-DIGIT" << std::endl;
        if(std::isupper(s[i])) ofs << "\tUPPER-CASE" << std::endl;
        if(std::islower(s[i])) ofs << "\tLOWER-CASE" << std::endl;
        if(std::isalnum(s[i])) ofs << "\tLETTER-OR-DECIMAL" << std::endl;
        if(std::iscntrl(s[i])) ofs << "\tCONTROL-CHARACTER" << std::endl;
        if(std::ispunct(s[i])) ofs << "\tPUNCTUATION" << std::endl;
        if(std::isprint(s[i])) ofs << "\tPRINTABLE" << std::endl;
        if(std::isgraph(s[i])) ofs << "\tISNT-A-SPACE" << std::endl;
    }
}

int main(){
    try{
        std::string file_name;
        std::cout << "Please enter the name of an output file:" << std::endl;
        std::cin >> file_name;
        std::ofstream ofs{file_name};
        if(!ofs) throw std::runtime_error("could not open file.");

        std::cout << "Please enter a series of strings: (use Ctrl-D to make entries)" << std::endl;
        for(std::string s; std::cin >> s;){
            output_classification(ofs, s);
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
