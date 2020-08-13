#include "Book.h"
#include <cctype>

Book::Book()
    : ISBN{"n-n-nx"}, Title{"Title"}, Author{"Author"}, Copyright_Date{1,Chrono::Month::jan,2000}, Checked_Out{false} 
{
}

Book::Book(std::string isbn, std::string t, std::string a, Chrono::Date cd, bool out)
    : ISBN{"n-n-nx"}, Title{"Title"}, Author{"Author"}, Copyright_Date{1,Chrono::Month::jan,2000}, Checked_Out{false}
{
    this->change_isbn(isbn);
    this->change_title(t);
    this->change_author(a);
    this->change_date(cd);
    
    this->Checked_Out = out;
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
