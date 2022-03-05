#pragma once
#include "ChargeurForme.h"
class ChargeurFormeCOR
{
protected :
	ChargeurFormeCOR* suivant;
public :
	ChargeurFormeCOR(ChargeurFormeCOR* suivant = NULL) {
		this->suivant = suivant;
	}
	/**
	* @brief methode pour COR 
	*/
	Forme2D* charger(const string fichier)const {
		if (fichier.size() == 0)
			return NULL;
		FILE* f = fopen(fichier.c_str(), "r");
		Forme2D* res = this->chargerForme(f);
		fclose(f);
		if (res != NULL) {
			return res;
		}
		else {
			if (suivant != NULL) {
				return this->suivant->charger(fichier);
			}
			else {
				return NULL;
			}
		}
	}
	/**
	* @brief charger une forme en fonction d'une requete en format string 
	*/
	virtual Forme2D* chargerForme(const FILE * f)const = 0;
};

