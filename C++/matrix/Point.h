#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0);
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x) { this->x = (x >= 0 ? x : 0); }
	void setY(int y) { this->y = (y >= 0 ? y : 0); }

};
// "inline" --> can be implemented in header file
inline bool operator<(const Point& a, const Point& b) {
	// if we didn't accept big x and y values, this would work:
	//int aref = a.getX() * 1000 + a.getY();
	//int bref = b.getX() * 1000 + b.getY();
	//return aref < bref;

	// this works with any values:
	if (a.getX() < b.getX()) return true;
	if (a.getX() == b.getX()) {
		if (a.getY() < b.getY()) return true;
	}
	return false;
}
