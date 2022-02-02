#pragma once
#include <vector>
#include "Point.h"
#include "vecteur2D.h"

using namespace std;

class VisitorForme;
class Forme
{
protected:
	vector<Point> ListePoint;
public:
	Forme() {}
	Forme(const Forme& f);
	void AjouterPoint(const Point& p) {
		ListePoint.push_back(p);
	}
	Point getPoint(int i)const {
		return ListePoint.at(i);
	}
	Forme* clone()const {
	//	return new Forme(*this); // plu besoin du clone 
	}
	void translation(const Vecteur2D& );
	
	virtual Forme * accept(const VisitorForme* v)const = 0;
};

