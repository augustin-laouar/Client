#pragma once
#include <vector>
#include "Forme2D.h"
using namespace std;

class FormeSimple : public Forme2D
{
protected:
	vector<Point2D> ListePoint;
	virtual void ajouterPoint(const Point2D& p) {
		ListePoint.push_back(p);
	}
	virtual void modifierPoint(int i, const Point2D& p) {
		if (i >= ListePoint.size()) {
			throw new Erreur("i sort des bornes de la liste");
		}
		ListePoint.at(i) = p;
	}

public:
	
	FormeSimple(int couleur) : Forme2D(couleur) {}
	FormeSimple(const FormeSimple& f);
	virtual ~FormeSimple() { // en a t on besoin ?
		ListePoint.clear();
	}
	virtual Point2D getPoint(int i)const {
		return ListePoint.at(i);
	}
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	virtual FormeSimple* clone()const = 0;
	virtual string toString()const;
	//virtual Forme2D * accept(const VisitorForme* v)const = 0;
	void translation(const Vecteur2D& v);
	void homothetie(const Point2D&, double);
};

