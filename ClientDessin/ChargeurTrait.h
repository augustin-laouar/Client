#pragma once
#include "ChargeurFormeCOR.h"
#include "Trait.h"
class ChargeurTrait : public ChargeurFormeCOR
{
protected :
	Forme2D* chargerForme(const string fichier, const string id)const {
		string buffer = trouverForme(fichier, id);
		int i = 0;
		//on saute l'id
		while (buffer[i] != ':' && buffer[i] != '\0') {
			i++;
		}
		i++;
		if (buffer[i] != 'F' || buffer[i + 2] != '1') { // ce n'est pas une forme ou un cercle 
			return NULL;
		}
		i += 4;
		string x, y;
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
		while (buffer[i] != '|') {
			b += buffer[i];
			i++;
		}
		Couleur c(stoi(r), stoi(g), stoi(b));
		return new Trait(v1, v2, c);
	}
public:
	ChargeurTrait(ChargeurFormeCOR* suivant = NULL) {
		this->suivant = suivant;
	}
	
};

