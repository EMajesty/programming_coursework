// tehtava2c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Anna luku väliltä 0-9\n";
    cin >> input;

    switch (input)
    {
    case 0:
        cout << "0";
        break;
    case 1:
        cout << "1";
        break;
    case 2:
        cout << "2";
        break;
    case 3:
        cout << "3";
        break;
    case 4:
        cout << "4";
        break;
    case 5:
        cout << "5";
        break;
    case 6:
        cout << "6";
        break;
    case 7:
        cout << "7";
        break;
    case 8:
        cout << "8";
        break;
    case 9:
        cout << "9";
        break;
    }
}