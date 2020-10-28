// 11. Complete the “list of gods” example from §17.10.1 and run it.

#include <iostream>

class Link { // would go in Link.h & Link.cpp, only here for github
public:
	std::string value;
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value{ v }, prev{ p }, succ{ s } { }
	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase(); // remove this object from list
	Link* find(const std::string& s); // find s in list
	Link* advance(int n); // move n positions in list
	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->succ = this; // this object comes after n
	if (prev) prev->succ = n;
	n->prev = prev; // this object’s predecessor becomes n’s predecessor
	prev = n; // n becomes this object’s predecessor
	return n;
}

Link* Link::add(Link* n) // insert n after this object; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->prev = this; // this object comes before n
	if (succ) succ->prev = n;
	n->succ = succ; // this object’s predecessor becomes n’s successor
	succ = n; // n becomes this object’s successor
	return n;
}

Link* Link::find(const std::string& s) // find s in list;
// return nullptr for “not found”
{
	Link* p = this;

	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) // move n positions in list
// return nullptr for “not found”
// positive n moves forward, negative backward
{
	Link* p = this;

	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}

Link* Link::erase() // remove from list; return successor
{
	if (this == nullptr) return nullptr;
	if (this->succ) this->succ->prev = this->prev;
	if (this->prev) this->prev->succ = this->succ;
	return this->succ;
}

int main() {

	Link* norse_gods = new Link{ "Odin" };
	norse_gods = norse_gods->insert( new Link{"Zeus"} );


	std::cout << norse_gods->advance(1)->value;
	

	return 0;
}