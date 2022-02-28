#pragma once
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
	/**
	* @brief construction directement avec les coordonnées x,y
	*/
	Vecteur2D(double x = 0, double y = 0){ 
		this->x = x;
		this->y = y;
	}
	Vecteur2D(const Vecteur2D& v) {
		this->x = v.x;
		this->y = v.y;
	}
	virtual ~Vecteur2D(){}


	//methodes
	/**
	* @brief calcul du determinant d'un vecteur 
	*/
	double determinant(const Vecteur2D& v) const {
		return x * v.y - y * v.x;
	}
	/**
	* @brief calcul de la norme d'un vecteur 
	*/
	double norme()const {
		return sqrt(x*x + y*y);
	}
	/**
	* @brief produit scalaire
	*/
	double produitScalaire(const Vecteur2D& v)const {
		return x * v.y + y * v.x;
	}
	/**
	* @brief multiplication de deux vecteurs 
	*/
	double operator * (const Vecteur2D& v)const {
		return produitScalaire(v);
	}

	void translation(const Vecteur2D&);
	Vecteur2D translation(const Vecteur2D&)const;

	/**
	* @brief copie d'un vecteur
	*/
	Vecteur2D* clone()const {
		return new Vecteur2D(*this);
	}
	string  toString() const {
		string s = "VECTEUR 2D : ";
		s += " (" + to_string(x) + " , " + to_string(y) + " )";
		return s;
	}
	/**
	* @brief addition de deux vecteurs 
	*/
	const Vecteur2D operator + (const Vecteur2D& u) const {
		return Vecteur2D(x + u.x, y + u.y);

	}
	/**
	* @brief soustraction entre deux vecteurs 
	*/
	const Vecteur2D operator - (const Vecteur2D& u) const {
		return (*this) + - u;

	}
	/**
	* @brief multiplication d'un vecteur et d'un reel 
	*/
	const Vecteur2D operator * (const double& a) const {
		return Vecteur2D(x * a, y * a);
	}

	/**
	* @brief inverse d'un vecteur 
	*/
	const Vecteur2D operator - () const {
		return Vecteur2D(-x, -y);
	}
	operator string() const
	{
		return this->toString();
	}
	/**
	* @brief egalite entre deux vecteurs 
	*/
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
inline Vecteur2D operator * (const double s, const Vecteur2D& v) {
	return v * s;
}