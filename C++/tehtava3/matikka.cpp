#include <iostream>
#include "matikka.h"

using namespace std;

void matikka::tulostaValilta(int a, int b)
{
	for (a; a <= b; a++)
	{
		cout << a << endl;
	}
}

int matikka::laskeSumma(int a, int b)
{
	int summa = a + b;
	return summa;
}