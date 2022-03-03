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
	Forme2D* charger(const string requete)const {
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
	virtual Forme2D* chargerForme(const string requete)const = 0;
};

