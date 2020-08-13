// Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.

#include "NamePair.h"

int main(){
    try{
        Name_pair entries;
    
        entries.read_names();
        entries.sort();
       
        Name_pair copy = entries;
        if(entries == copy)
            std::cout << entries << std::endl;

        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown error: " << std::endl;
        return 2;
    }
}
