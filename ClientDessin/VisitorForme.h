pragma once
#include "FormeSimple.h"
#include "Polygone.h"
#include "Trait.h"
#include "Cercle.h"
using namespace std;
class VisitorForme
{
public : 
	virtual FormeSimple* visit(const Polygone* p) const = 0;
	virtual FormeSimple* visit(const Cercle* c) const = 0;
	virtual FormeSimple*  visit(const Trait* t) const = 0;
	

};

