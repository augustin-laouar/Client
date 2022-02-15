#include "Polygone.h"
#include "VisitorForme2D.h"



//Forme2D* Polygone::accept(const VisitorForme* v)const { return v->visit(this); }
void Polygone::accept(const VisitorForme2D* v) { v->visit(this); }

