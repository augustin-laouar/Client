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
	/**
	* @brief permet de charger une forme a partir d'une chaine de caractere 
	*/
	Forme2D* chargerForme(const string requete)const {
		int pos = 0;
		while (requete[pos] != ':') {//positionnement apres l'id
			pos++;
		}
		pos++;
		if (requete[pos] != '[') {  //on verifie si la requete commence par [ cela indique que c'est un groupe de formes
			return NULL;
		}
		else {
			vector<string> requetes;  //liste de requetes 
			int i = pos+1;
			string aux;
			while (requete[i] != ']') { // parcours tant qu'on est pas a la fin du groupe 
				cerr << requete[i] << endl;
				while (requete[i] != '\n' && requete[i] != '\0') { //une forme par ligne
					if (requete[i] == '[') { //group dans un groupe
						while (requete[i] != ']') {
							aux += requete[i];
							i++;
						}
						aux += requete[i];
					}
					else {
						aux += requete[i];
						i++;
					}
					
				}
				requetes.push_back(aux);
				aux.clear();
				i++;
			}
			vector<Forme2D*>formes; //liste de formes qui contiendra les formes se trouvant dans le groupe
			ChargeurPolygone* cp = new ChargeurPolygone;
			ChargeurTrait* ct = new ChargeurTrait(cp);
			ChargeurCercle* cc = new ChargeurCercle(ct);
			ChargeurGroupe* cg = new ChargeurGroupe(cc);

			for (int i = 0; i < requetes.size(); i++) { // charger les formes 
				Forme2D* f = cg->charger(requetes[i]);
				if (f == 0) {
					throw new Erreur("Forme non reconnu");
				}
				else {
					formes.push_back(f);

				}
			}
			GroupeForme* g = new GroupeForme(formes[0]->getCouleur());
			for (int i = 0; i < formes.size(); i++) {
				g->ajouterForme(formes[i]);
			}
			return g;
		}
		
	}
};

