#include <iostream>
#include "osoitin.h"

using namespace osoitin;
using namespace std;

int main()
{
	int nro1 = 12;
	int nro2 = 23;

	cout << "nro1 = " << nro1 << endl;
	cout << "nro2 = " << nro2 << endl;

	vaihdaViittauksin(nro1,nro2);

	cout << "nro1 = " << nro1 << endl;
	cout << "nro2 = " << nro2 << endl;

	
	
	int* ptr1 = &nro1;
	int* ptr2 = &nro2;

	vaihdaOsoittimin(ptr1, ptr2);

	cout << "nro1 = " << nro1 << endl;
	cout << "nro2 = " << nro2 << endl;



	float arr[] = { 123,234,345,3456,456,5678,678,789,79890 };
	float* ptr = arr;

	tulostaTaulukko(ptr);
}
