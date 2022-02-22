#pragma once
#include "Polygone.h"
class Triangle : public Polygone
{
public:
	Triangle(Vecteur2D p1, Vecteur2D p2, Vecteur2D p3, Couleur c) : Polygone(c)
	{
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
		this->ajouterPoint(p3);		
	}
	virtual double LongueurCote(int numCote)const {
		if (numCote < 1 || numCote>3) {
			throw Erreur("Le numero du cote doit etre entre 1 et 3");
		}
		Vecteur2D aux;
		if (numCote < 3) {
			aux = ListePoint[numCote - 1] - ListePoint[numCote];
		}
		else {
			aux = ListePoint[2] - ListePoint[0];
		}
		return aux.norme();
	}
	virtual double Aire()const {
		double a = LongueurCote(1);
		double b = LongueurCote(2);
		double c = LongueurCote(3);
		double p = this->Perimetre() * 0.5;
		return sqrt(p * (p - a) * (p - b) * (p - c)); //formule de Héron
	}

};

