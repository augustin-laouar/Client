#pragma once
#include "Forme.h"
class Trait : public Forme
{
public:
	Trait(const Point& p1, const Point& p2){
		this->AjouterPoint(p1);
		this->AjouterPoint(p2);
	}
	Trait(const Trait& t ){
		this->AjouterPoint(t.ListePoint[0]);
		this->AjouterPoint(t.ListePoint[1]);
	}
	void setP1(const Point& p) {
		this->ListePoint[0] = p;
	}
	Point getP1()const {
		return this->ListePoint[0];
	}
	void setP2(const Point&p) {
		this->ListePoint[1] = p;
	}
	Point getP2()const {
		return this->ListePoint[1];
	}
	Trait* clone()const {
		return new Trait(*this);
	}
	Forme* accept(const VisitorForme* v)const;

};

