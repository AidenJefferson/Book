// Add the article the to the “English” grammar in §6.4.1, so that it can describe sentences such as “The birds fly but the
// fish swim.”

/* Old grammer reads as:
 *
 * Sentence:
 *     Noun Verb // e.g., C++ rules
 *     Sentence Conjunction Sentence // e.g., Birds fly but fish swim
 * Conjunction:
 *     "and"
 *     "or"
 *     "but"
 * Noun:
 *     "birds"
 *     "fish"
 *     "C++"
 * Verb:
 *     "rules"
 *     "fly"
 *     "swim"
 */

Sentence:
    Noun Verb // e.g., C++ rules
    Article Noun Verb   // e.g., The birds fly
    Sentence Conjunction Sentence // e.g., Birds fly but fish swim
Conjunction:
    "and"
    "or"
    "but"
Article:
    "the"
Noun:
    "birds"
    "fish"
    "C++"
Verb:
    "rules"
    "fly"
    "swim"
