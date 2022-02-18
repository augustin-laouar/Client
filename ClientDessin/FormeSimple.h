#pragma once
#include <vector>
#include "Forme2D.h"
using namespace std;

class FormeSimple : public Forme2D //la classe ne contient pas de partie dynamique donc destructeur inutile constructeur apr copie inutile et affectation inutile
{
protected:
	vector<Point2D> ListePoint;
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
	
	FormeSimple(int couleur) : Forme2D(couleur) {}
	FormeSimple(const FormeSimple& f);
	virtual ~FormeSimple() { // en a t on besoin ?
		ListePoint.clear();
	}
	virtual Point2D getPoint(int i)const {
		return ListePoint.at(i);
	}
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	virtual FormeSimple* clone()const = 0;
	virtual string toString()const;

	void translation(const Vecteur2D& v);
	void homothetie(const Point2D&, double);
	void rotation(const Point2D&, double);
	double xMAX()const; // permet de connaitre le point de la forme le plus avance sur l'axe X
	double yMAX()const;
	double xMIN()const;
	double yMIN()const;
	virtual int whoAmI()const {
		return 1;
	}
	virtual void accept(const VisitorForme2D* v);
	
};

