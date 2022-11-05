// tehtava2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int ika;
    cout << "Kerro ikäsi:\n";
    cin >> ika;

    if (0 < ika && ika < 3)
    {
        cout << "Vauva\n";
    }
    else if (4 < ika && ika < 15)
    {
        cout << "Lapsi\n";
    }
    else if (16 < ika && ika < 18)
    {
        cout << "Teini\n";
    }
    else if (19 < ika && ika < 25)
    {
        cout << "Nuori aikuinen\n";
    }
    else if (ika < 25)
    {
        cout << "Aikuinen\n";
    }
    else
    {
        cout << "Virheellinen ikä\n";
    }
}