// Quadratic equations are of the form
//
//          a·x^2 + b·x + c = 0
//
// To solve these, one uses the quadratic formula.There is a problem, though.
// If b2–4ac is less than zero, then it will fail. Write a program that can calculate x for a quadratic equation. 
// Create a function that prints out the roots of a quadratic equation, given a, b, c. When the program detects 
// an equation with no real roots, have it print out a message. How do you know that your results are plausible? 
// Can you check that they are correct?

#include <iostream>
#include <cmath>
#include <string>

void error(std::string s);
void quadratic(double A, double B, double C, double& X1, double& X2);

int main(){
    try{
        double a{0},b{0},c{0},x1{0},x2{0}; // quadratic variables and answers
        
        std::cout << "This program will solve a quadratic equation in the form of ax^2 + bx + c." << std::endl
        << "Please enter the values of a, b and c. (this program will not compute complex roots)." << std::endl;
        std::cin >> a >> b >> c; // storing of variables given

        quadratic(a,b,c,x1,x2); // solve the quadratic

        std::cout << "The solution to " << a << "x^2 + " << b << "x + " << c << " is:" << std::endl;
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;

        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Error: unknown." << std::endl;
        return 2;
    }
}

void error(std::string s){
    throw std::runtime_error(s);
}

void quadratic(double A, double B, double C, double& X1, double& X2){
    double root{B*B-4*A*C};
    
    if(root < 0) error("complex roots found.");
    X1 = (-B + sqrt(root))/2;
    X2 = (-B - sqrt(root))/2;
} 
