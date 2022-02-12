#include "FormeSimple.h"
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
		ListePoint[i].x = ListePoint[i].x + v.x;
		ListePoint[i].y = ListePoint[i].y + v.y;
	}
}
void FormeSimple::homothetie(const Point2D& p, double z) {
	for (size_t i = 0; i < ListePoint.size(); i++) {
		if (ListePoint[i].x < p.x) {
			ListePoint[i].x = ListePoint[i].x - z;
		}
		if (ListePoint[i].x > p.x) {
			ListePoint[i].x = ListePoint[i].x + z;
		}
		if (ListePoint[i].y < p.y) {
			ListePoint[i].y = ListePoint[i].y - z;
		}
		if (ListePoint[i].y > p.y) {
			ListePoint[i].y = ListePoint[i].y + z;
		}
		//rien a faire dans le cas ou ils sont �gaux
	}
}