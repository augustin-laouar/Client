#pragma once
#include "ChargeurForme.h"
class ChargeurFormeCOR
{
protected :
	ChargeurFormeCOR* suivant;
public :
	ChargeurFormeCOR(ChargeurFormeCOR* suivant) {
		this->suivant = suivant;
	}
	ChargeurFormeCOR() {
		this->suivant = NULL;
	}
	/**
	* @brief methode pour COR 
	*/
	Forme2D* charger(const string requete)const {
		if (requete.size() == 0)
			return NULL;
		Forme2D* res = this->chargerForme(requete);
		if (res != NULL) {
			return res;
		}
		else {
			if (suivant != NULL) {
				return this->suivant->charger(requete);
			}
			else {
				return NULL;
			}
		}
	}
	/**
	* @brief charger une forme en fonction d'une requete en format string 
	*/
	virtual Forme2D* chargerForme(const string requete)const = 0;
};

