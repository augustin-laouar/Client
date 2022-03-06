#include "GroupeForme.h"
#include "VisitorForme2D.h"

GroupeForme::GroupeForme(const GroupeForme& g) : Forme2D(g.couleur) {
	for (size_t i = 0; i < g.ListeForme.size(); i++) {
		ajouterForme(g.ListeForme[i]);
	}
}
void GroupeForme::Destruction() {
	for (size_t i = 0; i < ListeForme.size(); i++) {
		delete(ListeForme[i]);
	}
	ListeForme.clear();
}
GroupeForme::~GroupeForme() {
	Destruction();
}
void GroupeForme::retirer(const Forme2D* f)
{

	for (size_t i = 0; i < ListeForme.size(); i++) {
		if (ListeForme[i] == f)
		{

			ListeForme.erase(ListeForme.begin() + i);
			return;
		}

	}
}
string GroupeForme::toString()const {
	string retour = "Groupe : [ \n";
	for (size_t i = 0; i < ListeForme.size(); i++) {
		retour += ListeForme[i]->toString() + " \n";
		
	}
	retour += " ]";
	return retour;
}
void GroupeForme::translation(const Vecteur2D& v) {
	for (size_t i = 0; i < ListeForme.size(); i++) {
		ListeForme[i]->translation(v);
	}
}
void GroupeForme::homothetie(const Vecteur2D& p, double z) {
	for (size_t i = 0; i < ListeForme.size(); i++) {
		ListeForme[i]->homothetie(p,z);
	}
}
void GroupeForme::rotation(const Vecteur2D& p, double angle) {
	for (size_t i = 0; i < ListeForme.size(); i++) {
		ListeForme[i]->rotation(p, angle);
	}
}
//GroupeForme* GroupeForme::translation(const Vecteur2D& v)const {
//	GroupeForme* res = new GroupeForme(*this);
//	res->translation(v);
//	return res;
//}
//GroupeForme* GroupeForme::homothetie(const Vecteur2D& centre, const double zoom)const {
//	GroupeForme* res = new GroupeForme(*this);
//	res->homothetie(centre,zoom);
//	return res;
//}
//GroupeForme* GroupeForme::rotation(const Vecteur2D& centre, double angle)const {
//	GroupeForme* res = new GroupeForme(*this);
//	res->rotation(centre,angle);
//	return res;
//}
const GroupeForme& GroupeForme::operator = (const GroupeForme& g) {
	if (this == &g) {
		return *this;
	}
	this->couleur = g.couleur;
	Destruction();
	for (size_t i = 0; i < g.ListeForme.size(); i++)
	{
		ajouterForme(g.ListeForme[i]->clone());
	}
	return *this;
}
bool GroupeForme::operator == (const GroupeForme& g)const {

	if (this->getNbForme() != g.getNbForme())
		return false;
	for (int i = 0; i < (int)ListeForme.size(); i++)
	{
		if (!(ListeForme[i] == g.ListeForme[i]))
		{
			return false;
		}
	}
	return true;
}
double GroupeForme::xMAX()const {
	double x = DBL_MIN;
	for (size_t i = 0; i < ListeForme.size(); i++) {
		if (ListeForme[i]->xMAX() > x) {
			x = ListeForme[i]->xMAX();
		}
	}
	return x;
}
double GroupeForme::yMAX()const {
	double y = DBL_MIN;
	for (size_t i = 0; i < ListeForme.size(); i++) {
		if (ListeForme[i]->yMAX() > y) {
			y = ListeForme[i]->yMAX();
		}
	}
	return y;
}
double GroupeForme::xMIN()const {
	double x = DBL_MAX;
	for (size_t i = 0; i < ListeForme.size(); i++) {
		if (ListeForme[i]->xMIN() < x) {
			x = ListeForme[i]->xMIN();
		}
	}
	return x;
}
double GroupeForme::yMIN()const {
	double y = DBL_MAX;
	for (size_t i = 0; i < ListeForme.size(); i++) {
		if (ListeForme[i]->yMIN() < y) {
			y = ListeForme[i]->yMIN();
		}
	}
	return y;
}


void GroupeForme::accept(const VisitorForme2D* v)const { v->visit(this); }
double GroupeForme::Aire()const {
	double res = 0;
	for (size_t i = 0; i < ListeForme.size(); i++) {
		res += ListeForme[i]->Aire();
	}
	return res;
}