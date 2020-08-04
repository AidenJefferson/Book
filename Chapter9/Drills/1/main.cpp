// This drill simply involves getting the sequence of versions of Date to work. For each version define a Date called today
// initialized to June 25, 1978. Then, define a Date called tomorrow and give it a value by copying today into it and
// increasing its day by one using add_day(). Finally, output today and tomorrow using a << defined as in §9.8.
// Your check for a valid date may be very simple. Feel free to ignore leap years. However, don’t accept a month that is not in
// the [1,12] range or day of the month that is not in the [1,31] range. Test each version with at least one invalid date 
// (e.g., 2004, 13, –5).
//
// 1. The version from §9.4.1

#include "Chrono.h"

int main(){
    Chrono::Date today{25,Chrono::Month::jun,1978}; // a Date variable;
    Chrono::Date tomorrow = today;

    tomorrow.add_day(1);
    std::cout << tomorrow << std::endl;

    tomorrow.add_day(4);
    std::cout << tomorrow << std::endl;
    
    tomorrow.add_month(8);
    std::cout << tomorrow << std::endl;

    tomorrow.add_year(2);
    std::cout << tomorrow << std::endl;
    
    return 0;
}

