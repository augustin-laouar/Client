#pragma once
class Point
{
public:
	double x; // coordonnées en public car pas besoin de verification 
	double y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point(const Point* p) {
		this->x = p->x;
		this->y = p->y;
	}
	Point* clone()const {
		return new Point(this);
	}

};

