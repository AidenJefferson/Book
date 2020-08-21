#include "Library.h"

namespace Library{

    Transaction::Transaction(Book b, Patron u, Chrono::Date cd)
        : Item{b}, User{u}, Checkout_Date{cd}
    {
    }

    void Library::make_transaction(Book b, Patron p, Chrono::Date d){
        if(fee_owed(p)) throw std::runtime_error("user ows fee");
        b.check_out();
        
        Transaction T{b,p,d};
        this->Transactions.push_back(T);
    }

    void patron_who_owe(std::vector<Patron>& p){
        std::cout << "Current persons who owe:" << std::endl;

        for(int i=0; i<p.size(); i++){
            if(p[i].fees() > 0)
                std::cout << p[i].name() << std::endl;
        }
    }
    
}
