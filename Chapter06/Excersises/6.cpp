// Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1. Assume that every
// sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but the fish swim . is a
// sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim. (no space
// before dot) are not. For each sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t bother
// with tokens; just read into a string using >>.

/* Grammer to be used:
 *
 * Sentence:
 *     Noun Verb // e.g., C++ rules
 *     Article Noun Verb
 *     Sentence Conjunction Sentence // e.g., Birds fly but fish swim
 * Conjunction:
 *     "and"
 *     "or"
 *     "but"
 * Article:
 *     "the"
 * Noun:
 *     "birds"
 *     "fish"
 *     "C++"
 * Verb:
 *     "rules"
 *     "fly"
 *     "swim"
 */

// NOTE: This program is built using calculator00.cpp as a source of info.

#include <iostream>
#include <string>

class StrStream{
public:
    StrStream();
    std::string get();
    void put_back(std::string s);
private:
    bool full;
    std::string buffer;
};

void error(std::string s){
    throw std::runtime_error(s);
}

StrStream::StrStream()
    : full{false}, buffer{""} {}

std::string StrStream::get(){
    if(full){
        full = false;
        return buffer;
    }
    std::string s;
    std::cin >> s;
    return s;
}

void StrStream::put_back(std::string s){
    if(full) error("string stream already full.");
    
    full = true;
    buffer = s;
}

StrStream strs;

bool noun();
bool verb();
bool art();
bool conj();
bool sentence();

bool sentence(){
    return art();
}

bool conj(){
    std::string s = strs.get();
    if(s == "and" || s == "or" || s == "but"){
        return true;
    }
    else{
        return false;
    }
}

bool art(){
    std::string s = strs.get();
    if(s == "the"){
        return noun();
    }
    strs.put_back(s);
    return noun();
}

bool noun(){
    std::string s = strs.get();
    if(s == "birds" || s == "fish" || s == "C++"){
        return verb();
    }
    return false;
}

bool verb(){
    std::string s = strs.get();
    if(s == "rules" || s == "fly" || s == "swim"){
        return true;
    }
    return false;
}

int main(){
    try{
        bool sentenceCheck{false};
        std::cout << "Please enter a sentence for parsing followed by a full stop." << std::endl;
        while(std::cin){
            sentenceCheck = sentence();
            if(!sentenceCheck){
                std::cout << "Not a valid sentence." << std::endl;
                return 0;
            }
            std::string s = strs.get();
            if(s == "."){
                std::cout << "This is a valid sentence." << std::endl;
                return 0;
            }
            else{
                strs.put_back(s);
                sentenceCheck = conj();
                if(!sentenceCheck){
                    std::cout << "Not a valid sentence." << std::endl;
                    return 0; 
                }
            }
        }
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error found." << std::endl;
        return 2;
    }
}


