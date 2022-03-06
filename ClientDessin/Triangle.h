#pragma once
#include "Polygone.h"
class Triangle : public Polygone
{
public:

	/**
	* @brief Construction d'un triangle a partir de trois point
	*/
	Triangle(Vecteur2D p1, Vecteur2D p2, Vecteur2D p3, Couleur c) : Polygone(c)
	{
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
		this->ajouterPoint(p3);		
	}
	/**
	* @brief calcule la longueur d'un cote du triangle
	*/
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
	/**
	* @brief calcul de l'aire en utilisant la formule d'Heron 
	*/
	virtual double AireHeron()const {
		double a = LongueurCote(1);
		double b = LongueurCote(2);
		double c = LongueurCote(3);
		double p = this->Perimetre() * 0.5;
		return sqrt(p * (p - a) * (p - b) * (p - c)); //formule de Héron
	}

	virtual double Aire()const {
		Vecteur2D u1 = ListePoint[1] - ListePoint[0];
		Vecteur2D u2 = ListePoint[2] - ListePoint[0];
		double res = u1.determinant(u2);
		return abs(res) * 0.5; 
	}

};

