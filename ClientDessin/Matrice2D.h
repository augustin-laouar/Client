#pragma once
#include "Erreur.h"
#include "Vecteur2D.h"
#include <vector>
class Matrice2D
{
public:
	double x1;
	double y1;
	double x2;
	double y2;
	//constructeurs
	Matrice2D(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	Matrice2D(const Matrice2D& m) {
		this->x1 = m.x1;
		this->y1 = m.y1;
		this->x2 = m.x2;
		this->y2 = m.y2;
	}
	virtual ~Matrice2D(){}
	//getters setters

	//Methodes

	//toString clone et operator
	string toString()const;
	Matrice2D* clone()const {
		return new Matrice2D(*this);
	}
	virtual bool operator == (const Matrice2D& m)const;
	operator string() const
	{
		return this->toString();
	}
	Matrice2D operator +(const Matrice2D&)const;
	Matrice2D operator -(const Matrice2D&)const;
	Matrice2D operator *(const Matrice2D&)const;
	Matrice2D operator *(double)const;
	Vecteur2D operator *(Vecteur2D)const;
	

};
inline ostream& operator<<(ostream& s, const Matrice2D& m) {
	return s << m.toString();
}

