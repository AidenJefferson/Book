#include "Roman.h"
#include <iostream>

int main(){
    try{
        Roman_int r;
        std::string num;

        std::cout << "enter a roman numeral (use only symbols up to M)" << std::endl;
        std::cin >> num;

        r.set_numeral(num);
        
        std::cout << "Numeral: " << r.get_numeral() << "\tINT: " << r.as_int() << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return 1;
    }
}
