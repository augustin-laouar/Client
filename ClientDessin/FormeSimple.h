#pragma once
#include <vector>
#include "Forme2D.h"
using namespace std;

class FormeSimple : public Forme2D //la classe ne contient pas de partie dynamique donc destructeur inutile constructeur apr copie inutile et affectation inutile
{
protected:
	vector<Vecteur2D> ListePoint; // un point est un vecteur allant de l'origine du repere au point du plan
	virtual void ajouterPoint(const Vecteur2D& p) {
		ListePoint.push_back(p);
	}
	virtual void modifierPoint(int i, const Vecteur2D& p) {
		if (i >= ListePoint.size()) {
			throw new Erreur("i sort des bornes de la liste");
		}
		ListePoint.at(i) = p;
	}

public:
	
	FormeSimple(Couleur couleur) : Forme2D(couleur) {}
	FormeSimple(const FormeSimple& f);
	virtual ~FormeSimple() { // en a t on besoin ?
		ListePoint.clear();
	}
	virtual Vecteur2D getPoint(int i)const {
		return ListePoint.at(i);
	}
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	virtual FormeSimple* clone()const {
		return new FormeSimple(*this);
	}
	virtual string toString()const;

	void translation(const Vecteur2D& v);
	void homothetie(const Vecteur2D&, double);
	void rotation(const Vecteur2D&, double);
	virtual FormeSimple* translation(const Vecteur2D& v)const;
	virtual FormeSimple* homothetie(const Vecteur2D& centre, const double zoom)const;
	virtual FormeSimple* rotation(const Vecteur2D& centre, double angle)const;
	double xMAX()const; // permet de connaitre le point de la forme le plus avance sur l'axe X
	double yMAX()const;
	double xMIN()const;
	double yMIN()const;
	virtual int whoAmI()const {
		return 1;
	}
	virtual void accept(const VisitorForme2D* v)const;
	
};

