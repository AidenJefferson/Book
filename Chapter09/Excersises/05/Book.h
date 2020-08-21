// This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
// software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store data
// on whether or not the book is checked out. Create functions for returning those data values. Create functions for checking
// a book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n-n-nx 
// where n is an integer and x is a digit or a letter. Store an ISBN as a string.

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
