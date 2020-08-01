// Modify the program from exercise 8 to use double instead of int. Also, make a vector of doubles containing the N–1
// differences between adjacent values and write out that vector of differences.

#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main(){
    try{
        double numvalues{0}, input{0}, total{0};
        std::vector<double> inputvect, differences;

        std::cout << "Please enter a number of values you want to sum:" << std::endl;
        std::cin >> numvalues;
        std::cout << "Please enter some integer values: (press '|' to stop)" << std::endl;

        while(std::cin >> input){
            inputvect.push_back(input);
        }

        if(inputvect.size()<numvalues) throw std::runtime_error("not enough values entered to be summed."); // performs test to see if vector is in range

        for(int i=0; i < numvalues; i++){
            if(total > std::numeric_limits<double>::max() - inputvect[i]) throw std::runtime_error("total too big for int variable.");
            total += inputvect[i];
        }
        for(int i=1; i < numvalues; i++){
            differences.push_back(inputvect[i]-inputvect[i-1]);
        }

        std::cout << "The sum of the first " << numvalues << " values is:" << std::endl << total << std::endl;
        std::cout << "The differences of the enteries are:" << std::endl;

        for(int i=0; i<differences.size(); i++){
            std::cout << differences[i] << std::endl;    
        }
        
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
