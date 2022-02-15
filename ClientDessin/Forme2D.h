#pragma once
#include <string>
#include <iostream>
#include "Erreur.h"
#include "Vecteur2D.h"
#include "Point2D.h"

class VisitorForme2D;
class Forme2D
{
protected : 
	int couleur;
public:
	#define cyan 0,0,255,255
	
	enum { black = 1, blue = 2, red = 3, green = 4, yellow = 5};
	Forme2D(int couleur) {
		this->couleur = couleur;
	}
	void setCouleur(int couleur) {
		this->couleur = couleur;
	}
	int getCouleur()const {
		return couleur;
	}
	virtual string toString()const = 0;
	operator string() const
	{
		return this->toString();
	}
	virtual Forme2D* clone()const = 0;
	virtual void translation(const Vecteur2D& v) = 0;
	virtual void homothetie(const Point2D&, double) = 0;
	virtual double xMAX()const=0;
	virtual double yMAX()const=0;
	virtual double xMIN()const=0;
	virtual double yMIN()const=0;

	virtual Forme2D* accept(const VisitorForme2D* v)const = 0;
};
inline ostream& operator<<(ostream& s, const Forme2D& f) {
	return s << f.toString();
}

