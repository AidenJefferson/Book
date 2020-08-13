// Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the
// median. Do not use global variables. Either return a struct containing the results or pass them back through reference
// arguments. Which of the two ways of returning several result values do you prefer and why?

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct vectData{
    double smallest{0};
    double largest{0};
    double mean{0};
    double median{0};
};

void error(std::string s);
vectData vectCalc(std::vector<double>& v);

int main(){
    try{
        vectData answer;
        std::vector<double> entries;
        std::cout << "Please enter a vector of values. (press Ctrl-D to finish entering)" << std::endl;
        for(double input; std::cin >> input;){
            if(!std::cin) error("invalid entry.");
            entries.push_back(input);
        }

        answer = vectCalc(entries);

        std::cout << "Data from entries:" << std::endl;
        std::cout << "smallest: " << answer.smallest << ", largest: " << answer.largest
            << ", mean: " << answer.mean << ", and meadian: " << answer.median << std::endl;

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

vectData vectCalc(std::vector<double>& v){
    if(v.size() < 1) error("vector needs entries.");
    vectData data;

    std::sort(v.begin(), v.end());
    data.smallest = v[0];
    data.largest = v[v.size()-1];

    for(int i=0; i < v.size(); i++){
        data.mean += v[i];  // generates a total sum not the mean.
    }
    data.mean /= v.size();  // produces mean.

    if(v.size()%2 != 0){
        data.median = v[v.size()/2];
    }
    else{
        data.median = (v[v.size() / 2] + v[v.size() / 2 - 1])/2;
    }

    return data;
}
