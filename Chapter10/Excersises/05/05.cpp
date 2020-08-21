// Write the function print_year() mentioned in §10.11.2.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

constexpr int not_a_reading = -9999; // less than absolute zero
constexpr int not_a_month = -1; 
constexpr int days_in_month = 32;

/*
 * main class structure for memory
 */

struct Day{
    Day()
        : hour(24,not_a_reading){};

    std::vector<double> hour;
};

struct Month{
    Month()
        : month{not_a_month}, day(days_in_month) {}; // wasting the first element 0 to enable easy allocation

    int month; // 0-12 reprsenting Jan-Dec
    std::vector<Day> day;
};

struct Year{
    Year()
        : year{2000}, month(12) {};

    int year;
    std::vector<Month> month;
};

/*
 * reading structure used for input.
 */

struct Reading{
    int day;
    int hour;
    double temperature;
};

/*
 * operator overloading for all above structures
 */

// read temp from istream into reading of format (3 4 9.8). checks format but does not validate entry
std::istream& operator>>(std::istream& is, Reading& r){ 
    char ch1;
    if(is >> ch1 && ch1!='('){ // check for format beginning
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    int d, h; 
    double t;
    char ch2;
    is >> d >> h >> t >> ch2;
    if(!is || ch2!=')') throw std::runtime_error("invalid entry format"); // wrong format, exits out
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

/*
 * forward decloration
 */
    bool is_valid(const Reading& r);
    void end_of_loop(std::istream& is, char end_term, std::string error_message);
    int month_to_int(std::string s);
/* 
 * 
 */

// read month from istrem of format {Month feb (temp)(temp)...}. 
std::istream& operator>>(std::istream& is, Month& m){
    char ch1;
    if(is >> ch1 && ch1!='{'){
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    std::string month_word, month_name; 
    is >> month_word >> month_name;
    if(!is || month_word!="month") throw std::runtime_error("invalid month opener"); // wrong format, exits out
    m.month = month_to_int(month_name);
    int duplicates{0}, invalids{0};
    for(Reading r; is >> r;){
        if(is_valid(r)){
            if(m.day[r.day].hour[r.hour] != not_a_reading)
                duplicates++;
            
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else invalids++;
    }
    if(invalids > 0) throw std::runtime_error("invalid entry in month");
    if(duplicates > 0) throw std::runtime_error("duplicate entry in month");
    end_of_loop(is, '}', "bad end of month");
    return is;
}

// read year from istream of format {Year 2000 {Month ...}}
std::istream& operator>>(std::istream& is, Year y){
    char ch1;
    if(is >> ch1 && ch1!='{'){
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    std::string year_mark;
    int year_value;
    is >> year_mark >> year_value;
    if(!is || year_mark!="year") throw std::runtime_error("invalid year opener"); // wrong format so exit
    y.year = year_value;
    for(Month m; is >> m;){
        y.month[m.month] = m; 
        m = Month{}; // get a clean month every loop
    }
    end_of_loop(is, '}', "bad end of year");
    return is;
}

/*
 * helper functions used throughout
 */

// list of month names
const std::vector<std::string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul",
    "aug", "sep", "oct", "nov", "dec"
};

// converts month to integer value
int month_to_int(std::string s){
    for(int i=0; i<12; ++i) 
        if(month_input_tbl[i]==s) 
            return i;
    
    return -1;
}

const std::vector<std::string> month_print_tbl = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

// converts integer value to month
std::string int_to_month(int i){
    if (i<0 || 12<=i) throw std::runtime_error("bad month index");
    return month_print_tbl[i];
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

// rough test of validity of a reading
bool is_valid(const Reading& r)
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature)
    return false;
    return true;
}

// checks for the end term in the format for Month or Year
void end_of_loop(std::istream& is, char end_term, std::string error_message){
    if(is.fail()){ // use term as terminator and/or separator
        is.clear();
        char ch;
        if(is>>ch && ch==end_term) return; // all is fine
        throw std::runtime_error(error_message);
    }   
}

/*
 * output results to file
 */



std::ostream& operator<<(std::ostream& os, const Month& m){
    os<< "{ " << "month " << int_to_month(m.month) << " ";
    for(int i=1; i<days_in_month; i++){
        for(int j=0; j < 24; j++){
            if(m.day[i].hour[j] != not_a_reading){
                os << "(" << i << " " << j << " " << m.day[i].hour[j] << ")"<< " ";
            }
        }
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Year& y){
    os << "{ " << "year " << y.year << std::endl;
    for(int i=0; i<y.month.size(); i++){
        if(y.month[i].month != not_a_month) // if valid month then print
            os << y.month[i] << std::endl;
    }
    os << "}";
    return os;
}



int main(){
    // open an input file
    std::cout << "Please enter input file name\n";
    std::string iname;
    std::cin >> iname;
    std::ifstream ifs{iname};
    if (!ifs) throw std::runtime_error("can't open input file");
    ifs.exceptions(ifs.exceptions()|std::ios_base::badbit); // throw for bad()
    
    // open an output file:
    std::cout << "Please enter output file name\n";
    std::string oname;
    std::cin >> oname;
    std::ofstream ofs{oname};
    if (!ofs) throw std::runtime_error("can't open output file");
    
    // read an arbitrary number of years:
    std::vector<Year> years;
    for(Year y; ifs >> y;){
        years.push_back(y);
        y = Year{}; // get a freshly initialized Year each time around
    }
    std::cout << "read " << years.size() << " years of readings\n";
    for (Year& y : years) 
        ofs << y;
}
