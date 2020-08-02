// Write versions of the functions from exercise 5, but with a vector<string>.

#include <iostream>
#include <vector>
#include <string>

void print(std::string label, std::vector<std::string>& vect){
    std::cout << label << ": " << std::endl;

    for(int i=0; i < vect.size(); i++){
        std::cout << vect[i];
        if(i != vect.size()-1)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

void new_reverse(const std::vector<std::string>& original, std::vector<std::string>& newv){
    for(int i=0; i < original.size(); i++){
        newv.push_back(original[original.size()-1-i]);
    }
}

void orig_reverse(std::vector<std::string>& original){
    std::string placehold{0};

    for(int i=0; i < original.size()/2; i++){
        placehold = original[i];
        original[i] = original[original.size()-1-i];
        original[original.size()-1-i] = placehold;
    }
}

int main(){
    std::vector<std::string> test{"Excersise","fun","a","is","This"}, newvect;

    new_reverse(test, newvect);
    print("original",test);
    print("Reversed-copy", newvect);

    orig_reverse(test);
    print("Reversed-original",test);

    return 0;
}
