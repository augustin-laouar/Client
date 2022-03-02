#pragma once
#include "ChargeurFormeCOR.h"
#include "Cercle.h"
class ChargeurCercle : public ChargeurFormeCOR
{
public:
	ChargeurCercle() {
		this->suivant = NULL;
	}
	ChargeurCercle(ChargeurFormeCOR* suivant) {
		this->suivant = suivant;
	}
	Forme2D* chargerForme(const string requete)const {
		//char buffer[BUFSIZ];
		//string comparateur;
		//while (fgets(buffer, BUFSIZ, fd)) {
		//	for (int i = 0; buffer[i] != ':' && buffer[i] != ']' && buffer[i] != '}'; i++) {
		//		comparateur += buffer[i]; //recupere l'id char par char
		//	}
		//	if (id == comparateur) {
		//		int iterateur = comparateur.size()+1;

		//	}
		//	comparateur.clear();
		//}
		//return NULL;
		if (requete[0] != '2') {
			return NULL;
		}
		else {
			int pos = 4; // position dans la lecture de la requete
			string rayon;
			while (requete[pos] != ';') {
				rayon += requete[pos];
				pos++;
			}
			double rayonD = stod(rayon);
			pos++;
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
			Vecteur2D centre(stod(x), stod(y));
			string r, g, b;
			while (requete[pos] != ',') {
				r += requete[pos];
			}
			pos++;
			while (requete[pos] != ',') {
				g += requete[pos];
			}
			pos++;
			while (requete[pos] != '\n') {
				g += requete[pos];
			}
			Couleur c(stoi(r), stoi(g), stoi(b));
			return new Cercle(centre,rayonD,c);
		}
	}
};

