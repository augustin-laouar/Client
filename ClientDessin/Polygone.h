#pragma once
#include "Forme2D.h"
using namespace std;
class Polygone : public Forme2D
{

public :
	Polygone(vector<Point2D*> v) {
		for (int i = 0; i < v.size(); i++) {
			ajouterPoint(v[i]->clone());
		}
	}
	Polygone(const Polygone & p) {
		for (int i = 0; i < p.getNbPoint(); i++) {
			ajouterPoint(p.getPoint(i)->clone());
		}
	}
	Point2D getPointI(int i)const {
		return *getPoint(i);
	}
	Polygone* clone()const {
		return new Polygone(*this);
	}
	Forme2D* accept(const VisitorForme* v)const;


	virtual const Polygone& operator = (const Polygone& p) {
		if (this == &p) {
			return *this;
		}
		
		for (int i = 0; i < p.getNbPoint(); i++)
		{
			ajouterPoint(p.getPoint(i)->clone());
		}
		return *this;
	}
	virtual bool operator == (const Polygone& p)const {
		
		if (this->getNbPoint() != p.getNbPoint())
			return false;
		for (int i = 0; i < p.getNbPoint(); i++)
		{
			if (!(getPointI(i) == p.getPointI(i)))
			{
				return false;
			}
		}
		return true;
	}

	Polygone operator+(const Point2D *p) {
		Polygone res(*this);
		res.ajouterPoint(p->clone());
		return res;

	}
	Polygone operator+(const Point2D& p) {
		Polygone res(*this);
		res.ajouterPoint(p.clone());
		return res;
	}
	Polygone retirer (int i) {
		ListePoint.erase(ListePoint.begin() + i);
		return *this;
			
	}
	
	void retirer(const Point2D& p)
	{
		
		for (int i=0; i<getNbPoint(); i++) {
			if (getPoint(i)==&p)
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



};

/*
* Operator + avec un point2D
* Operator - avec un point2D
*/