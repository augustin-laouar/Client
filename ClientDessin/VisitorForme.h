#pragma once
#include "Forme.h"
#include "Polygone.h"
#include "Trait.h"
#include "Cercle.h"
using namespace std;
class VisitorForme
{
public : 
	virtual Forme* visit(const Polygone* p) const = 0;
	virtual Forme* visit(const Cercle* c) const = 0;
	virtual Forme*  visit(const Trait* t) const = 0;
	

};

