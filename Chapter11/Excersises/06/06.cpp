// Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question
// mark), - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For
// example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.

#include <iostream>
#include <string>
#include <vector>

void remove_punct(std::string& s){
    for(int i=0; i < s.length(); i++){
        switch(s[i]){
            case '.': case ';': case ',':
            case '?': case '-': case '\'':
                s[i] = ' ';
        }
    }
}

int main(){
    try{
        std::cout << "Please enter a series of strings: (use Ctrl-D to finish)" << std::endl;
        std::vector<std::string> entries;
        for(std::string s; std::cin >> s;){
            remove_punct(s);
            entries.push_back(s);
        }

        std::cout << "Your entry without the punctuation is:" << std::endl;
        for(int i=0; i < entries.size(); i++){
            std::cout << entries[i] << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    catch(...){
        std::cerr << "unknown error." << std::endl;
    }
}
