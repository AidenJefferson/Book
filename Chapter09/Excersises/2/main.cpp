// Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
// Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input
// operation read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age
// for each name. Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order
// determined by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and
// reorganizes the age vector to match. Implement all “operations” as member functions. Test the class (of course: test early
// and often).

#include "NamePair.h"

int main(){
    try{
        Name_pair entries;
    
        entries.read_names();
        entries.sort();
        entries.print();
        
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
