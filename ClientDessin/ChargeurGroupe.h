#pragma once
#include "ChargeurFormeCOR.h"
#include "GroupeForme.h"
#include "ChargeurPolygone.h"
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
class ChargeurGroupe : public ChargeurFormeCOR
{
protected :
	/**
	* @brief charger une forme simple a partir d'un fichier grace a son identifiant
	* @param id : identifiant de la forme dans le fichier
	* @param fichier : nom du fichier
	*/
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
		if (buffer[i + 1] != 'N') {
			return NULL;
		}
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
		cout << ids.size() << endl;
		for (size_t j = 1; j < ids.size(); j++) {
			g->ajouterForme(gr->charger(fichier, ids[j]));
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

