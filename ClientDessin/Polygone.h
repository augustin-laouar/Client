#pragma once
#include "FormeSimple.h"
using namespace std;
class Polygone : public FormeSimple
{

public :
	/**
	* @brief constructeur de polygone
	* @param v vector de points2d
	* @param couleur 
	*/
	Polygone(vector<Point2D> v, int couleur) : FormeSimple(couleur) {
		for (size_t i = 0; i < v.size(); i++) {
			ListePoint.push_back(v[i]);
		}
	}
	/**
	* @brief constructeur par copie 
	* @param p Polygone 
	* 
	*/

	Polygone(const Polygone & p): FormeSimple(p.couleur) {
		for (int i = 0; i < p.getNbPoint(); i++) {
			ListePoint.push_back(p.ListePoint[i]);
		}
	}

	/**
	* @brief recuperer un point du polygone grace a son index 
	*/
	Point2D getPointI(int i)const {
		return ListePoint.at(i);
	}
	/**
	* @brief renvoi une pointeur sur une copie du polygone
	*/
	Polygone* clone()const {
		return new Polygone(*this);
	}
	
	/** 
	* @brief affecter un polygone a un autre 
	* 
	*/

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
	/**
	* @brief egalite entre deux polygones
	* @return bool
	*/


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
	/**
	* @brief ajout d'un point au polygone
	* 
	*/

	Polygone operator+(const Point2D& p)const {
		Polygone res(*this);
		res.ajouterPoint(p);
		return res;

	}
	/**
	* @brief retirer un point du polygone en fonction de son indice
	* 
	*/
	void retirer (int i) {
		if (i >= ListePoint.size()) {
			return;
		}
		ListePoint.erase(ListePoint.begin() + i);
	}
	/**
	* @brief retirer un point du polygone en le recherchant grace a ses coordonnes dans la liste des points
	*
	*/
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
	
	/**
	* @brief retirer un point du polygone en le passant en parametre
	* @param p point a retirer
	*/
	Polygone operator -(const Point2D& p)const {
		Polygone res(*this);
		res.retirer(p);
		return res;
	}
	/**
	* @brief renvoi 11 pour indiquer que le forme est un polygone 
	*/
	virtual int whoAmI()const {
		return 11;
	}
	/**
	* @brief necessaire au designe pattern visitor 
	*/

	virtual void accept(const VisitorForme2D* v);


};

