#pragma once
#include "Forme2D.h"
#include "FormeSimple.h"
class GroupeForme : public Forme2D
{
protected:
	vector<Forme2D*>ListeForme;
public :
	GroupeForme(int couleur) : Forme2D(couleur) {}
	virtual ~GroupeForme() {

	}
};

