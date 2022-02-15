#pragma once
#include "FormeSimple.h"
using namespace std;
class Polygone : public FormeSimple
{

public :
	Polygone(vector<Point2D> v, int couleur) : FormeSimple(couleur) {
		for (size_t i = 0; i < v.size(); i++) {
			ListePoint.push_back(v[i]);
		}
	}
	Polygone(const Polygone & p): FormeSimple(p.couleur) {
		for (int i = 0; i < p.getNbPoint(); i++) {
			ListePoint.push_back(p.ListePoint[i]);
		}
	}
	Point2D getPointI(int i)const {
		return ListePoint.at(i);
	}
	Polygone* clone()const {
		return new Polygone(*this);
	}
	


	virtual const Polygone& operator = (const Polygone& p) {
		if (this == &p) {
			return *this;
		}
		this->couleur = p.couleur;
		ListePoint.clear();
		for (int i = 0; i < p.getNbPoint(); i++)
		{
			ListePoint.push_back(p.ListePoint[i]);
		}
		return *this;
	}
	virtual bool operator == (const Polygone& p)const {
		
		if (this->getNbPoint() != p.getNbPoint())
			return false;
		for (int i = 0; i < p.getNbPoint(); i++)
		{
			if (!(ListePoint[i] == p.ListePoint[i]))
			{
				return false;
			}
		}
		return true;
	}

	Polygone operator+(const Point2D& p)const {
		Polygone res(*this);
		res.ajouterPoint(p);
		return res;

	}
	void retirer (int i) {
		if (i >= ListePoint.size()) {
			return;
		}
		ListePoint.erase(ListePoint.begin() + i);
	}
	
	void retirer(const Point2D& p)
	{
		
		for (int i=0; i<getNbPoint(); i++) {
			if (ListePoint[i] == p)
			{
			
				ListePoint.erase(ListePoint.begin() + i);
				return;
			}
			
		}
	}
	

	Polygone operator -(const Point2D& p)const {
		Polygone res(*this);
		res.retirer(p);
		return res;
	}
	virtual int whoAmI()const {
		return 11;
	}


	virtual void accept(const VisitorForme2D* v);


};

