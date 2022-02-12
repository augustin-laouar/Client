#pragma once
#include <string>
#include <iostream>
#include "Erreur.h"
class Forme2D
{
protected : 
	int couleur;
public:
	enum { black = 1, blue = 2, red = 3 ,green =4,yellow = 5,cyan = 6};
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
	virtual Forme2D* clone()const = 0;
};
inline ostream& operator<<(ostream& s, const Forme2D& f) {
	return s << f.toString();
}

