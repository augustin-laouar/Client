#pragma once
#include <string>
#include <iostream>
using namespace std;
class Point2D 
{
public : 
	double x;
	double y;
	Point2D(double x=0, double y=0) {
		this->x = x;
		this->y = y;
	}
	Point2D(const Point2D& p) {
		this->x = p.x;
		this->y = p.y;
	}
	Point2D* clone()const {
		return new Point2D(*this);
	}
	const Point2D& operator = (const Point2D& p) {
		if (this == &p) {
			return *this;
		}
		this->x = p.x;
		this->y = p.y;
		return *this;
	}
	bool operator == (const Point2D& p)const {
		if (this->x == p.x && this->y == p.y) {
			return true;
		}
		else {
			return false;
		}
	}
	 virtual string toString()const {
		return " Point2D : ( " + to_string(x) + " , " + to_string(y) +" )";
	}
	 operator string() const
	 {
		 return this->toString();
	 }
};
inline ostream& operator<<(ostream& s, const Point2D& p) {
	return s << p.toString();
}

