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
Matrice2D Matrice2D::operator +(const Matrice2D& m)const {
	if (this->taille() != m.taille()) {
		throw new Erreur("Matrices de tailles différentes, addition impossible");
	}
	Matrice2D res(*this);
	for (size_t i = 0; i < res.ListeVecteur.size(); i++)
	{
		res.ListeVecteur[i].x = res.ListeVecteur[i].x + m.ListeVecteur[i].x;
		res.ListeVecteur[i].y = res.ListeVecteur[i].y + m.ListeVecteur[i].y;
	}
	return res;
}
Matrice2D Matrice2D::operator -(const Matrice2D& m)const {
	if (this->taille() != m.taille()) {
		throw new Erreur("Matrices de tailles différentes, multiplication impossible");
	}
	Matrice2D res(*this);
	for (size_t i = 0; i < res.ListeVecteur.size(); i++)
	{
		res.ListeVecteur[i].x = res.ListeVecteur[i].x - m.ListeVecteur[i].x;
		res.ListeVecteur[i].y = res.ListeVecteur[i].y - m.ListeVecteur[i].y;
	}
	return res;
}
Matrice2D Matrice2D::operator *(const Matrice2D& m)const {
	if (this->taille() != 2) { // le nombre de colonnes de la matrice A doit etre égal au nombre de lignes de la matrice B, et nous ne travaillons qu'avec des matrices de 2 lignes
		throw new Erreur("Multiplications impossible, le nombre de colonnes de la matrice 1 doit etre égal au nombre de lignes de la matrice 2");
	}
	Matrice2D res;
	double X;
	double Y;
	for (int i = 0; i < m.taille(); i++) {
		X = ListeVecteur[0].x * m.ListeVecteur[i].x + ListeVecteur[1].x * m.ListeVecteur[i].y;
		Y = ListeVecteur[0].y * m.ListeVecteur[i].x + ListeVecteur[1].y * m.ListeVecteur[i].y;
		Vecteur2D v(X, Y);
		res.ajouterVecteur(v);
	}
	return res;
}
Matrice2D Matrice2D::operator *(double d)const {
	Matrice2D res(*this);
	for (int i = 0; i < taille(); i++) {
		res.ListeVecteur[i].x *= d;
		res.ListeVecteur[i].y *= d;
	}
	return res;
}
