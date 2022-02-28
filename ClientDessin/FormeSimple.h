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
	/**
	 * @return un vecteur2d correspondant au point se trouvant a la position i
	 */
	virtual Vecteur2D getPoint(int i)const {
		return ListePoint.at(i);
	}
	/**
	* @return retourne le nombre de points 
	*/
	virtual int getNbPoint()const {
		return ListePoint.size();
	}
	/**
	* @brief renvoi un pointeur sur une formeSimple
	*/
	virtual FormeSimple* clone()const = 0;
	/**
	* @brief toString
	*/
	virtual string toString()const;
	
	void translation(const Vecteur2D& v);
	void homothetie(const Vecteur2D&, double);
	void rotation(const Vecteur2D&, double);
	double xMAX()const; 
	double yMAX()const;
	double xMIN()const;
	double yMIN()const;
	virtual int whoAmI()const {
		return 1;
	}
	virtual void accept(const VisitorForme2D* v)const;
	virtual double Aire()const = 0;
};

