#include "NamePair.h"

Name_pair::Name_pair()
    : Names{}, Ages{}, Ent{0}
{

}

void Name_pair::read_names(){
    std::cout << "Please enter a series of names (type 'enter' to submit entries.)" << std::endl;
    
    for(std::string name; std::cin >> name;){
        if(!std::cin) throw Invalid{};
        
        if(name == "enter") break;
        Names.push_back(name);
    }
    read_ages(Names.size()); // cannot read names without reading ages too.
    Ent = Names.size();
}

void Name_pair::read_ages(int n){
    if(n < 0) throw Invalid{};
    int age{0};
    std::cout << "\nPlease enter the corresponding age for:" << std::endl;
    
    for(int i=0; i < n; i++){
        std::cout << Names[i] << ": ";
        std::cin >> age;
        if(!std::cin) throw Invalid{};
        if(age < 0 || age > 130) throw Invalid{};
        Ages.push_back(age);
    }
}

void Name_pair::sort(){
    std::vector<std::string> copyN = Names;
    std::vector<int> copyA = Ages;
    std::sort(Names.begin(), Names.end());

    for(int i=0; i < Names.size(); i++)
        for(int j=0; j < Names.size(); j++)
            if(Names[i] == copyN[j])
                Ages[i] = copyA[j];
}

std::ostream& operator<<(std::ostream& os, const Name_pair& np){
    
    if(i==0) os << std::endl;
    for(int i=0; i < np.entries(); i++){
        os << "(" << np.getname(i) << ", " << np.getage(i) << ")" << std::endl;
    }
    return os;
}

bool operator==(const Name_pair& npA,const Name_pair& npB){
    return npA.getnames() == npB.getnames() && npA.getages() == npA.getages();    
}

bool operator!=(const Name_pair& npA, const Name_pair& npB){
    return !(npA==npB);
}
