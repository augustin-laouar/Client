#pragma once
#include <string>
#include <iostream>
#include "Erreur.h"
#include "Vecteur2D.h"
#include "Point2D.h"
#include "Couleur.h"

class VisitorForme2D;

class Forme2D
{
protected : 
	Couleur couleur;
public:
	
	
	//enum { black = 1, blue = 2, red = 3, green = 4, yellow = 5,cyan = 6}; // deplacer dans une autre classe

	/**
	* @brief construction d'une forme a partir d'une couleur 
	*/
	Forme2D(Couleur couleur) {
		this->couleur = couleur;
	}

	/**
	*/
	void setCouleur(Couleur couleur) {
		this->couleur = couleur;
	}
	Couleur getCouleur()const {
		return couleur;
	}
	virtual string toString()const = 0;
	operator string() const
	{
		return this->toString();
	}
	virtual Forme2D* clone()const = 0;
	virtual void translation(const Vecteur2D& v) = 0;
	virtual Forme2D* translation(const Vecteur2D& v)const = 0;
	virtual void homothetie(const Vecteur2D& centre, const double zoom) = 0;
	virtual Forme2D* homothetie(const Vecteur2D& centre, const double zoom)const = 0;
	virtual void rotation(const Vecteur2D& centre, double angle) = 0;
	virtual Forme2D* rotation(const Vecteur2D& centre, double angle)const = 0;
	//magnifique
	virtual double xMAX()const=0;
	virtual double yMAX()const=0;
	virtual double xMIN()const=0;
	virtual double yMIN()const=0;
	//typeid
	virtual int whoAmI()const = 0;
	virtual void accept(const VisitorForme2D* v)const = 0;
};
inline ostream& operator<<(ostream& s, const Forme2D& f) {
	return s << f << endl;
}

