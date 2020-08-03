// Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of
// all price[i]*weight[i]. Make sure to have weight.size()==price.size().

#include <iostream>
#include <vector>
#include <string>

void error(std::string s);
double vectindex(const std::vector<double>& price, const std::vector<double>& weight);

int main(){
    try{
        double index{0};
        std::vector<double> price{10,20,30,40}, weight{1,2,3,4};

        index = vectindex(price, weight);
        std::cout << "The index was " << index << std::endl;
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

double vectindex(const std::vector<double>& price, const std::vector<double>& weight){
    double ind{0};
    if(price.size() != weight.size()) error("vectors must match in size.");
    for(int i=0; i<weight.size(); i++)
        ind += price[i]*weight[i];
    return ind;
}
