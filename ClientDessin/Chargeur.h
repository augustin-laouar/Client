#pragma once
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
#include "ChargeurGroupe.h"
#include "ChargeurPolygone.h"
#include "Plan2D.h"
#pragma warning(disable : 4996)
class Chargeur
{
protected :
	/**
	* @brief charger des formes a partir d'un fichier en utilisant le design pattern chain of responsability
	*/
	Forme2D* charger(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return cp->charger(fichier);
	}
public :
	
	/**
	* @brief charger un trait a partir d'un fichier en utilisant le design pattern COR
	*/
	Trait* chargerTrait(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Trait*>(cp->charger(fichier));
	}
	/**
	* @brief charger un Cercle a partir d'un fichier en utilisant le design pattern COR
	*/
	Cercle* chargerCercle(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Cercle*>(cp->charger(fichier));
	}
	/**
	* @brief charger un polygone a partir d'un fichier en utilisant le design pattern COR
	*/
	Polygone* chargerPolygone(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Polygone*>(cp->charger(fichier));
	}
	/**
	* @brief charger un groupe de formes a partir d'un fichier en utilisant le design pattern COR
	*/
	GroupeForme* chargerGroupe(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<GroupeForme*>(cp->charger(fichier));
	}
	/**
	* @brief charger un plan a partir d'un fichier en utilisant le design pattern COR
	*/
	Plan2D* chargerPlan(string fichier) {
		Plan2D* res = new Plan2D;
		FILE* f = fopen(fichier.c_str(), "r");
		char buffer[BUFSIZ];
		fgets(buffer, BUFSIZ, f);
		fclose(f);
		vector<string>ids;
		int i = 0;
		while (buffer[i] != ':') // on saute l'id
			i++;
		if (buffer[i + 1] != 'N') {
			throw Erreur("Impossible de charger un plan a partir d'un fichier de forme simple");
		}
		i += 3;
		string idCurr;
		while (buffer[i] != '|') { // on recupere les id des formes du plan
			while (buffer[i] != ';') {
				idCurr += buffer[i];
				i++;
			}
			i++;
			ids.push_back(idCurr);
			idCurr.clear();
		}
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		for (int j = 0; j < (int)ids.size(); j++) {
			res->ajouterForme(cp->charger(fichier, ids[j]));
		}
		return res;
	}
};

