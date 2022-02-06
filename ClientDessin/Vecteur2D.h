#pragma once
#include "Point.h"
class Vecteur2D
{

public:
	Point x;
	Point y;
	Vecteur2D(const Point& x1, const Point& y1) : x(x1), y(y1) {
	}
	const Vecteur2D operator + (const Vecteur2D& u) const {
		
		return Vecteur2D(x.x + u.x.x, y.x + u.y.x);

	}
	const Vecteur2D operator * (const double& a) const {
		return Vecteur2D(x.x * a, y.x * a);
	}
	const Vecteur2D operator - () const {
		return Vecteur2D(-x.x, -y.x);

	}
	string  toString() const {
		string s;
		s = "vecteur2D : x= " + to_string(x.x) + " y= " + to_string(y.x);
		return s;
	}

};

inline ostream& operator<<(ostream& s, const Vecteur2D& v) {
	return s << v.toString();
}