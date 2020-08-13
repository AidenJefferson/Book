// 1.  Start a program called Test_output.cpp. Declare an integer birth_year and assign it the year you were born.
//
// 2.  Output your birth_year in decimal, hexadecimal, and octal form.
//
// 3.  Label each value with the name of the base used.
//
// 4.  Did you line up your output in columns using the tab character? If not, do it.
//
// 5.  Now output your age.
//
// 6.  Was there a problem? What happened? Fix your output to decimal.
//
// 7.  Go back to 2 and cause your output to show the base for each output.
//
// 8.  Try reading as octal, hexadecimal, etc.:
//          cin >> a >>oct >> b >> hex >> c >> d;
//          cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;
//
//          Run this code with the input
//          1234 1234 1234 1234
//          Explain the results.
//
//          RESULT: 1234 668 4660 4660 // This is because it is now using base_8 and base_16
//
// 9.  Write some code to print the number 1234567.89 three times, first using defaultfloat, then fixed, then scientific
//     forms. Which output form presents the user with the most accurate representation? Explain why.
//
// 10. Make a simple table including last name, first name, telephone number, and email address for yourself and at least five
//     of your friends. Experiment with different field widths until you are satisfied that the table is well presented.

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <iomanip>

int main(){
    try{
        int birth_year{1993}, age{27};
        int a{0}, b{0}, c{0}, d{0};
        double output{1234567.89};

        std::cout << "Birth Year:" << std::endl
                << std::showbase 
                << std::dec << birth_year << "\t(Decimal)" << std::endl
                << std::hex << birth_year << "\t(Hexi-decimal)" << std::endl
                << std::oct << birth_year << "\t(Octal)" << std::endl
                << std::endl;
       
        std::cout << "Age:" << std::endl
                << std::dec << age << std::endl
                << std::endl;

        std::cout << "Enter values:" << std::endl;
        std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
        std::cout << a << "\t" << b << "\t" << c << "\t" << d << std::endl
                << std::endl;

        std::cout << "Number 1234567.89" << std::endl
                << std::defaultfloat << output << "\t(Default)" << std::endl
                << std::fixed << output << "\t(Fixed)" << std::endl
                << std::scientific << output << "\t(Scientific)" << std::endl
                << std::endl;

        std::vector<std::string> First_name{"Aiden", "Natalie", "Kaiser", "Reece", "Patch"};
        std::vector<std::string> Last_name{"Jefferson", "Leahy", "Dog", "Jefferson", "Doggo"};
        std::vector<std::string> Number{"0123456789", "0123456788", "0123456754", "01234563212", "1235343553"};
        std::vector<std::string> Email{"Person@gmail.com", "testing@yahoo.co.uk", "Im-not-a-dog@gmail.com", "yesnoyes@test.com", "DOhhhDoubleG@gmail.com"};

        int width{30};
        std::cout << "Data Entered:" << std::endl;
        for(int i=0; i<First_name.size(); i++){
            std::cout << "\t|" << std::setw(width) << Last_name[i] << "|" << std::setw(width) << First_name[i] << "|" << std::setw(width) << Number[i] << "|" << std::setw(width) << Email[i] << "|" << std::endl;
        }

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
