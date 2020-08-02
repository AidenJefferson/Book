// Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
// The first reverse function should produce a new vector with the reversed sequence, leaving its original vector
// unchanged. The other reverse function should reverse the elements of its vector without using any other vectors (hint:
// swap).

#include <iostream>
#include <vector>

void print(std::string label, std::vector<int>& vals){
    std::cout << label << ": " << std::endl;

    for(int i=0; i < vals.size(); i++){
        std::cout << vals[i];
        if(i != vals.size()-1)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

void new_reverse(const std::vector<int>& original, std::vector<int>& newv){
    for(int i=0; i < original.size(); i++){
        newv.push_back(original[original.size()-1-i]);
    }
}

void orig_reverse(std::vector<int>& original){
    int placehold{0};

    for(int i=0; i < original.size()/2; i++){
        placehold = original[i];
        original[i] = original[original.size()-1-i];
        original[original.size()-1-i] = placehold;
    }
}

int main(){
    std::vector<int> test{1,2,3,4,5}, newvect;

    new_reverse(test, newvect);
    print("original",test);
    print("Reversed-copy", newvect);

    orig_reverse(test);
    print("Reversed-original",test);

    return 0;
}
