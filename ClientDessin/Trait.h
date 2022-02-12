#pragma once
#include "FormeSimple.h"
class Trait : public FormeSimple
{
public:
	Trait(const Point2D& p1, const Point2D& p2, int couleur): FormeSimple(couleur) {
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
	}
	Trait(const Trait& t ) : FormeSimple(t.couleur) {
		this->ajouterPoint(t.ListePoint[0]);
		this->ajouterPoint(t.ListePoint[1]);
	}
	void setP1(const Point2D& p) {
		this->ListePoint[0] = p;
	}
	Point2D getP1()const {
		return ListePoint[0];
	}
	void setP2(const Point2D&p) {
		this->ListePoint[1] = p;
	}
	Point2D  getP2()const {
		return ListePoint[1];
	}
	Trait* clone()const {
		return new Trait(*this);
	}
	//Forme2D* accept(const VisitorForme* v)const;
	
	string toString()const {
		string retour;
		retour = "Trait : P1 = " + ListePoint[0].toString() + "; P2 = " + ListePoint[1].toString();
		return retour;
	}


	virtual const Trait& operator = (const Trait& t) {
		if (this == &t) {
			return *this;
		}
		this->setP1(t.ListePoint[0]);
		this->setP2(t.ListePoint[1]);
		return *this;
	}
	virtual bool operator == (const Trait &t)const {
		
		if (  (ListePoint[0] == t.ListePoint[0]) && (ListePoint[1] == t.ListePoint[1]))
		{
			return true;
		}
		else {
			return false;
		}
	}
};
