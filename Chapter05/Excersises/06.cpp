// Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius (formula in §4.3.3). Use
// estimation (§5.8) to see if your results are plausible.

// Note: This program was heavily built on previous excersise 5.
#include <iostream>
#include <string>

double tempConvert(double temp, char unit);
void error(std::string s);

int main(){
    try{
        double temp{0}; // declare input variable
        char unit{' '}; // declare unit type (Celsius or Kelvin)

        std::cout << "This program will convert a measurement of Celcius to Fahrenheit or vice-versa." << std::endl
                  << "Please enter a valid temperature followed by the unit (c/f)." << std::endl;          
        std::cin >> temp >> unit; // retrieve temperature & unit variable

        double finaltemp = tempConvert(temp, unit); // convert temperature
        std::cout << finaltemp << std::endl; // print out temerature
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

double tempConvert(double temp, char unit){ // converts Celcius to Fahrenheit

    double conv{0};

    switch(unit){ // allows different outcomes based on unit given
        case 'c': case 'C':
            if(temp < -273.15) error("temperature below abs. zero");
            conv = 9.0/5*temp+32;
            break;
        case 'f': case 'F':
            if(temp < -459.67) error("temperature below abs. zero");
            conv = (temp-32)*5.0/9;
            break;
        default:
            error("incorrect unit of measurement, enter (C)elcius or (K)elvin.");
            break;
    }
    
    return conv;
} 

void error(std::string s){ // throws runtime-error using given string.
    throw std::runtime_error(s);
}
