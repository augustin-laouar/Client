#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;
class Vecteur2D
{

public:
	double x;
	double y;
	Vecteur2D(double x, double y){
		this->x = x;
		this->y = y;
	}
	const Vecteur2D operator + (const Vecteur2D& u) const {
		return Vecteur2D(x + u.x, y + u.y);

	}
	const Vecteur2D operator * (const double& a) const {
		return Vecteur2D(x * a, y * a);
	}
	const Vecteur2D operator - () const {
		return Vecteur2D(-x, -y);
	}
	string  toString() const {
		string s;
		s = "vecteur2D : x= " + to_string(x) + " y= " + to_string(y);
		return s;
	}
	operator string() const
	{
		return this->toString();
	}

};

inline ostream& operator<<(ostream& s, const Vecteur2D& v) {
	return s << v.toString();
}