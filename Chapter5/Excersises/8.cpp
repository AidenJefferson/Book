// Write a program that reads and stores a series of integers and then computes the sum of the first N integers. First ask for
// N, then read the values into a vector, then calculate the sum of the first N values. For example:
// 
//      “Please enter the number of values you want to sum:”
//              3
//      “Please enter some integers (press '|' to stop):”
//              12 23 13 24 15 |
//      “The sum of the first 3 numbers ( 12 23 13 ) is 48.”
// 
// Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than there
// are in the vector.

#include <iostream>
#include <string>
#include <vector>

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
