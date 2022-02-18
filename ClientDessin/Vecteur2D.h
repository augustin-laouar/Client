#pragma once
#include "Point2D.h"
#include <string>
#include <iostream>
#include <ostream>
using namespace std;
/** 
*@class Représentation mathématique d'un vecteur en 2D
*                                                                                   -->
*                                                                                  | x |
* on représente un vecteur non pas avec ses 2 points, mais avec la notation :      | y |
*/

class Vecteur2D
{

public:
	double x;
	double y;
	//construction directement avec les coordonnées s
	Vecteur2D(double x = 0, double y = 0){ 
		this->x = x;
		this->y = y;
	}
	Vecteur2D(const Vecteur2D& v) {
		this->x = v.x;
		this->y = v.y;
	}
	//construction directement avec les 2 points du vecteur
	//methodes
	double determinant(const Vecteur2D& v) const {
		return x * v.y - y * v.x;
	}
	double norme()const {
		return sqrt(x*x + y*y);
	}
	double produitScalaire(const Vecteur2D& v)const {
		return x * v.y + y * v.x;
	}
	void translation(const Vecteur2D&);
	Vecteur2D translation(const Vecteur2D&)const;

	//toString clone et operator
	Vecteur2D* clone()const {
		return new Vecteur2D(*this);
	}
	string  toString() const {
		string s = "VECTEUR 2D : \n";
		s += "( " + to_string(x) + " ) \n( " + to_string(y) + " )";
		return s;
	}
	const Vecteur2D operator + (const Vecteur2D& u) const {
		return Vecteur2D(x + u.x, y + u.y);

	}
	const Vecteur2D operator - (const Vecteur2D& u) const {
		return (*this) + - u;

	}
	const Vecteur2D operator * (const double& a) const {
		return Vecteur2D(x * a, y * a);
	}
	const Vecteur2D operator - () const {
		return Vecteur2D(-x, -y);
	}
	operator string() const
	{
		return this->toString();
	}
	virtual bool operator ==(const Vecteur2D& v)const {
		if (x == v.x && y == v.y) {
			return true;
		}
		return false;
	}
};

inline ostream& operator<<(ostream& s, const Vecteur2D& v) {
	return s << v.toString();
}