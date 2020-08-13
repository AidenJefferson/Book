// Write a program that writes out the first so many values of the Fibonacci series, that is, the series that starts with 1 1 2 3
// 5 8 13 21 34. The next number of the series is the sum of the two previous ones. Find the largest Fibonacci number that
// fits in an int

#include <iostream>
#include <vector>
#include <climits>

int main(){
    try{
        std::vector<int> fibonacci{1,1};
        int size{0}, current{0};

        std::cout << "This program will print the first N values of the fibonacci series, please enter N:" << std::endl;
        std::cin >> size;

        for(int i=2; i<size; i++){
            if(fibonacci[i-1] > INT_MAX - fibonacci[i-2]){
                std::cout << "The largest Fibonacci number to fit into an int is " << fibonacci[i-1] << std::endl;
                throw std::runtime_error("memory out of space.");
            } 
            fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
        }

        std::cout << "The first " << size << " values are:" << std::endl;
        for(int i=0; i<size; i++){
            std::cout << fibonacci[i] << " ";
        }
        std::cout << std::endl;

        

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown Error." << std::endl;
        return 2;
    }

}
