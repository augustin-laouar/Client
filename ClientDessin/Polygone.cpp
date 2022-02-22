#include "Polygone.h"
#include "VisitorForme2D.h"
#include "Triangle.h"

void Polygone::accept(const VisitorForme2D* v) { v->visit(this); }


vector<Triangle> Polygone::Triangulation()const {
	vector<Triangle> res;
	Polygone aux(*this);
	while (aux.getNbPoint() > 3) {
		Triangle t(aux.getPoint(0), aux.getPoint(1), aux.getPoint(2), aux.getCouleur());
		res.push_back(t);
		aux.retirer(1); // on retire le deuxieme point
	}
	//arrive ici, il ne reste que 3 point dans aux, c'est donc un triangle
	Triangle t(aux.getPoint(0), aux.getPoint(1), aux.getPoint(2), aux.getCouleur());
	res.push_back(t);
	return res;
}


double Polygone::Aire()const {
	vector<Triangle> triangulation = Triangulation();
	double res = 0;
	for (size_t i = 0; i < triangulation.size(); i++) {
		res += triangulation[i].Aire();
	}
	return res;
}


double Polygone::Perimetre()const {
	double res = 0;
	Vecteur2D aux;
	for (size_t i = 0; i < ListePoint.size() - 1; i++) {
		aux = ListePoint[i] - ListePoint[i + 1]; //distance entre chaque point de la forme
		res += aux.norme();
	}
	aux = ListePoint[ListePoint.size() - 1] - ListePoint[0]; //distance entre le dernier point et le premier point
	res += aux.norme();
	return res;
}