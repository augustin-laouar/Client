#include "FormeSimple.h"
#include "Matrice2D.h"
#include "VisitorForme2D.h"
#include <cmath>


FormeSimple::FormeSimple(const FormeSimple& f) : Forme2D(couleur) {
	for (size_t i = 0; i < f.ListePoint.size(); i++) {
		ajouterPoint(f.ListePoint[i]);
	}
}
string FormeSimple::toString()const {
	string retour = "Forme : [";
	for (int i = 0; i < getNbPoint(); i++) {
		retour += ListePoint[i].toString() + " ; ";
	}
	retour += " ]";
	return retour;
}
void FormeSimple::translation(const Vecteur2D& v) {
	for (size_t i = 0; i < ListePoint.size(); i++) {
		ListePoint[i].translation(v);
	}
}
void FormeSimple::homothetie(const Vecteur2D& p, double z) {
	for (size_t i = 0; i < ListePoint.size(); i++) {
		ListePoint[i] =  ((ListePoint[i] - p) * z)+ p;
	}
	
}

void FormeSimple::rotation(const Vecteur2D& centre , double angle )
{
	Matrice2D R(cos(angle), sin(angle), -sin(angle), cos(angle));
	for (size_t i = 0; i < ListePoint.size(); i++) {
		//ListePoint[i] = R * ( ListePoint[i] - p ) + p où R est une matrice 2*2
		ListePoint[i] = (R * (ListePoint[i] - centre)) + centre;
 	}

}
//FormeSimple* FormeSimple::translation(const Vecteur2D& v)const {
//	FormeSimple* res = new FormeSimple(*this);
//	res->translation(v);
//	return res;
//}
//FormeSimple* FormeSimple::homothetie(const Vecteur2D& centre, const double zoom)const {
//	FormeSimple* res = new FormeSimple(*this);
//	res->homothetie(centre,zoom);
//	return res;
//}
//FormeSimple* FormeSimple::rotation(const Vecteur2D& centre, double angle)const {
//	FormeSimple* res = new FormeSimple(*this);
//	res->rotation(centre,angle);
//	return res;
//}
double FormeSimple::xMAX()const {
	double x = DBL_MIN;
	for (size_t i = 0; i < ListePoint.size(); i++) {
		if (ListePoint[i].x > x) {
			x = ListePoint[i].x;
		}
	}
	return x;
}
double FormeSimple::yMAX()const {
	double y = DBL_MIN;
	for (size_t i = 0; i < ListePoint.size(); i++) {
		if (ListePoint[i].y > y) {
			y = ListePoint[i].y;
		}
	}
	return y;
}
double FormeSimple::xMIN()const {
	double x = DBL_MAX;
	for (size_t i = 0; i < ListePoint.size(); i++) {
		if (ListePoint[i].x < x) {
			x = ListePoint[i].x;
		}
	}
	return x;
}
double FormeSimple::yMIN()const {
	double y = DBL_MAX;
	for (size_t i = 0; i < ListePoint.size(); i++) {
		if (ListePoint[i].y < y) {
			y = ListePoint[i].y;
		}
	}
	return y;
}
void FormeSimple::accept(const VisitorForme2D* v)const {
	v->visit(this);
}

