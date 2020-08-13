// Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the output
// and a vector.

#include <iostream>
#include <string>
#include <vector>

void print(std::string& label, std::vector<int>& vals){
    std::cout << label << ": " << std::endl;
    for(int i=0; i < vals.size(); i++){
        std::cout << vals[i];
        if(i != vals.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(){
    try{
        std::vector<int> test{0,1,2,3,4,5};
        std::string label{"TEST"};

        print(label, test);
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown exception!" << std::endl;
        return 2;
    }
}
