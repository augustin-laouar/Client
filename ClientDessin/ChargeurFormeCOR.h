#pragma once
#include "ChargeurForme.h"
class ChargeurFormeCOR : public ChargeurForme
{
protected :
	ChargeurFormeCOR* suivant;
	virtual Forme2D* chargerForme(const string fichier, const string id)const = 0;
public :
	ChargeurFormeCOR(ChargeurFormeCOR* suivant = NULL) {
		this->suivant = suivant;
	}
	/**
	* @brief methode pour COR 
	*/
	Forme2D* charger(const string fichier, const string id ="0")const {
		if (fichier.size() == 0)
			return NULL;
		Forme2D* res = this->chargerForme(fichier,id);
		if (res != NULL) {
			return res;
		}
		else {
			if (suivant != NULL) {
				return this->suivant->charger(fichier, id);
			}
			else {
				return NULL;
			}
		}
	}
	virtual string trouverForme(const string fichier,const string id)const {
		FILE* f = fopen(fichier.c_str(), "r");
		char buffer[BUFSIZ];
		string res;
		while (fgets(buffer,BUFSIZ,f)) { // tant qu'on a pas trouvé la forme ou que l'on est pas en fin de fichier
			int i = 0;
		//scout << buffer << endl;
			string idFormeCurr;
			while (buffer[i] != ':') { // on recupere l'id de la forme a cette ligne
				idFormeCurr += buffer[i];
				i++;
			}
			if (idFormeCurr == id) { // on a trouve l'id
				res = buffer;
				fclose(f);
				return res;
				
			}
			idFormeCurr.clear();
		}
		fclose(f);
		if (res.size() == 0) {
			throw Erreur("Aucune forme correspondante a cette ID");
		}
	}

};

