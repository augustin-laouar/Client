#pragma once
#include "Forme2D.h"
#include "FormeSimple.h"
class GroupeForme : public Forme2D
{
protected:
	vector<Forme2D*>ListeForme;
public :
	GroupeForme(int couleur) : Forme2D(couleur) {}
	GroupeForme(const GroupeForme& g);
	void Destruction();
	virtual ~GroupeForme();
	
	void ajouterForme(const Forme2D* f) {
		//test si la forme n'entre pas en collision avec une autre forme du groupe, si oui throw error
		ListeForme.push_back(f->clone());
		ListeForme[ListeForme.size()]->setCouleur(this->couleur); // met la forme ajoutée de la meme couleur que le groupe
	}
	void retirer(int i) {
		ListeForme.erase(ListeForme.begin()+i);
	}
	void retirer(const Forme2D* f);
	Forme2D* getForme(int i)const {
		return ListeForme.at(i)->clone();
	}
	int getNbForme()const {
		return this->ListeForme.size();
	}
	virtual GroupeForme* clone()const {
		return new GroupeForme(*this);
	}
	virtual string toString()const;
	void translation(const Vecteur2D& v);
	void homothetie(const Point2D& p, double d);

	virtual const GroupeForme& operator = (const GroupeForme& g);
	virtual bool operator == (const GroupeForme& g)const;

	GroupeForme operator+(const Forme2D* f) {
		GroupeForme res(*this);
		res.ajouterForme(f);
		return res;

	}

	GroupeForme operator -(const Forme2D* f)const {
		GroupeForme res(*this);
		res.retirer(f);
		return res;
	}
};

