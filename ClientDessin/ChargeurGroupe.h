#pragma once
#include "ChargeurFormeCOR.h"
#include "GroupeForme.h"
#include "ChargeurPolygone.h"
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
class ChargeurGroupe : public ChargeurFormeCOR
{
public:
	ChargeurGroupe() {
		this->suivant = NULL;
	}
	ChargeurGroupe(ChargeurFormeCOR * suivant) {
		this->suivant = suivant;
	}
	Forme2D* chargerForme(const string requete)const {
		if (requete[0] != '[') {
			return NULL;
		}
		else {
			vector<string> requetes;
			int i = 1;
			string aux;
			while (requete[i] != ']') {
				while (requete[i] != '\n') {
					aux += requete[i];
					i++;
				}
				requetes.push_back(aux);
				aux.clear();
				i++;
			}
			vector<Forme2D*>formes;
			ChargeurPolygone* cp = new ChargeurPolygone;
			ChargeurTrait* ct = new ChargeurTrait(cp);
			ChargeurCercle* cc = new ChargeurCercle(ct);
			ChargeurGroupe* cg = new ChargeurGroupe(cc);

			for (int i = 0; i < requetes.size(); i++) {
				Forme2D* f = cg->charger(requetes[i]);
				if (f == NULL) {
					throw new Erreur("Forme non reconnu");
				}
				formes.push_back(f);
			}
			GroupeForme* g = new GroupeForme(formes[0]->getCouleur());
			for (int i = 0; i < formes.size(); i++) {
				g->ajouterForme(formes[i]);
			}
			return g;
		}
		
	}
};

