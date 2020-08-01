// The following program takes in a temperature value in Celsius and converts it to Kelvin. This code has many errors in it.
// Find the errors, list them, and correct the code.
// double ctok(double c) // converts Celsius to Kelvin
// {
//     int k = c + 273.15;
//     return int
// }
// int main()
// {
//     double c = 0; // declare input variable
//     cin >> d; // retrieve temperature to input variable
//     double k = ctok("c"); // convert temperature
//     Cout << k << '/n' ; // print out temperature
// }


#include <iostream>

double ctock(double c){ // converts Celcius to Kelvin
    double k = c + 273.15;
    return k;
} 
int main(){
    double c{0}; // declare input variable
    std::cin >> c; // retrieve temperature to input variable
    double k = ctock(c); // convert temperature
    std::cout << k << '\n'; // print out temerature
}
