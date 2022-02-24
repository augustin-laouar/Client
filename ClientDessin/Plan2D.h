#pragma once
#include "Vecteur2D.h"
#include "Cercle.h"
class Plan2D
{
	//AXE J
	// ^
	// |
	// |
	//-|------> AXE I
	// O      
private:
	Vecteur2D Origine;
	Vecteur2D I;
	Vecteur2D J;
	vector<Forme2D*>FormesDuPlan;
public:
	Plan2D() : Origine(Vecteur2D(0,0)), I(Vecteur2D(0,1000)), J(Vecteur2D(1000,0)) {}
	Plan2D(const Vecteur2D& O, double x, double y) : Origine(O), J(O.x,O.y + y), I(O.x + x,O.y) {}
	void setOrigine(const Vecteur2D& O = Vecteur2D(0, 0)) { //par defaut réinitialise a 0,0
		double x = I.x - O.x; // taille du repere par rapport au point Origine
		double y = J.y - O.y;
		Origine = O;
		setAxeI(x); // on réinitialise les vecteurs I et J afin qu'ils soit adaptés à la nouvelle origine
		setAxeJ(y);
		// à faire : déplacé toute les formes du plan
		cout << "Point d'origine du repère MAJ" << endl << "Nouvelle origine : " << Origine << endl << "Nouveau axe I : " << I << endl << "Nouveau axe J : " << J << endl;
	}
	void setAxeI(double y);
	void setAxeJ(double x);

	Vecteur2D getAxeI()const {
		return I;
	}
	Vecteur2D getAxeJ()const {
		return J;
	}
	int nbFormes()const {
		return FormesDuPlan.size();
	}
	void ajouterForme(const Forme2D* f) {
		if (f->xMAX() > J.x + Origine.x) { //sort du repere dans l'axe x
			setAxeI(f->xMAX() + 10);//laisse une petit marge de 10 ( arbitraire )
		}
		if (f->yMAX() > I.y + Origine.y) { //sort du repere dans l'axe y
			setAxeJ(f->yMAX() + 10);
		}
		FormesDuPlan.push_back(f->clone());
	}
	Forme2D* getForme(int i)const {
		return FormesDuPlan[i]->clone();
	}
};

