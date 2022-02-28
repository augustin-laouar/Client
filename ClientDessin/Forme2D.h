#pragma once
#include <string>
#include <iostream>
#include "Erreur.h"
#include "Vecteur2D.h"
#include "Couleur.h"

class VisitorForme2D;

class Forme2D
{
protected : 
	Couleur couleur;
public:
	
	/**
	* @brief construction d'une forme a partir d'une couleur 
	*/
	Forme2D(Couleur couleur) {
		this->couleur = couleur;
	}
	virtual ~Forme2D(){}

	/** 
	*@return la couleur de la forme 
	*/
	Couleur getCouleur()const {
		return couleur;
	}
	/**
	* @brief setter de Couleur
	*/
	void setCouleur(Couleur couleur) {
		this->couleur = couleur;
	}
	/**
	* @brief methode ToString
	*/
	virtual string toString()const = 0;
	/**
	* @brief redefinition de l'operator string 
	*/
	operator string() const
	{
		return this->toString();
	}
	virtual Forme2D* clone()const = 0;
	/**
	* @brief translation d'une forme ou d'un goupe de formes en fonction d'un vecteur de translation
	*/
	virtual void translation(const Vecteur2D& v) = 0;
	/**
	* @brief operation d'homothetie sur une forme ou un groupe de formes en fonction d'un centre et d'un rapport
	* @param centre
	* @param zoom est le rapport d'homothetie
	*/
	virtual void homothetie(const Vecteur2D& centre, const double zoom) = 0;
	/**
	* @brief operation de rotation 
	* @param centre correspond au centre de la rotation
	* @param angle correspond a l'angle de la rotation 
	*/
	virtual void rotation(const Vecteur2D& centre, double angle) = 0;
	/**
	* @return renvoi la forme apres translation
	*/
	Forme2D* translation(const Vecteur2D& v)const {
		Forme2D* res = this->clone();
		res->translation(v);
		return res;
	}
	/**
	* @return renvoi la forme apres Homothetie
	*/

	Forme2D* homothetie(const Vecteur2D& centre, const double zoom)const {
		Forme2D* res = this->clone();
		res->homothetie(centre,zoom);
		return res;
	}
	/**
	* @return renvoi la forme apres la rotation
	*/
	Forme2D* rotation(const Vecteur2D& centre, double angle)const {
		Forme2D* res = this->clone();
		res->rotation(centre,angle);
		return res;
	}
	/**
	* @brief Calcul d'aire d'une forme 
	*/
	virtual double Aire()const = 0;
	//magnifique
	
	/**
	* @brief calculer le x maximum que peut prendre un point de la forme en abscisse (utile pour le dessin)
	*/
	virtual double xMAX()const=0;
	/**
	* @brief calculer le y maximum que peut prendre un point de la forme en ordonnees (utile pour le dessin)
	*/
	virtual double yMAX()const=0;
	/**
	* @brief calculer le x minimum que peut prendre un point de la forme en abscisse (utile pour le dessin)
	*/
	virtual double xMIN()const=0;

	/**
	* @brief calculer le y minimum que peut prendre un point de la forme en ordonnees (utile pour le dessin)
	*/
	virtual double yMIN()const=0;
	//typeid

	/**
	* @brief renvoi un nombre en fonction de la classe qui l'appelle (formeSimple,GroupeForme...)
	*/
	virtual int whoAmI()const = 0;
	/**
	* @brief methode pour le design pattern visitor 
	*/
	virtual void accept(const VisitorForme2D* v)const = 0;

};
inline ostream& operator<<(ostream& s, const Forme2D& f) {
	return s << f.toString() << endl;
}

