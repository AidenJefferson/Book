// Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
// vector<Name_value> instead of two vectors.

/*
 * Chapter 4, Excersise 9:
 * 
 * Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add
 * the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if
 * names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
 * terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
 */
#include <iostream>
#include <vector>
#include <string>

class Name_value {
public:
    std::string name;
    int value;
    Name_value(std::string Nam, int Val)
        : name{Nam}, value{Val} {}
};

int main(){
    try{
        std::vector<Name_value> entries;
        std::string nameentry;
        int scoreentry{0};

        std::cout << "Please enter a name followed by a score, press Ctrl-D to end." << std::endl;
        while(std::cin >> nameentry >> scoreentry){
            for(int i=0; i<entries.size(); i++)
                if(entries[i].name == nameentry) throw std::runtime_error("name entered twice.");
            entries.push_back(Name_value(nameentry,scoreentry));
        }

        std::cout << "You entered:" << std::endl;
        for(int i=0; i<entries.size(); i++){
            std::cout << entries[i].name << "\t" << entries[i].value << std::endl; 
        }

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error occurred." << std::endl;
    }
}
