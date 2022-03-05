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
	Forme2D* chargerForme(FILE * f)const {
		char buffer[BUFSIZ];
		while (fgets(buffer, BUFSIZ, f)) {
			int i = 0;
			//on saute l'id
			while (buffer[i] != ':' && buffer[i] != '\0') {
				i++;
			}
			i++;
			if (buffer[i] != 'F' || buffer[i + 2] != '1') { // ce n'est pas une forme ou un cercle 
				return NULL;
			}
			i += 2;
			string x, y;
			i++;
			while (buffer[i] != ',') {
				x += buffer[i];
				i++;
			}
			i++;
			while (buffer[i] != ';') {
				y += buffer[i];
				i++;
			}
			Vecteur2D v1(stoi(x), stoi(y));
			i++;
			x.clear();
			y.clear();
			while (buffer[i] != ',') {
				x += buffer[i];
				i++;
			}
			i++;
			while (buffer[i] != ';') {
				y += buffer[i];
				i++;
			}
			Vecteur2D v2(stoi(x), stoi(y));
			i++;
			string r, g, b;
			while (buffer[i] != ',') {
				r += buffer[i];
				i++;
			}
			i++;
			while (buffer[i] != ',') {
				g += buffer[i];
				i++;
			}
			i++;
			while (buffer[i] != ',') {
				b += buffer[i];
				i++;
			}
			Couleur c(stoi(r), stoi(g), stoi(b));
			return new Trait(v1, v2, c);
		}
	}
};

