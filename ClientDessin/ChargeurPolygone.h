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
	/**
	* @brief permet de charger un polygone a partir d une requete si la requete y correspond
	*/
	Polygone* chargerForme(const string requete)const {
		// structure d un polygone     3;nbPoints;x1,y1;x2,y2;...;couleur
		if (requete[0] != '3') {  // le 3 est l'identifiant d'un polygone
			return NULL;
		}
		else {
			int pos = 2; // position dans la lecture de la requete
			string nbp;
			while (requete[pos] != ';') { // le ; est un separateur dans nos requetes 
				nbp += requete[pos];
				pos++;
			}
			pos++;
			int nbPoint = stoi(nbp); 

			string x;
			string y;
			vector<Vecteur2D> listePoint;
			for (int i = 0; i < nbPoint; i++) {  // on parcours grace aux nombre de points recupéré
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
			//format couleur cest : r,g,b exemple  : 255,255,255
			while (requete[pos] != ',') {  // on recupere le r de la requete
				r += requete[pos];
				pos++;
			}
			pos++; // on avance d'un pas a cause de la virgule
			while (requete[pos] != ',') { //on recupere le g
				g += requete[pos];
				pos++;
			}
			pos++; 
			while (requete[pos] != '\n' && requete[pos] != '\0') { //on recupere le b
				b += requete[pos];
				pos++;
			}
			Couleur c(stoi(r), stoi(g), stoi(b));
			return new Polygone(listePoint, c);
		}
	}
};

