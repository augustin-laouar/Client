#include "Trait.h"
#include "VisitorForme.h"

Forme2D* Trait::accept(const VisitorForme* v)const { return v->visit(this); }