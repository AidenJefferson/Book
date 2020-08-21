#include "Chrono.h"

namespace Chrono {

Date::Date(int day, Month month, int year)
    : d{day}, m{month}, y{year} 
{
    if(!is_date(day, month, year)) throw Invalid{};
}

Date::Date()
    : d{1}, m{Month::jan}, y{2000} 
{

}

void Date::add_day(int num){
    if(num < 1) return;
    
    int days_in_month{1};

    for(int i=0; i < num; i++){
        switch(m){
            case Month::sep: case Month::apr: 
            case Month::jun: case Month::nov:
                days_in_month = 30;
                if(d == days_in_month){
                    d = 1;
                    add_month(1);
                }
                else d+=1;
                break;
            case Month::feb:
                days_in_month = (leap_year(y))? 29 : 28;
                if(d == days_in_month){
                    d = 1;
                    add_month(1);
                }
                else d+=1;    
                break;
            default:
                days_in_month = 31;
                if(d == days_in_month){
                    d = 1;
                    add_month(1);
                }
                else d+=1;
                break;
        }
    }
}

void Date::add_month(int num){
    if(num < 1) return;

    int days_in_month{31};

    for(int i=0; i < num; i++){
        if(m == Month::dec){
            m = Month::jan;
            add_year(1);
        }
        else m = Month(int(m)+1);;

        switch(m){
            case Month::sep: case Month::apr: 
            case Month::jun: case Month::nov:
                days_in_month = 30;
                d = (d > days_in_month)? days_in_month : d;
                break;
            case Month::feb:
                days_in_month = (leap_year(y))? 29 : 28;
                d = (d > days_in_month)? days_in_month : d;
                break;
            default:
                d = (d > days_in_month)? days_in_month : d;
                break;
        }
    }
}

void Date::add_year(int num){
    if(m == Month::feb && d == 29 && leap_year(y+num)){
        m = Month::mar;
        d = 1;
    }
    y += num;
}


bool is_date(int day, Month month, int year){

    if(month < Month::jan || month > Month::dec) return false;

    int days_in_month{31};

    switch(month){
        case Month::sep: case Month::apr: case Month::jun: case Month::nov:
            days_in_month = 30;
            break;
        case Month::feb:
            days_in_month = (leap_year(year))? 29 : 28;
            break;
    }

    if(day<0 || day > days_in_month) return false;

    return true;
}

bool leap_year(int year){
    return (year%4 == 0)? true : false;
}

bool operator==(const Date& a, const Date& b){
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year()
        << ',' << int(d.month())
        << ',' << d.day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is) return is;
    if(ch1!= '(' || ch2!=',' || ch3!=',' || ch4!=')'){ // oops: format error
        is.clear(std::ios_base::failbit); // set the fail bit
        return is;
    }
    dd = Date(y,Month(m),d); // update dd
    return is;
}

} // end of namespace Chrono
