#pragma once
#include <vector>
#include <string>
#include "Point.h"
#include "vecteur2D.h"

using namespace std;

class VisitorForme;
class Forme
{
protected  :
	vector<Point* > ListePoint; 
	virtual void ajouterPoint(const Point* p) {
		ListePoint.push_back(p->clone());
	}
	virtual Point* getPoint(int i)const {
		return ListePoint.at(i)->clone();
	}
	virtual void modifierPoint(int i, const Point* p) {
		ListePoint.at(i) = p->clone();
	}
public:
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	virtual Forme * clone()const = 0;
	virtual Forme* accept(const VisitorForme* v)const = 0;
	virtual string toString()const =0 ;
};
inline ostream& operator<<(ostream& s, const Forme& f) {
	return s << f.toString();
}
