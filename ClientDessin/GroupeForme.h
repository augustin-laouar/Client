#pragma once
#include "Forme2D.h"
#include "FormeSimple.h"

class GroupeForme : public Forme2D
{
protected:
	vector<Forme2D*>ListeForme;
public :
	GroupeForme(Couleur couleur) : Forme2D(couleur) {}
	GroupeForme(const GroupeForme& g);
	void Destruction();
	virtual ~GroupeForme();
	
	/**
	* @brief ajoute une nouvelle forme au groupe de formes 
	*/

	void ajouterForme(const Forme2D* f) {
		//test si la forme n'entre pas en collision avec une autre forme du groupe, si oui throw error
		ListeForme.push_back(f->clone());
		ListeForme[ListeForme.size()-1]->setCouleur(this->couleur); // met la forme ajoutée de la meme couleur que le groupe
	}
	/**
	* @brief retirer une forme en fonction de son indice 
	*/

	void retirer(int i) {
		if (i >= ListeForme.size()) {
			return;
		}
		ListeForme.erase(ListeForme.begin()+i);
	}

	/**
	* @brief retirer une forme en la passant en parametre 
	*/
	void retirer(const Forme2D* f);
	/**
	* @brief recuperer la forme se trouvant a l'indice i
	*/
	Forme2D* getForme(int i)const {
		return ListeForme.at(i)->clone();
	}
	/**
	* @brief retourne le nombre de formes dans le groupe 
	*/
	int getNbForme()const {
		return this->ListeForme.size();
	}

	virtual GroupeForme* clone()const {
		return new GroupeForme(*this);
	}

	virtual string toString()const;
	void translation(const Vecteur2D& v);
	void homothetie(const Vecteur2D&, double);
	void rotation(const Vecteur2D&, double);
	/*virtual GroupeForme* translation(const Vecteur2D& v)const;
	virtual GroupeForme* homothetie(const Vecteur2D& centre, const double zoom)const;
	virtual GroupeForme* rotation(const Vecteur2D& centre, double angle)const;*/

	/**
	* @brief affecter un groupe de forme a un autre 
	*/
	virtual const GroupeForme& operator = (const GroupeForme& g);
	/**
	* @brief egalite entre deux groupes 
	*/
	virtual bool operator == (const GroupeForme& g)const;

	/**
	* @brief ajout d'une forme a un groupe
	*/
	GroupeForme operator+(const Forme2D* f) {
		GroupeForme res(*this);
		res.ajouterForme(f);
		return res;

	}
	/**
	* @brief retirer une forme du groupe
	*/

	GroupeForme operator -(const Forme2D* f)const {
		GroupeForme res(*this);
		res.retirer(f);
		return res;
	}
	double xMAX()const;
	double yMAX()const;
	double xMIN()const;
	double yMIN()const;
	virtual int whoAmI()const {
		return 0;
	}
	void accept(const VisitorForme2D* v)const;

	virtual double Aire()const;
};

