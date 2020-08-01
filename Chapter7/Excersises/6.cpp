// Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1. Assume that every
// sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but the fish swim . is a
// sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim. (no space
// before dot) are not. For each sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t bother
// with tokens; just read into a string using >>.

/* Grammer to be used:
 *
 * Sentence:
 *     Noun Verb // e.g., C++ rules
 *     Article Noun Verb   // e.g., The birds fly
 *     Sentence Conjunction Sentence // e.g., Birds fly but fish swim
 * Conjunction:
 *     "and"
 *     "or"
 *     "but"
 * Article:
 *     "the"
 * Noun:
 *     "birds"
 *     "fish"
 *     "C++"
 * Verb:
 *     "rules"
 *     "fly"
 *     "swim"
 */

// NOTE: use calculator00.cpp

#include <iostream>
#include <string>

int main(){
    try{
         
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error found." << std::endl;
        return 2;
    }
}
