#include <iostream>
#include "Book.h"

int main(){
    
    Library::Patron Aiden{"Aiden", 1, 0};

    std::cout << Aiden << std::endl;

    Aiden.set_fee(999.0);


    std::cout << Aiden << std::endl;

    return 0;
}
