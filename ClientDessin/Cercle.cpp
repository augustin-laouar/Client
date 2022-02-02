#include "Cercle.h"

Forme* Cercle::accept(const VisitorForme* v)const { return v->visit(this); }
