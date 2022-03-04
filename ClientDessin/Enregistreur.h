#pragma once
#include "Plan2D.h"
#include <iostream>
#include <fstream>
#include "Noeud.h"
#include "GroupeForme.h"
#include "Polygone.h"
#include "Cercle.h"
#include "Trait.h"
#include "VisitorForme2D.h"
#pragma warning(disable : 4996)
using namespace std;
class Enregistreur : public VisitorForme2D
{	
private:
	string nomFichier;
public:
	Enregistreur(string nom) {
		nomFichier = nom;
	}
	/**
	* @brief getter de nom de fichier 
	*/
	string getNomFichier()const {
		return nomFichier;
	}
	/**
	* @brief setter de nom de fichier
	*/
	void setNomFichier(string nom) {
		nomFichier = nom;
	}
	void enregistrerNoeud(Noeud* n, FILE * file)const {
		string requete = n->id + ":" + n->data;
		fputs(requete.c_str(), file);
	}

	virtual void visit(const FormeSimple* f)const {
		FILE * outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = creerNoeud(f,"0");
		enregistrerNoeud(n, outfile);
	}
	virtual	void visit(const GroupeForme* f)const {
		FILE* outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = creerNoeud(f,"0");
		enregistrerNoeud(n, outfile);
	}
	virtual void visit(const Polygone* f)const {
		FILE* outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = creerNoeud(f,"0");
		enregistrerNoeud(n, outfile);
	}
	virtual void visit(const Trait* f)const {
		FILE* outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = creerNoeud(f,"0");
		enregistrerNoeud(n, outfile);
	}
	virtual void visit(const Cercle* f)const {
		FILE* outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = creerNoeud(f,"0");
		enregistrerNoeud(n, outfile);
	}
	/**
	* @brief enregistrement d'un polygone dans un fichier	
	*/
	virtual Noeud * creerNoeud(const Polygone* f,string id) const {
		Noeud* n = new Noeud(id);
		n->data = "3;" + to_string(f->getNbPoint()) + ";";
		for (int i = 0; i < f->getNbPoint(); i++) {
			n->data += to_string(f->getPoint(i).x) + "," + to_string(f->getPoint(i).y) + ";";
		}
		n->data += f->getCouleur().toString() + ";";
		return n;
	}
	/**
	* @brief enregistrement d'un trait dans un fichier 
	*/

	virtual Noeud* creerNoeud(const Trait* f,string id) const {
		Noeud* n = new Noeud(id);
		n->data = "1;" + to_string(f->getP1().x) + "," + to_string(f->getP1().y) + ";" + to_string(f->getP2().x) + "," + to_string(f->getP2().y) + ";" + f->getCouleur().toString() + ";";
		return n;

	}

	/**
	* @brief enregistrement d'un cercle dans le fichier 
	*/
	virtual Noeud* creerNoeud(const Cercle* f,string id)const {
		Noeud* n = new Noeud(id);
		n->data = "2;" + to_string(f->getRayon()) + ";" + to_string(f->getCentre().x) + "," + to_string(f->getCentre().y) + ";" + f->getCouleur().toString() + ";";
		return n;
	}

	/**
	* @brief enregistrement de forme simple 
	*/

	virtual Noeud* creerNoeud(const FormeSimple* f,string id)const {

		switch (f->whoAmI()) {
		case 10: {
			Cercle* c = (Cercle*)f;
			return creerNoeud(c,id);
		}
			   break;
		case 11: {
			Polygone* p = (Polygone*)f;
			return creerNoeud(p,id);
		}
			   break;
		case 12: {
			Trait* t = (Trait*)f;
			return creerNoeud(t,id);
		}
		}

	}
	/**
	* @brief enregistrement d'un groupe de forme 
	*/
	virtual Noeud* creerNoeud(const GroupeForme* f,string id)const {
		Noeud* g = new Noeud(id);
	
		for (size_t i = 0; i < f->getNbForme(); i++) {  //parcour de toutes les formes du groupe
			string newID = id + "_" + to_string(i);
			Noeud* fils = creerNoeud(f->getForme(i), newID);  //appel recursif créant le sous arbre
			g->ajouterFils(fils); //lien avec la racine 
		}
		return g;
	}
	/**
	* @brief enregistrment d'une forme2D
	*/
	virtual Noeud * creerNoeud(const Forme2D* f,string id)const {
			if (f->whoAmI() > 0) {
				FormeSimple* f2 = (FormeSimple*)f;
				return creerNoeud(f2,id);
			}
			else {
				GroupeForme* f2 = (GroupeForme*)f;
				return creerNoeud(f2,id);
			}
	}

	void enregistrerArbre(Noeud* racine, FILE * file)const {
		//enregistrement de l'arborescence
		string requete;
		if (racine->nbFils() > 0) { // c'est un noeud
			requete = racine->id + ":N;"; // N signifie noeud
			for (int i = 0; i < racine->nbFils(); i++) {
				requete += racine->getFils(i)->id + ";"; // pour un noeud, on indiquera seulement l'id de ses fils
			}
			requete += '\n';
			fputs(requete.c_str(), file); // la requete pour ce noeud sera ecrite avant celle de ses fils
			for (int i = 0; i < racine->nbFils(); i++) {
				enregistrerArbre(racine->getFils(i), file); // appel recursif pour enregistrer tout les fils 
			}
		}
		else { // c'est une feuille
			requete = racine->id + ":F;"+racine->data + '\n'; // F signifie feuille
			fputs(requete.c_str(), file);
		}
		cout << requete << endl;
	}
	/**
	* @brief elle permet d'enregistrer un repere avec toutes les formes qui y sont dessinées
	*/
	void EnregistrerPlan(const Plan2D& plan) {
		FILE* outfile;
		cout << "Enregistrement du plan..." << endl;
		outfile = fopen(nomFichier.c_str(), "w");
		Noeud* n = new Noeud("0");
		for (int i = 0; i < plan.nbFormes(); i++) {
			string newID = n->id + "_" + to_string(i);
			n->ajouterFils(creerNoeud(plan.getForme(i),newID)); //la racine sera le premier noeud 
		}
		enregistrerArbre(n,outfile);
		fclose(outfile);
		cout << "Enregistrement du plan terminé." << endl;
	}
};

