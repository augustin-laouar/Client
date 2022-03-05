#pragma once
#include "ChargeurFormeCOR.h"
#include "Cercle.h"
class ChargeurCercle : public ChargeurFormeCOR
{
protected:
	/**
	* @brief charger un cercle a partir d'un fichier grace a son identifiant
	* @param id : identifiant de la forme dans le fichier
	* @param fichier : nom du fichier 
	*/
	Forme2D* chargerForme(const string fichier, const string id)const {
			string buffer = trouverForme(fichier, id);
			int i = 0;
			//on saute l'id
			while (buffer[i] != ':' && buffer[i] != '\0') {
				i++;
			}
			i++;
			if (buffer[i] != 'F' || buffer[i + 2] != '2') { // ce n'est pas une forme ou un cercle 
				return NULL;
			}
			i += 4;
			string rayon;
			while (buffer[i] != ';') {
				rayon += buffer[i];
				i++;
			}
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
			return new Cercle(Vecteur2D(stod(x), stod(y)), stod(rayon), c);
		}
public:
	ChargeurCercle(ChargeurFormeCOR* suivant = NULL) {
		this->suivant = suivant;
	}
	
		
};

