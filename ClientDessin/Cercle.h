#pragma once
#include "FormeSimple.h"
# define PI           3.14159265358979323846
using namespace std;

/** 
* classe representant un cercle 
*/

class  Cercle : public FormeSimple
{
private:
	double rayon;
public:
	/**
	*@brief construction d'un cercle à partir de d'un centre qui est un point 2D avec coordonnees x,y
	* @param centre rayon du centre
	* @param rayon rayon du cercle
	* @param couleur couleur du cercle
	* 
	*/
	Cercle(const Vecteur2D& centre, double rayon,Couleur couleur) : FormeSimple(couleur) {
		this->ajouterPoint(centre);
		setRayon(rayon);
	}

	/**
	* @brief Constructeur par copie d'un cercle par copie
	* @param c passage par reference
	*/
	Cercle(const Cercle& c) : FormeSimple(c.couleur) {
		this->ajouterPoint(c.ListePoint[0]);
		this->rayon = c.rayon;
	}

	/**
	* @brief setter du centre
	* @param c passage par reference du Point2D avec x,y comme coordonnees 
	*/
	void setCentre(const Vecteur2D &c) {
		this->ListePoint[0] = c;
	}
	/**
	* @brief recuperer la valeur du centre
	* @return Point2D 
	*/
	Vecteur2D  getCentre()const {
		return this->ListePoint[0];
	}
	/**
	* @brief setter du rayon
	* @param rayon 
	*/

	void setRayon(double rayon) {
		if (rayon > 0) {
			this->rayon = rayon;
		}
	}
	/**
	* @brief recuperer la valeur du rayon 
	* @return double rayon 
	*/
	double getRayon()const {
		return this->rayon;
	}

	/**
	* @brief methode pour renvoyer un pointeur sur une copie d'un cercle
	* @return Cercle*
	*/
	Cercle* clone()const {
		return new Cercle(*this);
	}

	/**
	* @brief transformer une chaine de caractere sous forme "cercle :centre :liste des points;rayon"
	*/
	string toString()const {
		return "Cercle : centre : " + ListePoint[0].toString() + "; Rayon : " + to_string(rayon);
	}

	/**
	* @brief operator d'egalite entre deux cercles 
	* @return bool 
	*/

	virtual bool operator == (const Cercle &c)const {
		if (this->rayon == c.rayon && c.ListePoint[0] == this->ListePoint[0]) {
			
			return true;
		}
		else {
			return false;
		}
	}

	/**
	* @brief renvoi 10 pour indiquer que la forme est un cercle
	* @return int 
	*/
	virtual int whoAmI()const {
		return 10;
	}
	/**
	* @brief methode necessaire pour le design pattern visitor
	*/
	virtual void accept(const VisitorForme2D* v);
	/**
	* @brief methode pour calculer l'air d'un cercle 
	* @return double
	*/
	virtual double Aire()const {
		return rayon* rayon * PI;
	}
	/**
	* @brief calculer l homothetie 
	*/
	virtual void homothetie(const Vecteur2D& centre, const double zoom) {
		if (zoom < 0) {
			throw Erreur("Le zoom ne doit pas être negatif");
		}
		ListePoint[0] = ((ListePoint[0] - centre) * zoom) + centre;
		rayon *= zoom;
	}
	/**
	* @brief calculer le x minimum que peut prendre un point du cercle (utile pour le dessin)
	*/
	double xMIN()const {
		return ListePoint[0].x - rayon;
	}
	/** @brief calculer le y minimum que peut prendre un point du cercle (utile pour le dessin)
	*/
	double yMIN()const {
		return ListePoint[0].y - rayon;
	}
	/** @brief calculer le x maximul  que peut prendre un point du cercle (utile pour le dessin)
	*/
	double xMAX()const {
		return ListePoint[0].x + rayon;
	}
	/** @bried calculer le y maximum que peut prendre un point du cercle (utile pour le dessin)
	*/
	double yMAX()const {
		return ListePoint[0].y + rayon;
	}
};