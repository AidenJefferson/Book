// Improve print_until_s() from §8.5.2. Test it. What makes a good set of test cases? Give reasons. Then, write a
// print_until_ss() that prints until it sees a second occurrence of its quit argument.

#include <iostream>
#include <string>
#include <vector>

void print_until_s(const std::vector<std::string>& v, const std::string quit){
    for(std::string s : v) {
        if (s == "quit") return;
        std::cout << s << '\n';
    }
}

void print_until_ss(const std::vector<std::string>& v, const std::string quit){
    bool first{false};
    for(std::string s : v) {
        if(s == "quit" && first == true) return;
        if (s == "quit") first = true;
        else std::cout << s << '\n';
    }
}

int main(){
    try{
        std::vector<std::string> inputs;

        std::cout << "Please input a series of strings" << std::endl;
        for(std::string input; std::cin >> input;){
            if(!std::cin) throw std::runtime_error("input invalid.");
            inputs.push_back(input);
        }
        
        std::cout << "until s: " << std::endl;
        print_until_s(inputs, "quit");
        std::cout << "\nunit ss: " << std::endl;
        print_until_ss(inputs, "quit");
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
