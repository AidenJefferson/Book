#include <iostream>
#include "Library.h"

int main(){
    Library::Library mylibrary{};
    Library::Patron Aiden{"Aiden", 1, 0};
    Chrono::Date today{6, Chrono::Month::aug, 2020};

    Library::Book The_Stand{"2-3-2A", "The Stand", "Stephen King", today , true, Library::Genre::fiction};

    mylibrary.add_patron(Aiden);
    mylibrary.add_book(The_Stand);

    mylibrary.make_transaction(The_Stand, Aiden, today);

}
