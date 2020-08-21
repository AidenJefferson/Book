// Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal,
// decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal
// form. Then your program should output the values in properly spaced columns like this:

//     0x43 hexadecimal converts to 67 decimal
//     0123 octal       converts to 83 decimal
//     65   decimal     converts to 65 decimal

#include <iostream>
#include <vector>
#include <string>

int main(){
    std::cin.unsetf(std::ios::dec); 
    std::cin.unsetf(std::ios::oct);
    std::cin.unsetf(std::ios::hex);

    int num{0};
    std::vector<int> entries;
    std::vector<char> types;
    int input{0};

    std::cout << "Please enter some integers (use 0 for octal, 0x for hexadecimal and regular format for decimal)" << std::endl;

    char c2;
    for(char c; std::cin >> c;){
        switch(c){
            case '0':
                c2 = std::cin.peek();
                if(isdigit(c2)){
                    std::cin.putback(c);
                    std::cin >> input;
                    entries.push_back(input);
                    types.push_back('o');
                }
                else if(c2 == 'x' || c2 == 'X'){
                    std::cin.putback(c);
                    std::cin >> input;
                    entries.push_back(input);
                    types.push_back('h');
                }
                else throw std::runtime_error("incorrect format entered");

                break;
            default:
                if(!isdigit(c)) throw std::runtime_error("no digit entered");
                std::cin.putback(c);
                std::cin >> input;
                entries.push_back(input);
                types.push_back('d');
                break;
        }
    }   

    std::cout << std::showbase;
    for(int i=0; i < entries.size(); i++){
        switch(types[i]){
            case 'h':
                std::cout << std::hex << entries[i] << "\t(hexadecimal) converts to\t" << std::dec << entries[i] << std::endl;
                break;
            case 'o':
                std::cout << std::oct << entries[i] << "\t(octal) converts to\t" << std::dec << entries[i] << std::endl;
                break;
            case 'd':
                std::cout << std::dec << entries[i] << "\t(decimal) converts to\t" << std::dec << entries[i] << std::endl;
                break;
        }
    }

    return 0;
}
