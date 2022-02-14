#include "Plan2D.h"
void Plan2D::setAxeI(double y) {
	double ymax = DBL_MIN; // recherche du point le plus loin sur l'axe Y
	for (size_t i = 0; i < FormesDuPlan.size(); i++) {
		if (FormesDuPlan[i]->yMAX() > ymax) {
			ymax = FormesDuPlan[i]->yMAX();
		}
	}
	Vecteur2D v(Origine, Point2D(Origine.x, Origine.y + y));
	if (ymax > v.y) {
		throw new Erreur("Impossible de changer l'axe I car une le nouveau repere est trop petit, certaine formes déjà sur le plan ne serraient pas dedans.");
	}
	else {
		I = v;
	}
}
void Plan2D::setAxeJ(double x) {
	double xmax = DBL_MIN; // recherche du point le plus loin sur l'axe Y
	for (size_t i = 0; i < FormesDuPlan.size(); i++) {
		if (FormesDuPlan[i]->xMAX() > xmax) {
			xmax = FormesDuPlan[i]->xMAX();
		}
	}
	Vecteur2D v(Origine, Point2D(Origine.x + x, Origine.y));
	if (xmax> v.y) {
		throw new Erreur("Impossible de changer l'axe J car une le nouveau repere est trop petit, certaine formes déjà sur le plan ne serraient pas dedans.");
	}
	else {
		J = v;
	}
}
