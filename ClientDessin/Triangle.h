#pragma once
#include "Polygone.h"
#include "Couleur.h"
class Triangle : public Polygone
{
	Triangle(Vecteur2D p1, Vecteur2D p2, Vecteur2D p3,Couleur c)
	{
		vector <Vecteur2D>LP;
		LP.push_back(p1);
		LP.push_back(p2);
		LP.push_back(p3);
		Polygone(LP,c);
		
	}
};

