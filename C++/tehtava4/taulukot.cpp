#include <iostream>
#include "taulukot.h"

using namespace std;

bool naytto[16][12];


void taulukot::luoTaulukko()
{
	int luvut[10];
	for (int i = 0; i <= 9; i++)
	{
		cout << "Anna luku " << i+1 << endl;
		cin >> luvut[i];
	}

	// Print for debug
	for (int i = 0; i <= 9; i++)
	{
		cout << luvut[i] << endl;
	}
}

void taulukot::kaannaTaulukko()
{
	int taulu[] = { 1,2,3,4,5,6,4,52,4 };
	int n = sizeof(taulu) / sizeof(taulu[0]);

	cout << "Taulukko: ";
	for (int i = 0; i < n; i++)
		cout << taulu[i] << " ";

	reverse(taulu, taulu + n);

	cout << "\nKäännetty taulukko: ";
	for (int i = 0; i < n; i++)
		cout << taulu[i] << " ";
}

void taulukot::setLed(int x, int y, bool val)
{
	naytto[x][y] = val;
}

void taulukot::printLed()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << naytto[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void taulukot::clearLed()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			naytto[i][j] = 0;
		}
	}
}