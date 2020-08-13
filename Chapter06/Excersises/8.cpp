// Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use four letters rather than four digits.

#include <iostream>
#include <vector>
#include <string>

void error(std::string s){
    throw std::runtime_error(s);
}

bool checkgame(std::vector<char>& v){
    std::vector<char> bullcow{'a','b','c','d'};
    int bulls{0}, cows{0};
    
    for(int i=0; i < v.size(); i++){
        if(v[i] == bullcow[i]) bulls++;

        for(int j=0; j < v.size(); j++){
            if(i != j && bullcow[i] == v[j]) cows++;
        }
    }
    if(bulls == 4) return true;
    
    std::cout << "Bulls: " << bulls << "\tCows: " << cows << std::endl;
    v.clear();
    return false;
}

int main(){
    try{
        std::vector<char> entries;
        char input{' '};
        bool correct{false};
    
        while(!correct){
            std::cout << "Please enter four different letters:" << std::endl;
            for(int i=0; i<4; i++){
                std::cin >> input;
                entries.push_back(input);
            }
            correct = checkgame(entries);
        }
        std::cout << "You entered the correct result!!" << std::endl;

        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error occurred." << std::endl;
        return 2;
    }
}
