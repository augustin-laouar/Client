#pragma once
#include "Forme2D.h"
using namespace std;
class Cercle : public Forme2D
{
private:
	double rayon;
public:
	Cercle(const Point2D* centre, double rayon) {
		this->ajouterPoint(centre);
		this->rayon = rayon;
	}
	Cercle(const Cercle& c) {
		this->ajouterPoint(c.getCentre().clone());
		this->rayon = c.rayon;
	}
	void setCentre(const Point2D &c) {
		modifierPoint(0,c.clone());
	}
	Point2D  getCentre()const {
		return *(getPoint(0)->clone());
	}
	void setRayon(double rayon) {
		if (rayon > 0) {
			this->rayon = rayon;
		}
	}
	double getRayon()const {
		return this->rayon;
	}
	Cercle* clone()const {
		return new Cercle(*this);
	}
	string toString()const {
		return "Cercle : centre : " + getCentre().toString() + "; Rayon : " + to_string(rayon);
	}
	Forme2D* accept(const VisitorForme* v)const;

	virtual const Cercle& operator = (const Cercle& c) {
		if (this == &c) {
			return *this;
		}
		this->rayon= c.rayon;
		this->setCentre(c.getCentre());
		return *this;
	}
	virtual bool operator == (const Cercle &c)const {
		if (this->rayon == c.rayon && c.getCentre() == this->getCentre()) {
			
			return true;
		}
		else {
			return false;
		}
	}
};
/*
* redefinir operator ==
* redefinir operator =
*/
