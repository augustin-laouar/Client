#pragma once
#include "ChargeurFormeCOR.h"
#include "Trait.h"
class ChargeurTrait : public ChargeurFormeCOR
{
public:
	ChargeurTrait() {
		this->suivant = NULL;
	}
	ChargeurTrait(ChargeurFormeCOR* suivant) {
		this->suivant = suivant;
	}
	Forme2D* chargerForme(const string requete)const {
		if (requete[0] != '1') {
			return NULL;
		}
		else {
			int pos = 4; // position dans la lecture de la requete
			string x;
			string y;
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
			Vecteur2D p1(stod(x), stod(y));
			x.clear(); y.clear();
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
			Vecteur2D p2(stod(x), stod(y));
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
			return new Trait(p1, p2, c);
		}
	}
};

