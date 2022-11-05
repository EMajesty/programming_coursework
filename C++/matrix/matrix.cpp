// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    // test sequence, a Matrix object should be created and several zero and nonzero
    // values should be added (set()) and print() calls between them ..
    Matrix m;
    Matrix other;
    char menu;
    int coefficient;
    bool loop = true;

    while (loop) {
        cout << "Do you want to:\n\n";
        cout << "Run the (D)efault demo sequence\n";
        cout << "Run the (S)umming demo sequence\n";
        cout << "Run the (P)roduct demo sequence\n\n";
        cout << "        (E)xit?\n\n";

        cout << "Your choice: ";
        cin >> menu;

        switch (menu) {
        case 'D':
            cout << "Default test sequence\n";
            m.set(4, 3, 5);
            m.print();
            m.set(3, 4, 6);
            m.print();
            m.set(4, 3, 0); // note: zero value!
            m.print();
            break;

        case 'S':
            cout << "\nSumming of two matrices\n";
            other.set(1, 2, 3);
            other.set(3, 2, 1);
            other.set(3, 4, 3);

            cout << "\nFirst matrix\n";
            m.print();
            cout << "\nSecond matrix\n";
            other.print();
            m.sum(other);
            cout << "\nSum of matrices\n";
            m.print();
            break;

        case 'P':
            cout << "\nGive an integer to multiply with: ";
            cin >> coefficient;
            m.product(coefficient);
            cout << "\nProduct of coefficient and matrix values\n";
            m.print();
            break;

        case 'E':
            loop = false;
            break;

        default:
            cout << "\nInvalid choice\n";
        }
    }
}
// if offered value == 0 --> no insert, possibly existing should be removed!
void Matrix::set(int x, int y, int value)
{
    Point p(x, y);
    if (value == 0) {
        map<Point, int>::iterator mi = m.find(p);
        // if found --> remove using iterator and return
        m.erase(p);
    }
    else {
        m[p] = value;
    }
    return;
}

// if Point(x,y) found --> return value
// if not --> return 0
int Matrix::get(int x, int y)
{
    Point p(x, y);
    // we shall first check if p/val exists..
    map<Point, int>::iterator mi = m.find(p);
    if (mi == m.end()) return 0;
    int val = m[p]; // val = mi->second; // if iterator used
    return val;
}

void Matrix::product(int coefficient)
{
    // First, it does make sense to check if coefficient is zero..
    if (coefficient == 0) {
        m.clear();
        return;
    }
    // use iterator to read and update values (mi->second *= coefficient). 
    map<Point, int>::iterator mi = m.begin();
    while (mi != m.end()) {
        mi->second *= coefficient;
        mi++;
    }
}

bool Matrix::sum(Matrix other)
{
    // Hints:
    // - use getRowCount() and getColCount() to retrieve the dimensions for both matrices
    //   --> if not equal dimensions (this and other), do nothing and simply return false
    // - according the dimensions create nested for loops where you add values
    //   and update "this" matrix cells. pseudocode: "this->m += other.m"
    // - Use this->get() and other.get() and this->set() !!!
    // - finally return true
    if (this->getColCount() == other.getColCount() && this->getRowCount() == other.getRowCount()) {
        for (int i = 0; i < this->getRowCount(); i++) {
            for (int j = 0; j < this->getColCount(); j++) {
                int val = this->get(j,i) + other.get(j,i);
                this->set(j,i,val);
            }
        }
        return true;
    }

    return false;
}

int Matrix::getColCount()
{
    int maxX = -1;
    map<Point, int>::iterator mi = m.begin();
    while (mi != m.end()) {
        int currX = mi->first.getX();
        if (currX > maxX)
            maxX = currX;
        mi++;
    }
    return maxX+1;
}

// like getColCount() but y..
int Matrix::getRowCount()
{
    int maxY = -1;
    map<Point, int>::iterator mi = m.begin();
    while (mi != m.end()) {
        int currY = mi->first.getY();
        if (currY > maxY)
            maxY = currY;
        mi++;
    }
    return maxY + 1;
}

// hints:
// - two nested for loops
// - use getRowCount() for outer loop and getColCount() for inner loop
// - use get() for values
// - print nice looking output please
void Matrix::print()
{
    cout << "-------begin--------\n";

    for (int i = 0; i < this->getRowCount(); i++) {
        for (int j = 0; j < this->getColCount(); j++) {
            cout << this->get(j, i);
            cout << " ";
        }
        cout << "\n";
    }

    cout << "-------end----------\n\n";
}
