#pragma once
#include "Polygone.h"
#include "Couleur.h"
class Triangle : public Polygone
{
	Triangle(Vecteur2D p1, Vecteur2D p2, Vecteur2D p3,Couleur c)
	{
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
		this->ajouterPoint(p3);		
	}

};

