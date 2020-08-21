// Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a
// function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number of
// elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where each
// element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . . Your
// fibonacci() function should make such a sequence starting with its x and y arguments.

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
void fibonacci(int x, int y, std::vector<int>& v, int n){
    v.push_back(x);
    v.push_back(y);
    for(int i=1; i<n; i++){
        v.push_back(v[i]+v[i-1]);
    }
}

int main(){
    try{
        std::vector<int> fib;
        std::string label{"Fibonacci"};
        int start{0}, end{0}, resultnum{0};

        std::cout << "Please enter two starting numbers for a Fibonacci sequence aswell as how many results are required." << std::endl;
        std::cin >> start >> end >> resultnum;

        fibonacci(start, end, fib, resultnum);
        print(label, fib);
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
