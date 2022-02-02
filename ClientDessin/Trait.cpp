#include "Trait.h"

Forme* Trait::accept(const VisitorForme* v)const { return v->visit(this); }