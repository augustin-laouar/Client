#pragma once
#include "Point2D.h"
#include <string>
#include <iostream>
#include <ostream>
using namespace std;
/** 
*@class Repr�sentation math�matique d'un vecteur en 2D
*                                                                                   -->
*                                                                                  | x |
* on repr�sente un vecteur non pas avec ses 2 points, mais avec la notation :      | y |
*/

class Vecteur2D
{

public:
	double x;
	double y;
	//construction directement avec les coordonn�es s
	Vecteur2D(double x, double y){ 
		this->x = x;
		this->y = y;
	}
	Vecteur2D(const Vecteur2D& v) {
		this->x = v.x;
		this->y = v.y;
	}
	//construction directement avec les 2 points du vecteur
	Vecteur2D(const Point2D& p1,const  Point2D& p2) { // p1---->p2 ( et pas p2---->p1) � enlever ? 
		x = p2.x - p1.x;
		y = p2.y - p1.y;
	}
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
	virtual const Vecteur2D& operator = (const Vecteur2D& v) {
		if (this == &v) {
			return *this;
		}
		this->x=v.x;
		this->y=v.y;
		return *this;
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