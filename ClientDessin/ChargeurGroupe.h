#pragma once
#include "ChargeurFormeCOR.h"
#include "GroupeForme.h"
#include "ChargeurPolygone.h"
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
class ChargeurGroupe : public ChargeurFormeCOR
{
protected :
	Forme2D* chargerForme(const string fichier,const string id)const {
 		ChargeurTrait* t = new ChargeurTrait;
		ChargeurCercle* c = new ChargeurCercle(t);
		ChargeurPolygone* p = new ChargeurPolygone(c);
		ChargeurGroupe* gr = new ChargeurGroupe(p);
		string buffer = trouverForme(fichier, id);
		vector<string>ids;
		int i = 0;
		while (buffer[i] != ':') // on saute l'id
			i++;
		i+= 3;
		string idCurr;
		while (buffer[i] != '|') { // on recupere les id des formes du groupe
			while (buffer[i] != ';') {
				idCurr += buffer[i];
				i++;
			}
			i++;
			ids.push_back(idCurr);
			idCurr.clear();
		}
		Forme2D* premiereForme = gr->charger(fichier, ids[0]); // on charge lla premire forme pour savoir quel est la couleur du groupe
		GroupeForme* g = new GroupeForme(premiereForme->getCouleur());
		g->ajouterForme(premiereForme);
		for (size_t j = 1; i < ids.size(); j++) {
			g->ajouterForme(gr->charger(fichier, ids[i]));
		}
		return g;
		
	}
public:
	ChargeurGroupe() {
		this->suivant = NULL;
	}
	ChargeurGroupe(ChargeurFormeCOR * suivant) {
		this->suivant = suivant;
	}
};

