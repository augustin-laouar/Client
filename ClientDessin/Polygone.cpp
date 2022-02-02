#include "Polygone.h"



Forme* Polygone::accept(const VisitorForme* v)const { return v->visit(this); }
