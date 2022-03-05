#pragma once
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
#include "ChargeurGroupe.h"
#include "ChargeurPolygone.h"
#include "Plan2D.h"
#pragma warning(disable : 4996)
class Chargeur
{
public :
	Forme2D* charger(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return cp->charger(fichier);
	}
	Trait* chargerTrait(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Trait*>(cp->charger(fichier));
	}
	Cercle* chargerCercle(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Cercle*>(cp->charger(fichier));
	}
	Polygone* chargerPolygone(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<Polygone*>(cp->charger(fichier));
	}
	GroupeForme* chargerGroupe(string fichier) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return dynamic_cast<GroupeForme*>(cp->charger(fichier));
	}
	Plan2D* chargerPlan(string fichier) {
	}
};

