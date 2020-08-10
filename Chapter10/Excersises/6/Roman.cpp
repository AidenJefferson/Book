#include "Roman.h"
#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<char> valid_numerals{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

Roman_int::Roman_int(std::string s)
    : numeral{s} 
{
    if(!is_valid(s)) throw std::runtime_error("invalid numeral given");
};

void Roman_int::set_numeral(std::string s){
    if(!is_valid(s)) throw std::runtime_error("invalid numeral set");
    this->numeral = s;
}

int Roman_int::as_int(){
    std::vector<char> numers;
    std::vector<int> values;
    int sum{0};

    for(int i=0; i < this->numeral.size(); i++){
        numers.push_back(numeral[i]);
    }
    for(int i=0; i < numers.size(); i++){
        switch(numers[i]){
            case 'I':
                values.push_back(1);
                break;
            case 'V':
                values.push_back(5);
                break;
            case 'X':
                values.push_back(10);
                break;
            case 'L':
                values.push_back(50);
                break;
            case 'C':
                values.push_back(100);
                break;
            case 'D':
                values.push_back(500);
                break;
            case 'M':
                values.push_back(1000);
                break;
        }
    }
    for(int i=0; i < values.size(); i++){
        if(values[i] == 0){
        }
        else if(values[i] >= values[i+1] || values[i] == values.size()-1){
            sum += values[i];
        }
        else{
            sum += values[i+1] - values[i];
            values[i+1] = 0; // ensures that the next value is skipped as it is already used.
        }
    }

    return sum;
}

bool is_valid(std::string s){
    int counter{0};
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<valid_numerals.size(); j++){
            if(s[i] == valid_numerals[j])
                counter++;
        }
    }
    if(counter == s.size()) return true;
    return false;
}
