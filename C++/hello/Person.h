#pragma once
#include <string>
using namespace std;

class Person
{
private:
	string fname;
	string lname;
public:
	string getFname();
	void setFname(string fname);
	string getLname();
	void setLname(string lname);
	string toString();
};

