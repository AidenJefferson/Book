// Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.; leaves
// hyphens within words intact (so that we get “ do not use the as-if rule ”); and converts all characters to lower case.

#include <iostream>
#include <string>
#include <vector>

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
        return 1;
    }
}
