#pragma once
#include "Forme.h"
#include "vecteur2D.h"
#include "Point2D.h"
using namespace std;

class Forme2D : public Forme
{
protected:
	virtual void ajouterPoint(const Point2D* p) {
		ListePoint.push_back(p->clone());
	}
	virtual Point2D* getPoint(int i)const {
		return (Point2D*)ListePoint.at(i);
	}
public:
	Forme2D() {}
	Forme2D(const Forme2D& f);
	virtual Forme2D* clone()const = 0;
	virtual string toString()const;
	virtual Forme2D * accept(const VisitorForme* v)const = 0;
	void translation(const Vecteur2D& v) {
		for (size_t i = 0; i < ListePoint.size(); i++) {
			getPoint(i)->x = getPoint(i)->x + v.x;
			getPoint(i)->y = getPoint(i)->y + v.y;
		}
	}
	
};


