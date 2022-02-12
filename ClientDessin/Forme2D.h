#pragma once
#include <vector>
#include "Erreur.h"
#include "vecteur2D.h"
#include "Point2D.h"
using namespace std;

class Forme2D
{
protected:
	vector<Point2D> ListePoint;
	int couleur;
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
	
	Forme2D(int couleur) {
		this->couleur = couleur;
	}
	Forme2D(const Forme2D& f);
	virtual ~Forme2D() { // en a t on besoin ?
		ListePoint.clear();
	}
	virtual Point2D getPoint(int i)const {
		return ListePoint.at(i);
	}
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	virtual Forme2D* clone()const = 0;
	virtual string toString()const;
	operator string() const
	{
		return this->toString();
	}
	//virtual Forme2D * accept(const VisitorForme* v)const = 0;
	void translation(const Vecteur2D& v);
	void homothetie(const Point2D&, double);
};
inline ostream& operator<<(ostream& s, const Forme2D& f) {
	return s << f.toString();
}

