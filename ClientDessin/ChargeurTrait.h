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
	/**
	* @brief charger un trait si la requete correspond a une requete de dessin de trait
	*/
	Forme2D* chargerForme(const string requete)const {
		//format d un trait:  1;nbpoints;x1,y1;x2,y2;couleur 
		// la couleur est au format r,g,b
		int pos = 0;
		while (requete[pos] != ':') {//positionnement apres l'id
			pos++;
		}
		pos++;
		if (requete[pos] != '1') {
			return NULL;
		}
		else {
			pos = pos + 4; // position dans la lecture de la requete pour lire les coordoonees des points
			string x;
			string y;
			while (requete[pos] != ',') { //recuperer le x1
				x += requete[pos];
				pos++;
			}
			pos++;
			while (requete[pos] != ';') { //recuperer le y1 
				y += requete[pos];
				pos++;
			}
			pos++;
			Vecteur2D p1(stod(x), stod(y)); // construction du point1
			x.clear(); y.clear();
			while (requete[pos] != ',') { // recuperer le x2
				x += requete[pos];
				pos++;
			}
			pos++;
			while (requete[pos] != ';') { // recuperer le y2
				y += requete[pos];
				pos++;
			}
			pos++;
			Vecteur2D p2(stod(x), stod(y)); //construction du 2 eme point
			//recuperation de la couleur
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

