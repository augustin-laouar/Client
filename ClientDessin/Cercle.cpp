#include "Cercle.h"
#include "VisitorFormeSimple.h"

FormeSimple* Cercle::accept(const VisitorFormeSimple* v)const { return v->visit(this); }

