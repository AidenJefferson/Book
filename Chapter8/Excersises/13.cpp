// Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters
// in each string. Also find the longest and the shortest string and the lexicographically first and last string. How many
// separate functions would you use for these tasks? Why?

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

std::vector<int> vec_length(const std::vector<std::string>& v){ // creates vector of lengths of strings
    std::vector<int> lengths;
    if(v.size() < 1) throw std::runtime_error("vector has no entries.");
    for(int i=0; i < v.size(); i++)
        lengths.push_back(v[i].size());
    return lengths;
}

std::string vec_short(const std::vector<std::string>& vstring, const std::vector<int>& vint){ // finds shortest string in a vector
    int small{INT_MAX}, index{0};
    if(vstring.size() != vint.size()) throw std::runtime_error("vectors dont match");
    for(int i=0; i < vstring.size(); i++){
        if(vint[i] < small){
            small = vint[i];
            index = i;
        }
    }
    return vstring[index];
}
std::string vec_long(const std::vector<std::string>& vstring, const std::vector<int>& vint){ // finds longest string in a vector
    int large{INT_MIN}, index{0};
    if(vstring.size() != vint.size()) throw std::runtime_error("vectors dont match");
    for(int i=0; i < vstring.size(); i++){
        if(vint[i] > large){
            large = vint[i];
            index = i;
        }
    }
    return vstring[index];
}
void vec_lexicog(std::vector<std::string>& vstring, std::vector<int>& vint){
    if(vstring.size() != vint.size()) throw std::runtime_error("vectors dont match");

    std::vector<std::string> vstringcopy = vstring;
    std::vector<int> vintcopy = vint;
    std::sort(vstring.begin(), vstring.end());
    for(int i=0; i < vstring.size(); i++){
        for(int j=0; j<vstring.size(); j++){
            if(vstring[i] == vstringcopy[j])
                vint[i] = vintcopy[j];
        }
    }
}

std::string lexi_first(std::vector<std::string>& vstring, std::vector<int>& vint){
    vec_lexicog(vstring, vint);
    return vstring[0];
}
std::string lexi_last(std::vector<std::string>& vstring, std::vector<int>& vint){
    vec_lexicog(vstring, vint);
    return vstring[vstring.size()-1];
}

int main(){
    try{
        std::vector<std::string> inputs;
        std::vector<int> lengths;
        std::string smallest, longest, lexifirst, lexilast;

        std::cout << "Please enter a series of strings:" << std::endl;
        for(std::string input; std::cin >> input;){
            if(!std::cin) throw std::runtime_error("invalid entry");
            inputs.push_back(input);
        }
        
        lengths = vec_length(inputs);
        smallest = vec_short(inputs, lengths);
        longest = vec_long(inputs, lengths);
        lexifirst = lexi_first(inputs, lengths);
        lexilast = lexi_last(inputs, lengths);
        
        std::cout << "Longest string: " << longest << std::endl
                << "Smallest string: " << smallest << std::endl
                << "First (alphabetical): " << lexifirst << std::endl  
                << "Last (alphabetical): " << lexilast << std::endl;

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
