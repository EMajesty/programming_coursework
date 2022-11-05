// tehtava2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    cout << "Anna luku\n";
    cin >> a;
    cout << "Anna toinen luku\n";
    cin >> b;

    if (a >= b * 10)
    {
        cout << "Annoitpa ison luvun a\n";
    }
    else {
        cout << "Aikalailla samansuuruiset luvut\n";
    }
}