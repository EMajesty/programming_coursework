#include "osoitin.h"
#include <iostream>

using namespace std;

void osoitin::vaihdaViittauksin(int& a, int& b)
{
	cout << a << endl;
	cout << b << endl;

	int c = a;
	a = b;
	b = c;

	cout << a << endl;
	cout << b << endl;
}

void osoitin::vaihdaOsoittimin(int* a, int* b)
{
	cout << *a << endl;
	cout << *b << endl;

	int* c = a;
	a = b;
	b = c;

	cout << *a << endl;
	cout << *b << endl;
}

void osoitin::tulostaTaulukko(float* ptr)
{
	for (int i = 0; i < 9; i++)
	{
		cout << *ptr << endl;
		++ptr;
	}
}