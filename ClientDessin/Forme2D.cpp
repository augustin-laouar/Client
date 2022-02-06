#include "Forme2D.h"
Forme2D::Forme2D(const Forme2D& f) {
	for (int i = 0; i < getNbPoint(); i++) {
		ajouterPoint(f.getPoint(i)->clone());
	}
}
string Forme2D::toString()const {
	string retour = "Forme : [";
	for (int i = 0; i < getNbPoint(); i++) {
		retour += getPoint(i)->toString() + " ; ";
	}
	retour += " ]";
	return retour;
}