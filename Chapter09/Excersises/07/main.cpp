#include <iostream>
#include "Library.h"

int main(){
    Library::Book the_stand;
    the_stand.change_genre(Library::Genre::nonfiction);

    std::cout << the_stand.genre() << std::endl;

    return 0;
}
