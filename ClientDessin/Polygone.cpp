#include "Polygone.h"
#include "VisitorFormeSimple.h"



//Forme2D* Polygone::accept(const VisitorForme* v)const { return v->visit(this); }
FormeSimple* Polygone::accept(const VisitorFormeSimple* v)const { return v->visit(this); }

