#pragma once
#include "VisitorFormeSimple.h"
#include "VisitorForme2D.h"
class Dessin :public VisitorForme2D,public VisitorFormeSimple
{
	virtual FormeSimple* visit(const Polygone* f) {
		
		
	}
	virtual FormeSimple* visit(const Trait* f) {

	}
	virtual FormeSimple* visit(const Cercle* f) {

	}
	virtual Forme2D* visit(const FormeSimple* f) {

	}
	virtual Forme2D* visit(const GroupeForme* f) {

	}

	
};

