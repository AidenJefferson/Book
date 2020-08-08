// Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
// biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
// functions.

#include "Chrono.h"
#include <string>

namespace Library{

enum class Genre{
    fiction = 0, nonfiction, periodical, biography, children
};

class Book{
public:
    class Invalid{};

    Book();
    Book(std::string isbn, std::string t, std::string a, Chrono::Date cd, bool out, Genre g);

    std::string isbn() const {return ISBN;};
    std::string title() const {return Title;};
    std::string author() const {return Author;};
    Chrono::Date date() const {return Copyright_Date;};
    std::string genre() const;

    void change_isbn(std::string isbn);
    void change_title(std::string t);
    void change_author(std::string a);
    void change_date(Chrono::Date& cd);
    void change_genre(Genre g);
    void check_in();
    void check_out();

private:
    std::string ISBN;
    std::string Title;
    std::string Author;
    Genre Gen;
    Chrono::Date Copyright_Date;
    bool Checked_Out; // true for when book out of library
    void incorrect_isbn(); // for use to fix error in entering data

};

std::ostream& operator<<(std::ostream& os, Book& b);
bool operator==(Book& b1, Book& b2);
bool operator!=(Book& b1, Book& b2);

} 
