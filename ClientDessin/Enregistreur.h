#pragma once
#include "VisitorForme2D.h"
#include "Plan2D.h"
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
class Enregistreur : public VisitorForme2D
{	
private:
	string nomFichier;
	string ident;
public:
	Enregistreur(string nom ,string id) {
		nomFichier = nom;
		ident = id;
	}
	string getNomFichier()const {
		return nomFichier;
	}
	string getIdent()const {
		return ident;
	}
	void setNomFichier(string nom) {
		nomFichier = nom;
	}
	void setIdent(string id) {
		for (size_t i = 0; i < id.size(); i++) {
			if (id[i] == ':') {
				throw Erreur("Impossible d'utiliser le caractere ':' dans un identifiant");
			}
		}
		if (id.size() > 20) {
			throw Erreur("Identifiant de forme trop long");
		}
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "r");
		char compare[25]; // 25 car taille max pour un id = 20 + 1 pour le caractere de fin ":" + 2 si c'est une forme d'un groupe ( _i ) + 2 si forme d'un plan
		string IdRecupere;
		while (fgets(compare, 25, outfile)) {
			for (int i = 0; compare[i] != ':' && compare[i] != ']' && compare[i] != '}'; i++) {
				IdRecupere += compare[i]; //recupere l'id char par char
			}
			if( IdRecupere == id ){ 
				throw Erreur("Id deja present dans le fichier");
			}
			IdRecupere.clear();
		}
		fclose(outfile);
		ident = id;
	}
	virtual void visit(const Polygone* f) const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a");
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}

		string requete = ident + ":3;";
		requete += to_string(f->getNbPoint()) + ";";
		for (int i = 0; i < f->getNbPoint(); i++) {
			requete += to_string(f->getPoint(i).x) + ",";
			requete += to_string(f->getPoint(i).y) + ";";
		}
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile);
		fclose(outfile);
	}
	/**
	* @brief methode pour le design pattern visitor pour le dessin d'un Trait format requete :1;nombreDePoints;coordonneesSepareeParDesVirgules;couleur
	*/

	virtual void visit(const Trait* f) const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a");
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}
		string requete = ident + ":1;";
		requete += to_string(f->getNbPoint()) + ";";
		requete += "2;";
		requete += to_string(f->getP1().x) + "," + to_string(f->getP1().y) +";";
		requete += to_string(f->getP2().x) + "," + to_string(f->getP2().y)+";";
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile);
		fclose(outfile);

	}

	/**
	* @brief methode pour le design pattern visitor pour le dessin d'un Cercle format requete :2;nombreDePoints;rayon;centre(x,y);couleur
	*/
	virtual void visit(const Cercle* f)const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a");
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}
		string requete =  ident + ":1;";
		requete += to_string(f->getNbPoint()) + ";";
		requete += "2;";
		requete += to_string(f->getRayon()) +";";
		requete += to_string(f->getCentre().x) + "," + to_string(f->getCentre().y) + ";";
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile);
		fclose(outfile);

	}

	/**
	* @brief methode pour le dessin d'une forme simple
	*/

	virtual void visit(const FormeSimple* f)const {

		switch (f->whoAmI()) {
		case 10: {
			Cercle* c = (Cercle*)f;
			visit(c);
		}
			   break;
		case 11: {
			Polygone* p = (Polygone*)f;
			visit(p);
		}
			   break;
		case 12: {
			Trait* t = (Trait*)f;
			visit(t);
		}
		}

	}
	/**
	* @brief methode pour le dessin d'un groupe de formes
	*/
	virtual void visit(const GroupeForme* f)const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a");
		string requete = ident + ":[\n";
		fputs(requete.c_str(), outfile);
		fclose(outfile);
		for (size_t i = 0; i < f->getNbForme(); i++) { 
			string newIdent = ident + "_";
			newIdent += to_string(i);
			Enregistreur intermediaire(this->nomFichier, newIdent);
			intermediaire.visit(f->getForme(i));
		}
		outfile = fopen(nomFichier.c_str(), "a");
		fputs("]\n", outfile);
		fclose(outfile);
	}
	/**
	* @brief methode pour le dessin d'une forme2D en fonction du type de la forme
	*/
	virtual void visit(const Forme2D* f)const {
		try {
			if (f->whoAmI() > 0) {
				FormeSimple* f2 = (FormeSimple*)f;
				visit(f2);
			}
			else {
				GroupeForme* f2 = (GroupeForme*)f;
				visit(f2);
			}
		}
		catch(const Erreur e) {
			cout << e.what() << endl;
		}
	}
	void Enregistrer(const Plan2D& plan) {
		FILE* outfile;
		cout << "Enregistrement du plan..." << endl;
		outfile = fopen(nomFichier.c_str(), "a");
		string requete = ident + ":{\n";
		fputs(requete.c_str(), outfile);
		fclose(outfile);
		for (size_t i = 0; i <plan.nbFormes(); i++) {
			string newIdent = ident + "_";
			newIdent += to_string(i);
			Enregistreur intermediaire(this->nomFichier, newIdent);
			intermediaire.visit(plan.getForme(i));
		}
		outfile = fopen(nomFichier.c_str(), "a");
		fputs("}\n", outfile);
		fclose(outfile);
		cout << "Enregistrement du plan terminé." << endl;
	}
};

