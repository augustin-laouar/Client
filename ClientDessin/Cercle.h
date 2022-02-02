#pragma once
#include "Forme.h"
using namespace std;
class Cercle : public Forme
{
private:
	double rayon;
public:
	Cercle(const Point& centre, double rayon) {
		this->AjouterPoint(centre);
		this->rayon = rayon;
	}
	Cercle(const Cercle& c) {
		this->AjouterPoint(c.getCentre());
		this->rayon = c.rayon;
	}
	void setCentre(const Point& c) {
		this->ListePoint[0] = c;
	}
	Point getCentre()const {
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
	Forme* accept(const VisitorForme* v)const;
};

