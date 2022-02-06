#pragma once
#include "Forme2D.h"
class Trait : public Forme2D
{
public:
	Trait(const Point2D * p1, const Point2D * p2){
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
	}
	Trait(const Trait& t ){
		this->ajouterPoint(t.getP1().clone());
		this->ajouterPoint(t.getP2().clone());
	}
	void setP1(const Point2D* p) {
		modifierPoint(0, p);
	}
	Point2D getP1()const {
		return *(Forme2D::getPoint(0));
	}
	void setP2(const Point2D *p) {
		modifierPoint(1, p);
	}
	Point2D  getP2()const {
		return *(Forme2D::getPoint(1));
	}
	Trait* clone()const {
		return new Trait(*this);
	}
	Forme2D* accept(const VisitorForme* v)const;
	
	string toString()const {
		string retour;
		retour = "Trait : P1 = " + getP1().toString() + "; P2 = " + getP2().toString();
		return retour;
	}


	virtual const Trait& operator = (const Trait& t) {
		if (this == &t) {
			return *this;
		}
		this->setP1(t.getP1().clone());
		this->setP2(t.getP2().clone());
		return *this;
	}
	virtual bool operator == (const Trait &t)const {
		
		if (  (getP1()==t.getP1()) && (getP2()== t.getP2()))
		{
			return true;
		}
		else {
			return false;
		}
	}
};
