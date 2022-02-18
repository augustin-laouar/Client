#pragma once
#include "Erreur.h"
#include "Vecteur2D.h"
#include <vector>
class Matrice2D
{
private : 
	vector<Vecteur2D> ListeVecteur;
public:
	//constructeurs
	Matrice2D() {}
	Matrice2D(const Matrice2D& m);
	virtual ~Matrice2D() {
		ListeVecteur.clear();
	}

	//getters setters
	void ajouterVecteur(const Vecteur2D& v) {
		ListeVecteur.push_back(v);
	}
	void retirerVecteur(int i) {
		if (i >= ListeVecteur.size()) {
			return;
		}
		ListeVecteur.erase(ListeVecteur.begin() + i);
	}
	void retirerVecteur(const Vecteur2D& v);
	Vecteur2D getVecteur(int i)const {
		return ListeVecteur.at(i);
	}
	int taille()const {
		return ListeVecteur.size();
	}

	//Methodes

	//toString clone et operator
	string toString()const;
	Matrice2D* clone()const {
		return new Matrice2D(*this);
	}
	virtual const Matrice2D& operator = (const Matrice2D& m);
	virtual bool operator == (const Matrice2D& m)const;

	Matrice2D operator+(const Vecteur2D& v)const {
		Matrice2D res(*this);
		res.ajouterVecteur(v);
		return res;

	}

	Matrice2D operator -(const Vecteur2D& v)const {
		Matrice2D res(*this);
		res.retirerVecteur(v);
		return res;
	}

	operator string() const
	{
		return this->toString();
	}
	Matrice2D operator +(const Matrice2D&)const;
	Matrice2D operator -(const Matrice2D&)const;
	Matrice2D operator *(const Matrice2D&)const;
	Matrice2D operator *(double)const;
	

};
inline ostream& operator<<(ostream& s, const Matrice2D& m) {
	return s << m.toString();
}

