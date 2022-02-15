#pragma once
#include "FormeSimple.h"
using namespace std;
class  Cercle : public FormeSimple
{
private:
	double rayon;
public:
	Cercle(const Point2D& centre, double rayon, int couleur) : FormeSimple(couleur) {
		this->ajouterPoint(centre);
		this->rayon = rayon;
	}
	Cercle(const Cercle& c) : FormeSimple(c.couleur) {
		this->ajouterPoint(c.ListePoint[0]);
		this->rayon = c.rayon;
	}
	void setCentre(const Point2D &c) {
		this->ListePoint[0] = c;
	}
	Point2D  getCentre()const {
		return this->ListePoint[0];
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
		return "Cercle : centre : " + ListePoint[0].toString() + "; Rayon : " + to_string(rayon);
	}


	virtual const Cercle& operator = (const Cercle& c) {
		if (this == &c) {
			return *this;
		}
		this->couleur = c.couleur;
		this->rayon= c.rayon;
		this->setCentre(c.getCentre());
		return *this;
	}
	virtual bool operator == (const Cercle &c)const {
		if (this->rayon == c.rayon && c.ListePoint[0] == this->ListePoint[0]) {
			
			return true;
		}
		else {
			return false;
		}
	}

	virtual FormeSimple* accept(const VisitorFormeSimple* v)const;
};