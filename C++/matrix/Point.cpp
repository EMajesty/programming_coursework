#include "Point.h"

Point::Point(int x, int y)
// if no member validation needed we accept all x and y values
// --> we can set the values in init list.. but we accept coords >=0
//	: x(x), y(y)	
{
	setX(x);
	setY(y);
}

// This definition is not needed since we implemented it as "inline"
//bool operator<(const Point& a, const Point& b)
//{
//	return false;
//}
