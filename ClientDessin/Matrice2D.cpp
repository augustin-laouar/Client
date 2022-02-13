#include "Matrice2D.h"
Matrice2D::Matrice2D(const Matrice2D& m) {
	for (size_t i = 0; i < m.ListeVecteur.size(); i++) {
		ListeVecteur.push_back(m.ListeVecteur[i]);
	}
}
void Matrice2D::retirerVecteur(const Vecteur2D& v) {
	for (int i = 0; i < ListeVecteur.size(); i++) {
		if (ListeVecteur[i] == v)
		{

			ListeVecteur.erase(ListeVecteur.begin() + i);
			return;
		}

	}
}
string Matrice2D::toString()const {
	string retour = "MATRICE 2D :\n|";
	for (size_t i = 0; i < ListeVecteur.size(); i++) {
		retour += to_string(ListeVecteur[i].x);
		retour += "  ";
	}
	retour += "|\n|";
	for (size_t i = 0; i < ListeVecteur.size(); i++) {
		retour += to_string(ListeVecteur[i].y);
		retour += "  ";
	}
	retour += "|";
	return retour;
}
const Matrice2D& Matrice2D::operator = (const Matrice2D& m) {
	if (this == &m) {
		return *this;
	}
	ListeVecteur.clear();
	for (size_t i = 0; i < m.ListeVecteur.size(); i++)
	{
		ListeVecteur.push_back(m.ListeVecteur[i]);
	}
	return *this;
}
bool Matrice2D::operator == (const Matrice2D& m)const {

	if (this->taille() != m.taille())
		return false;
	for (size_t i = 0; i < m.ListeVecteur.size(); i++)
	{
		if (!(ListeVecteur[i] == m.ListeVecteur[i]))
		{
			return false;
		}
	}
	return true;
}
