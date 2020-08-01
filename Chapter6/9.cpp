// Modify the program from exercise 8 to write out an error if the result cannot be represented as an int.

#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main(){
    try{
        int numvalues{0}, input{0}, total{0};
        std::vector<int> inputvect;

        std::cout << "Please enter a number of values you want to sum:" << std::endl;
        std::cin >> numvalues;
        if(!std::cin >> numvalues) throw std::runtime_error("incorrect value entered, please enter integers only.");
        std::cout << "Please enter some integer values: (press '|' to stop)" << std::endl;

        while(std::cin >> input){
            inputvect.push_back(input);
        }

        if(inputvect.size()<numvalues) throw std::runtime_error("not enough values entered to be summed."); // performs test to see if vector is in range

        for(int i=0; i < numvalues; i++){
            if(total > INT_MAX - inputvect[i]) throw std::runtime_error("total too big for int variable.");
            total += inputvect[i];
        }

        std::cout << "The sum of the first " << numvalues << " values is:" << std::endl << total << std::endl;

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown Error Occured." << std::endl;
        return 2;
    }
}
