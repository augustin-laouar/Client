#pragma once
#include "ChargeurFormeCOR.h"
#include "Polygone.h"
class ChargeurPolygone : public ChargeurFormeCOR
{
public :
	ChargeurPolygone() {
		this->suivant = NULL;
	}
	ChargeurPolygone(ChargeurFormeCOR* suivant) {
		this->suivant = suivant;
	}
	Forme2D* chargerForme(const string requete)const {
		if (requete[0] != '3') {
			return NULL;
		}
		else {
			int pos = 2; // position dans la lecture de la requete
			string nbp;
			while (requete[pos] != ';') {
				nbp += requete[pos];
				pos++;
			}
			pos++;
			int nbPoint = stoi(nbp);

			string x;
			string y;
			vector<Vecteur2D> listePoint;
			for (int i = 0; i < nbPoint; i++) {
				while (requete[pos] != ',') {
					x += requete[pos];
					pos++;
				}
				pos++;
				while (requete[pos] != ';') {
					y += requete[pos];
					pos++;
				}
				pos++;
				Vecteur2D p(stod(x), stod(y));
				listePoint.push_back(p);
				x.clear(); y.clear();
			}
			string r, g, b;
			while (requete[pos] != ',') {
				r += requete[pos];
				pos++;
			}
			pos++;
			while (requete[pos] != ',') {
				g += requete[pos];
				pos++;
			}
			pos++;
			while (requete[pos] != '\n' && requete[pos] != '\0') {
				b += requete[pos];
				pos++;
			}
			Couleur c(stoi(r), stoi(g), stoi(b));
			return new Polygone(listePoint, c);
		}
	}
};

