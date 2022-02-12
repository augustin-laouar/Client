#include "GroupeForme.h"

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
void GroupeForme::homothetie(const Point2D& p, double d) {
	for (size_t i = 0; i < ListeForme.size(); i++) {
		ListeForme[i]->homothetie(p,d);
	}
}
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
	for (int i = 0; i < ListeForme.size(); i++)
	{
		if (!(ListeForme[i] == g.ListeForme[i]))
		{
			return false;
		}
	}
	return true;
}
