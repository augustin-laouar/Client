#pragma once
#include "FormeSimple.h"
class Trait : public FormeSimple
{
public:

	/**
	* @brief constructeur 
	* @param p1 premier point 
	* @param p2 deuxieme point
	* @param couleur couleur du trait 
	* 
	*/
	Trait(const Vecteur2D& p1, const Vecteur2D& p2, Couleur couleur): FormeSimple(couleur) {
		this->ajouterPoint(p1);
		this->ajouterPoint(p2);
	}
	/**
	* @brief constructeur par copie avec passage par reference 
	* @param t trait 
	* @param couleur couleur du trait
	*/
	Trait(const Trait& t ) : FormeSimple(t.couleur) {
		this->ajouterPoint(t.ListePoint[0]);
		this->ajouterPoint(t.ListePoint[1]);
	}
	void setP1(const Vecteur2D& p) {
		this->ListePoint[0] = p;
	}
	Vecteur2D getP1()const {
		return ListePoint[0];
	}
	void setP2(const Vecteur2D&p) {
		this->ListePoint[1] = p;
	}
	Vecteur2D  getP2()const {
		return ListePoint[1];
	}
	/**
	* @brief methode qui permet de retourner un pointeur sur une copie du trait
	*/
	Trait* clone()const {
		return new Trait(*this);
	}
	
	/**
	* @brief transformer un trait en chaine de caractere
	*/
	
	string toString()const {
		string retour;
		retour = "Trait : P1 = " + ListePoint[0].toString() + "; P2 = " + ListePoint[1].toString();
		return retour;
	}

	/**
	* @brief verifie l'egalite entre deux trait 
	* @param t const trait& 
	*/
	virtual bool operator == (const Trait &t)const {
		
		if (  (ListePoint[0] == t.ListePoint[0]) && (ListePoint[1] == t.ListePoint[1]))
		{
			return true;
		}
		else {
			return false;
		}
	}

	/**
	* @brief renvoi 12 pour dire que c'est un trait
	*/
	virtual int whoAmI()const {
		return 12;
	}
	/**
	* @brief methode pour visitor 
	* @param v VisitorForme2d*
	*/
	virtual void accept(const VisitorForme2D* v);
};
