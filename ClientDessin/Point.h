#pragma once
#include <string>
#include <iostream>
using namespace std;
class Point // Point dans un repere a une dimention
{
public:
	double x; // coordonnées en public car pas besoin de verification 
	Point() {
		this->x = 0;
	}
	Point(double x) {
		this->x = x;
	}
	Point(const Point* p) {
		this->x = p->x;
	}
	Point* clone()const {
		return new Point(this);
	}
	virtual const Point& operator = (const Point& p) {
		if (this == &p) {
			return *this;
		}
		this->x = p.x;
		return *this;
	}
	virtual bool operator == (const Point& p)const {
		if (this->x == p.x) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual string toString()const {
		return "Point : ( " + to_string(x)+" )";
	}
};
inline ostream& operator<<(ostream& s, const Point& p) {
	return s << p.toString();
}

/*Operator a ajouter :
* 
*/