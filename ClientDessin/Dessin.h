#pragma once
#include "VisitorForme2D.h"
class Dessin :public VisitorForme2D
{
	virtual Forme2D* visit(const FormeSimple* f) {

	}
	virtual Forme2D* visit(const GroupeForme* f) {

	}
};

