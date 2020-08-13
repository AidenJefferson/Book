#include <iostream>

namespace Chrono{

enum class Month{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

struct Date {

public:
    class Invalid{};

    Date(int day, Month month, int year);
    Date();

    int day() const {return d;};
    Month month() const {return m;}
    int year() const {return y;};

    void add_day(int num);
    void add_month(int num);
    void add_year(int num);

private:
    int d; // day of month
    Month m; // month in year
    int y; // year
};

bool is_date(int day, Month month, int year);
bool leap_year(int year);

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& dd);

}
