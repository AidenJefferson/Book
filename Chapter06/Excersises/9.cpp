// Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and
// 3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value.
// Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5' subtract '0',
// that is, '5'–'0'==5.

#include <iostream>
#include <vector>

void error(std::string s){
    throw std::runtime_error(s);
}

void numtosentence(std::vector<char>& v){
    int number{0};

    switch(v.size()){
        case 1:
            number += v[0] - '0';
            std::cout << number << " is " << v[0] << "ones" << std::endl;
            break;
        case 2:
            number += (v[0] - '0')*10;
            number += (v[1] - '0');
            std::cout << number << " is " << v[0] << " tens and " << v[1] << " ones." << std::endl;
            break;
        case 3:
            number += (v[0] - '0')*100;
            number += (v[1] - '0')*10;
            number += (v[2] - '0');
            std::cout << number << " is " << v[0] << " hundreds and "<< v[1] << " tens and " << v[2] << " ones." << std::endl;
            break;
        case 4:
            number += (v[0] - '0')*1000;
            number += (v[1] - '0')*100;
            number += (v[2] - '0')*10;
            number += (v[3] - '0');
            std::cout << number << " is " << v[0] << " thousands and " << v[1] << " hundreds and "<< v[2] << " tens and " << v[3] << " ones." << std::endl;
            break;
        default:
            break;
    }
}

int main(){
    try{
        std::vector<char> input;

        std::cout << "Please enter up to four digits: (press Ctrl-D to enter)" << std::endl;
        for(char in; std::cin >> in;){
            if(in < '0' || in > '9') error("please enter digits only.");
            input.push_back(in);
        }
        if(input.size() > 4) error("please only enter up to four digits.");

        numtosentence(input);
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cout << "unknown exception!" << std::endl;
        return 2;
    }

}
