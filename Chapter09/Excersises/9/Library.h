// Create a Library class. Include vectors of Books and Patrons. Include a struct called Transaction. Have it include a
// Book, a Patron, and a Date from the chapter. Make a vector of Transactions. Create functions to add books to the
// library, add patrons to the library, and check out books. Whenever a user checks out a book, have the library make sure
// that both the user and the book are in the library. If they aren’t, report an error. Then check to make sure that the user
// owes no fees. If the user does, report an error. If not, create a Transaction, and place it in the vector of Transactions.
// Also write a function that will return a vector that contains the names of all Patrons who owe fees

#include "Book.h"
#include "Patron.h" // other classes in Library namespace
#include <vector>

namespace Library{

    struct Transaction{
        Transaction(Book b, Patron u, Chrono::Date cd);
        Book Item;
        Patron User;
        Chrono::Date Checkout_Date;  
    };

    class Library{
        public:
        Library()
            : Books{}, Patrons{}, Transactions{} {};

        std::vector<Patron> patrons() const {return Patrons;};
        std::vector<Book> books() const {return Books;};
        std::vector<Transaction> transactions() const {return Transactions;};

        void add_patron(Patron p) {this->Patrons.push_back(p);};
        void add_book(Book b) {this->Books.push_back(b);};
        void make_transaction(Book b, Patron p, Chrono::Date d);

        private:
        std::vector<Book> Books;
        std::vector<Patron> Patrons;
        std::vector<Transaction> Transactions;
    };
    
    void patrons_who_owe(std::vector<Patron>& p);

}
