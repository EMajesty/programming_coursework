#pragma once
#include <map>
using namespace std;
#include "Point.h"
class Matrix
{
private:
	map<Point, int> m;	// default container is created when Matrix obj created
public:
	void set(int x, int y, int value);
	int get(int x, int y);
	void product(int coefficient);
	bool sum(Matrix other);
	int getRowCount();
	int getColCount();
	void print();
};

