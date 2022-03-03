#pragma once
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
#include "ChargeurGroupe.h"
#include "ChargeurPolygone.h"
#include "Plan2D.h"
class Chargeur
{
public :
	string trouverRequete(FILE*fd,string id) {
		char buffer[BUFSIZ];
		string comparateur;
		while (fgets(buffer, BUFSIZ, fd)) {
			for (int i = 0; buffer[i] != ':'; i++) {
				comparateur += buffer[i]; //recupere l'id char par char
			}
			if (id == comparateur) {
				int iterateur = comparateur.size()+1;
				string requete;
				while (buffer[iterateur] != '\n' && buffer[iterateur] != '\0') {
					requete[iterateur] = buffer[iterateur];
					iterateur++;
				}
				return requete;
			}
			comparateur.clear();
		}
		throw Erreur("Id non trouvé");
	}
	Forme2D* traiteRequete(string requete) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return cp->charger(requete);
	}
};

