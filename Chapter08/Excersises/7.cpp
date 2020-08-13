// Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages
// in a vector<double> age. Then print out the five (name[i],age[i]) pairs. Sort the names
// (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs. The tricky part here is to get the age
// vector in the correct order to match the sorted name vector. Hint: Before sorting name, take a copy and use that to
// make a copy of age in the right order after sorting name. Then, do that exercise again but allowing an arbitrary number
// of names.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void error(std::string s){
    throw std::runtime_error(s);
}

void getInfo(std::vector<std::string>& vnames, std::vector<int>& vages){
        int entries{0}, age{0};
        std::string name;

        std::cout << "How many entries would you like to make?" << std::endl;
        std::cin >> entries;
        if(!std::cin || entries < 1){
            error("invalid valid amount of entries entered.");
        }
        std::cout << "Please enter the names of "<< entries << " people." << std::endl;
        for(int i=0; i<entries; i++){
            std::cin >> name;
            vnames.push_back(name);
        }
        std::cout << "Please enter the ages of the " << entries << " people." << std::endl;
        for(int j=0; j < entries; j++){
            std::cin >> age;
            vages.push_back(age);
        }
}

void pairSort(std::vector<std::string>& vnames, std::vector<int>& vages){
    std::vector<std::string> duplicaten = vnames;
    std::vector<int> duplicatea = vages;

    std::sort(vnames.begin(), vnames.end());
    
    for(int i=0; i < vnames.size(); i++){
        for(int j=0; j < vnames.size(); j++){
            if(vnames[i] == duplicaten[j])
                vages[i] = duplicatea[j];
        }
    }
    return;
}

void pairPrint(const std::vector<std::string>& vnames, const std::vector<int>& vages){
    std::cout << "The (name, age) pairs you entered were:" << std::endl;
    for(int i=0; i < vnames.size(); i++)
        std::cout << "(" << vnames[i] << ", " << vages[i] << ")" << std::endl;
}

int main(){
    try{
        std::vector<std::string> names;
        std::vector<int> ages;
       
        getInfo(names, ages);
        pairSort(names, ages);
        pairPrint(names, ages);
        
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown exception." << std::endl;
        return 2;
    }
}
