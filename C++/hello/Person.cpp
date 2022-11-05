#include "Person.h"

string Person::getFname()
{
	return string();
}

void Person::setFname(string fname)
{
	// "this" is a pointer to object itself and if we want  to refer the members behind the pointer
	// we have to use arrow (->) operator
	this->fname = fname;
}

string Person::getLname()
{
	return string();
}

void Person::setLname(string lname)
{
	// (*this).lname = lname; // possible but almost never used
	this->lname = lname;
}

string Person::toString()
{
	return getFname() + " " + getLname();
}
