#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Name_pair{
    public:
    Name_pair();
    class Invalid{};
    void read_names(); 
    void print() const;
    void sort();

    private:
    void read_ages(int n); // n used to input how many new entries required.
    std::vector<std::string> Names;
    std::vector<int> Ages;
};
