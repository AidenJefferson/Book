// Write a function maxv() that returns the largest element of a vector argument.

#include <iostream>
#include <vector>
#include <string>
#include <limits>

void error(std::string s);
double maxv(const std::vector<double>& v);

int main(){
    try{
        std::vector<double> vector{10,20,30,40};

        double maximum = maxv(vector);

        std::cout << "The maximum value is " << maximum << std::endl;
        return 0;
    }
    catch(std::exception& e){
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown error." << std::endl;
        return 2;
    }
}

void error(std::string s){
    throw std::runtime_error(s);
}

double maxv(const std::vector<double>& v){
    double maxi{std::numeric_limits<double>::min()};
    if(v.size() < 1) error("vector must have entries.");
    if(v.size() == 1) return v[0];
    
    for(int i=0; i<v.size(); i++){
        if(v[i] > maxi)
            maxi = v[i];
    }
    return maxi;
}
