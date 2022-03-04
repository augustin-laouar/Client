
#pragma once
#include "FormeSimple.h"
#include "Forme2D.h"
#include "GroupeForme.h"
#include "Polygone.h"
#include "Cercle.h"
#include "Trait.h"
#include "Noeud.h"
class VisitorForme2D
{	
public:
		virtual ~VisitorForme2D() {}
		virtual Noeud* visit(const FormeSimple* f)const = 0;
		virtual	Noeud* visit(const GroupeForme* f)const = 0;
		virtual Noeud* visit(const Polygone* f)const = 0;
		virtual Noeud* visit(const Trait* f)const = 0;
		virtual Noeud* visit(const Cercle* f)const = 0;
	};



