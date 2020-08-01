// Add to the program so that it can also convert from Kelvin to Celsius.

#include <iostream>
#include <string>

double tempConvert(double temp, char unit);
void error(std::string s);

int main(){
    try{
        double temp{0}; // declare input variable
        char unit{' '}; // declare unit type (Celsius or Kelvin)

        std::cout << "This program will convert a measurement of Celcius to Kelvin or vice-versa." << std::endl
                  << "Please enter a valid temperature followed by the unit (c/k)." << std::endl;          
        std::cin >> temp >> unit; // retrieve temperature & unit variable

        double k = tempConvert(temp, unit); // convert temperature
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

double tempConvert(double temp, char unit){ // converts Celcius to Kelvin

    double conv{0};

    switch(unit){ // allows different outcomes based on unit given
        case 'c': case 'C':
            if(temp < -273.15) error("temperature below abs. zero");
            conv = temp + 273.15;
            break;
        case 'k': case 'K':
            if(temp < 0) error("temperature below abs. zero");
            conv = temp - 273.15;
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
