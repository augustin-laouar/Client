#pragma once
#include "Forme2D.h"
using namespace std;
class Polygone : public Forme2D
{

public :
	Polygone(vector<Point2D*> v) {
		for (int i = 0; i < v.size(); i++) {
			ajouterPoint(v[i]->clone());
		}
	}
	Polygone(const Polygone & p) {
		for (int i = 0; i < p.getNbPoint(); i++) {
			ajouterPoint(p.getPoint(i)->clone());
		}
	}
	Polygone* clone()const {
		return new Polygone(*this);
	}
	Forme2D* accept(const VisitorForme* v)const;

};

/*
* Operator + avec un point2D
* Operator - avec un point2D
*/