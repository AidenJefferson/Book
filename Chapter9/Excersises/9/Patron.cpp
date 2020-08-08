#include "Patron.h"
#include <iostream>

namespace Library{

    Patron::Patron()
        : Name{"Name"}, Card_Number{0}, Fees{0}
    {
    }
    
    Patron::Patron(std::string n, int cn, double f)
        : Name{n}, Card_Number{cn}, Fees{f}
    {
    }

    void Patron::set_fee(double fee){
        this->Fees = fee;
    }

    bool fee_owed(Patron& p){
        bool check = (p.fees()>0)? true : false;

        return check;
    }
    
    std::ostream& operator<<(std::ostream& os, Patron& p){
        os << "Patron Details:" << std::endl
            << p.name() << std::endl
            << p.card_number() << std::endl
            << p.fees() << std::endl;

        return os;
    }
} // end of namespace Library
