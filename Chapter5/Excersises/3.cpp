// Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The above program, even when
// corrected, will produce erroneous results when given a temperature below this. Place a check in the main program that
// will produce an error if a temperature is given below –273.15°C.

#include <iostream>
#include <string>

double ctock(double c);
void error(std::string s);

int main(){
    try{
        double c{0}; // declare input variable
        std::cin >> c; // retrieve temperature to input variable
        if(c<-273.15) error("temperature below abs. zero.");
        double k = ctock(c); // convert temperature
        std::cout << k << '\n'; // print out temerature
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Error: unknown error found." << std::endl;
        return 2;
    }
}

double ctock(double c){ // converts Celcius to Kelvin
    double k = c + 273.15;
    return k;
} 

void error(std::string s){ // throws runtime-error using given string.
    throw std::runtime_error(s);
}
