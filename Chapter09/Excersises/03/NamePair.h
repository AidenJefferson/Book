#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Name_pair{
    public:
    Name_pair();
    
    class Invalid{};
    
    std::string getname(int i) const {return Names[i];};
    int getage(int i) const {return Ages[i];};
    std::vector<std::string> getnames() const {return Names;};
    std::vector<int> getages() const {return Ages;};
    int entries() const {return Ent;};
    
    void read_names(); 
    void sort();
    
    private:
    void read_ages(int n); // n used to input how many new entries required.
    std::vector<std::string> Names;
    std::vector<int> Ages;
    int Ent;
};

std::ostream& operator<<(std::ostream& os, const Name_pair& np);
bool operator==(const Name_pair& npA,const Name_pair& npB);
bool operator!=(const Name_pair& npA, const Name_pair& npB);
