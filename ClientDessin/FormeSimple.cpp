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
		//rien a faire dans le cas ou ils sont égaux
	}

}

void FormeSimple::rotation(const Point2D& centre , double angle )
{
	//double x, y;
	//angle *=  3.141592653589793/180;
	//for (int i = 0; i < ListePoint.size(); i++)
	//{
	//	//calcul des cooordonnes dans le nouveau repere
	//	x=ListePoint.at(i).x - centre.x;
	//	y=ListePoint.at(i).y - centre.y;

	//	//calcul des nouvelles coordoonnees apres la rotation 
	//	ListePoint.at(i).x = x * cos(angle) + y * sin(angle) + centre.x;
	//	ListePoint.at(i).y = x * sin(angle) + y * cos(angle) + centre.y;
	//}
	for (int i = 0; i < ListePoint.size(); i++) {
		Vecteur2D v(centre, ListePoint[i]); //vecteur entre l'axe de rotation et le point a faire tourné
		double x2 = v.x * cos(angle) - v.y * sin(angle);
		double y2 = v.x * sin(angle) + v.y * cos(angle);
		Vecteur2D v2(x2, y2); // nouveau vecteur après la rotation du vecteur v
		ListePoint[i].translation(v2); //application de la rotation au point
	}

}
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
Forme2D* FormeSimple:: accept(const VisitorForme2D* v) const { return v->visit(this); }