#pragma once
#include "Erreur.h"
#include <string>
#include <vector>
using namespace std;

class Noeud // uniquement les methodes neccessaires 
{
private:
	vector<Noeud*>Fils;
public:
	string id;
	string data;
	Noeud() {}
	Noeud(string id) {
		this->id = id;
	}
	virtual ~Noeud() {
		for (size_t i = 0; i < Fils.size(); i++) {
			delete(Fils[i]);
		}
	}
	/**
	* @brief ajouter un noeud fils au noeud pere courant
	*/
	void ajouterFils(Noeud * f) {
		if (f != this) {
			int numFils = Fils.size() + 1; //numero du fils dans l arbre
			Fils.push_back(f);
		}
		else {
			throw Erreur("Impossible d'ajouter ce fils au noeud");
		}
	}
	/**
	* @brief retourner le fils se trouvant a l'indice i
	*/
	Noeud* getFils(size_t i) {
		return Fils[i];
	}
	/**
	* @brief retourne le nombre de fils du noeud 
	*/
	int nbFils()const {
		return Fils.size();
	}
	/**
	* @brief verifie l egalite entre deux noeuds
	*/
	bool operator ==(const Noeud& f)const {
		if (this->id == f.id)
			return true;
		return false;
	}
	string toString()const {
		//parcours en profondeur
		string res = this->id + "[";
		for (int i = 0; i < nbFils(); i++) {
			res += Fils[i]->toString() + "|";
		}
		res += "]";
		return res;
	}
};
inline ostream& operator<<(ostream& s, const Noeud& n) {
	return s << n.toString() << endl;
}

