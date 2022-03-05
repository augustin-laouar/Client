#pragma once
#include "ChargeurFormeCOR.h"
#include "Polygone.h"
class ChargeurPolygone : public ChargeurFormeCOR
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
			if (buffer[i] != 'F' || buffer[i + 2] != '3') { // ce n'est pas une forme ou un polygone 
				return NULL;
			}
			i += 4;
			string nbFormeString;
			while (buffer[i] != ';') {
				nbFormeString = buffer[i];
				i++;
			}
			int nbForme = stoi(nbFormeString);
			string x, y;
			i++;
			vector<Vecteur2D>listePoint;
			for (int j = 0; j < nbForme; j++) {
				while (buffer[i] != ',') {
					x += buffer[i];
					i++;
				}
				i++;
				while (buffer[i] != ';') {
					y += buffer[i];
					i++;
				}
				Vecteur2D v(stod(x), stod(y));
				listePoint.push_back(v);
				i++;
				x.clear();
				y.clear();
			}
			
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
			return new Polygone(listePoint, c);
		}
public :
	ChargeurPolygone(ChargeurFormeCOR* suivant = NULL) {
		this->suivant = suivant;
	}

};

