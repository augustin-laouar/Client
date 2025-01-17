#pragma once
#include "FormeSimple.h"
using namespace std;
class Triangle;
class Polygone : public FormeSimple
{

public :
	/**
	* @brief constructeur de polygone
	* @param v vector de points2d
	* @param couleur 
	*/
	Polygone(vector<Vecteur2D> v, Couleur couleur) : FormeSimple(couleur) {
		for (size_t i = 0; i < v.size(); i++) {
			ListePoint.push_back(v[i]);
		}
	}
	Polygone(Couleur couleur) : FormeSimple(couleur) {}
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
	* @brief renvoi un pointeur sur une copie du polygone
	*/
	Polygone* clone()const {
		return new Polygone(*this);
	}
	

	/**
	* @brief egalite entre deux polygones
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

	Polygone operator+(const Vecteur2D& p)const {
		Polygone res(*this);
		res.ajouterPoint(p);
		return res;

	}
	/**
	* @brief retirer un point du polygone en fonction de son indice
	* @param i indice du point a supprimer
	*/
	void retirer (int i) {
		if (i >= (int) ListePoint.size()) {
			return;
		}
		ListePoint.erase(ListePoint.begin() + i);
	}
	/**
	* @brief retirer un point du polygone en le recherchant grace a ses coordonnes dans la liste des points
	*
	*/
	void retirer(const Vecteur2D& p)
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
	Polygone operator -(const Vecteur2D& p)const {
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
	* @brief necessaire au design pattern visitor 
	*/

	virtual void accept(const VisitorForme2D* v);
	/**
	* @brief permet de diviser le polygone en plusieurs triangles
	*/
	virtual vector<Triangle> Triangulation()const;
	virtual double Aire()const;
	virtual double Perimetre()const;
	
};

