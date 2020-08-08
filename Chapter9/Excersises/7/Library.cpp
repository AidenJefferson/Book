#include "Library.h"
#include <cctype>

namespace Library{

Book::Book()
    : ISBN{"n-n-nx"}, Title{"Title"}, Author{"Author"}, Copyright_Date{1,Chrono::Month::jan,2000}, Checked_Out{false}, Gen{Genre::fiction}
{
}

Book::Book(std::string isbn, std::string t, std::string a, Chrono::Date cd, bool out, Genre g)
    : ISBN{"n-n-nx"}, Title{"Title"}, Author{"Author"}, Copyright_Date{1,Chrono::Month::jan,2000}, Checked_Out{false}, Gen{Genre::fiction}
{
    this->change_isbn(isbn);
    this->change_title(t);
    this->change_author(a);
    this->change_date(cd);
    this->change_genre(g);
    this->Checked_Out = out;
}

std::string Book::genre() const{
    std::string genre;
    switch(int(this->Gen)){
        case 0:
            genre = "fiction";
            break;
        case 1:
            genre = "non-fiction";
            break;
        case 2:
            genre = "periodical";
            break;
        case 3:
            genre = "biography";
            break;
        case 4:
            genre = "children";
            break;
    }

    return genre;
}

void Book::change_isbn(std::string isbn){
    static const int ISBN_length = 6;
    int correct{0};

    if(isbn.length() != ISBN_length){
        this->incorrect_isbn();
        return;
    }    
    for(int i=0; i < ISBN_length; i++){
        switch(i){
            case 0: case 2: case 4:
            correct = (isdigit(isbn[i]))? correct+1 : correct;
            break;
            case 1: case 3:
            correct = (isbn[i] == '-')? correct+1 : correct;
            break;
            case 5:
            correct = (isalpha(isbn[i]))? correct+1 : correct;
            break;
        }
    }
    
    if(correct != 6) this->incorrect_isbn();
    return;
}

void Book::change_title(std::string t){
    this->Title = t;
}

void Book::change_author(std::string a){
    this->Author = a;
}

void Book::change_date(Chrono::Date& cd){
    this->Copyright_Date = cd;
}

void Book::check_in(){
    if(this->Checked_Out = false){
        throw Invalid{};
    }
    this->Checked_Out = false;
}

void Book::change_genre(Genre g){
    this->Gen = g;
}

void Book::check_out(){
    if(this->Checked_Out = true){
        throw Invalid{};
    }
    this->Checked_Out = true;
}

void Book::incorrect_isbn(){
    char input{' '};
    std::string isbn;
    int correct{0};

    std::cout << "Oops, you incorrectly entered that ISBN, please re-try. (ISBN example: 0-0-0A)" << std::endl;
    static const int ISBN_length = 6;
    
    for(int i=0; i < ISBN_length; i++){
        std::cin >> input;
        switch(i){
            case 0: case 2: case 4:
                if(isdigit(input)){
                    isbn += input;
                    correct++;
                }
            break;
            case 1: case 3:
                if(input == '-'){
                    isbn += input;
                    correct++;
                } 
            break;
            case 5:
            if(isalpha(input)){
                isbn += input;
                correct++;
            }
            break;
        }
    }

    if(correct != 6) this->incorrect_isbn();
    else this->ISBN = isbn;
}

std::ostream& operator<<(std::ostream& os, Book& b){
    os << "Book Details:" << std::endl 
        << b.title() << std::endl 
        << b.author() << std::endl
        << b.isbn() << std::endl;

    return os;
}

bool operator==(Book& b1, Book& b2){
    return b1.isbn() == b2.isbn();
}

bool operator!=(Book&b1, Book&b2){
    return !(b1 == b2);
}

} // end of namepace Library
