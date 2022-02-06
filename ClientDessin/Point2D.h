#pragma once
#include "Point.h"
class Point2D : public Point
{
public : 
	double y;
	Point2D() {
		x = 0;
		y = 0;
	}
	Point2D(double x, double y) {
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
	const Point& operator = (const Point2D& p) {
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
};

