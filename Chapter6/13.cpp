// Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a vector of four
// different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover those numbers by
// repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1
// cow” because the user got one digit (1) right and in the right position (a bull) and one digit (3) right but in the wrong
// position (a cow). The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct
// order.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void error(std::string s){
    throw std::runtime_error(s);
}

int main(){
    try{
        std::vector<int> bullcow, entries;
        int input{0}, size{4}; // inputted guesses
        int bulls{0}, cows{0};
        bool correct{false};
        
        for(int i=0; i<size; i++){
            bullcow.push_back(rand() % 10);
        }

        std::cout << "Welcome to Bulls and Cows. Please guess a four digit code of values from 0-9 (seperate numbers with spaces, all numbers should be different)." << std::endl;
        
        while(!correct){
            bulls = 0;
            cows = 0;

            for(int i=0; i<bullcow.size(); i++){ // take guess of code.
                std::cin >> input;
                
                for(int i=0; i<entries.size(); i ++)
                    if(input == entries[i]) error("repeat entry guessed. Please guess four different values.");
                
                if(input < 0 || input > 9 ) error("invalid entry entered. Please enter values of 0-9");

                entries.push_back(input);
            }

            for(int i=0; i<bullcow.size(); i++){
                if(bullcow[i] == entries[i])
                    bulls++;

                for(int j=0; j < bullcow.size(); j++){
                    if(i != j && bullcow[i] == entries[j])
                        cows++;
                }
            }
                        
            if(bulls == 4)
                correct = true;

            std::cout << bulls << " bull(s) and " << cows << " cow(s)" << std::endl;

            entries.clear();
        }

        std::cout << "YOU WIN!! Thanks for playing." << std::endl;

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error occured." << std::endl;
        return 2;
    }
}
