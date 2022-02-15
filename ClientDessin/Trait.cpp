#include "Trait.h"
#include "VisitorForme2D.h"

//Forme2D* Trait::accept(const VisitorForme* v)const { return v->visit(this); }
void Trait::accept(const VisitorForme2D* v) { v->visit(this); }

