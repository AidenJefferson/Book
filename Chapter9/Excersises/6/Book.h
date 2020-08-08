// Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books.
// Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

#include "Chrono.h"
#include <string>

class Book{
public:
    class Invalid{};

    Book();
    Book(std::string isbn, std::string t, std::string a, Chrono::Date cd, bool out);

    std::string isbn() const {return ISBN;};
    std::string title() const {return Title;};
    std::string author() const {return Author;};
    Chrono::Date date() const {return Copyright_Date;};

    void change_isbn(std::string isbn);
    void change_title(std::string t);
    void change_author(std::string a);
    void change_date(Chrono::Date& cd);
    void check_in();
    void check_out();

private:
    std::string ISBN;
    std::string Title;
    std::string Author;
    Chrono::Date Copyright_Date;
    bool Checked_Out; // true for when book out of library
    void incorrect_isbn(); // for use to fix error in entering data

};

std::ostream& operator<<(std::ostream& os, Book& b);
bool operator==(Book& b1, Book& b2);
bool operator!=(Book& b1, Book& b2);
