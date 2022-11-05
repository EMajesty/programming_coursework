// hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// C++ is an oop language containing the whole C-language + OOP + STL

// - Standard i/o including console and file i/o is found in iostream header.
// - Note: no .h extension!
// - Almost all the standard lib functionalities belong to "std" namespace

#include <iostream>
#include <string>
// In C++ you can use also C-functions including standard i/o
#include <stdio.h>
// Like in C: if header is surrounded by quotation marks, precompiler tries to find from project dirs
// If header is surrounded by angle brackets, from compiler include dirs
#include "Person.h"

using namespace std;

int main()
{
    cout << "Hello\nworld from cout object!" << endl;
    printf("Hello from stdio.h()!\n");
    //string name;
    string name("Keijo");
    cout << "name: \"" << name << "\"" << " length: " << name.size() << endl;
    printf("name: \"%s\" length: %d\n", name.c_str(), name.size());

    Person p;
    cout << "Person p: " << p.toString() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
