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
	/**
	* @brief getter de nom de fichier 
	*/
	string getNomFichier()const {
		return nomFichier;
	}
	/**
	* @brief getter de l'identifiant de la forme 
	*/
	string getIdent()const {
		return ident;
	}
	/**
	* @brief setter de nom de fichier
	*/
	void setNomFichier(string nom) {
		nomFichier = nom;
	}
	/**
	* @brief setter de l'identifiant
	*/
	void setIdent(string id) {
		
		//verifications
		for (size_t i = 0; i < id.size(); i++) { 
			if (id[i] == ':') {
				throw Erreur("Impossible d'utiliser le caractere ':' dans un identifiant");
			}
		}
		if (id.size() > 20) { //limite de taille 
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
	/**
	* @brief enregistrement d'un polygone dans un fichier
	*/
	virtual void visit(const Polygone* f) const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a"); //ouverture fichier
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}

		string requete = ident + ":3;"; // debut de la construction de la requete
		requete += to_string(f->getNbPoint()) + ";";
		for (int i = 0; i < f->getNbPoint(); i++) { //ajout des coordonnes des points 
			requete += to_string(f->getPoint(i).x) + ",";
			requete += to_string(f->getPoint(i).y) + ";";
		}
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile); //ecriture de la requete dans le fichier
		fclose(outfile);
	}
	/**
	* @brief enregistrement d'un trait dans un fichier 
	*/

	virtual void visit(const Trait* f) const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a"); //ouverture fichier
		
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}
		string requete = ident + ":1;";  // debut de construction de la requete 
		requete += to_string(f->getNbPoint()) + ";";
		requete += to_string(f->getP1().x) + "," + to_string(f->getP1().y) +";";
		requete += to_string(f->getP2().x) + "," + to_string(f->getP2().y)+";";
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile); //ecrityre de la requete dans le fichier
		fclose(outfile);

	}

	/**
	* @brief enregistrement d'un cercle dans le fichier 
	*/
	virtual void visit(const Cercle* f)const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a"); //ouverture du fichier
		if (outfile == NULL) {
			throw Erreur("Ouverture du ficher");
		}
		string requete =  ident + ":2;";  // debut de la construction de la requete 
		requete += to_string(f->getNbPoint()) + ";"; 
		requete += to_string(f->getRayon()) +";";
		requete += to_string(f->getCentre().x) + "," + to_string(f->getCentre().y) + ";";
		requete += f->getCouleur().toString() + "\n";
		fputs(requete.c_str(), outfile); //
		fclose(outfile);

	}

	/**
	* @brief enregistrement de forme simple 
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
	* @brief enregistrement d'un groupe de forme 
	*/
	virtual void visit(const GroupeForme* f)const {
		FILE* outfile;

		outfile = fopen(nomFichier.c_str(), "a"); //ouverture du fichier
		string requete = ident + ":[\n"; //ajout de marqueur de debut de groupes
		fputs(requete.c_str(), outfile);
		fclose(outfile);
	
		for (size_t i = 0; i < f->getNbForme(); i++) {  //parcour de toutes les formes pour les enregistrer
			string newIdent = ident + "_";
			newIdent += to_string(i);
			Enregistreur intermediaire(this->nomFichier, newIdent);
			intermediaire.visit(f->getForme(i));
		}
		outfile = fopen(nomFichier.c_str(), "a");
		fputs("]\n", outfile); //mettre le marqueur de fin de groupe
		fclose(outfile);
	}
	/**
	* @brief enregistrment d'une forme2D
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
	/**
	* @brief elle permet d'enregistrer un repere avec toutes les formes qui y sont dessinées 
	*/
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

