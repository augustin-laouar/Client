#include "Trait.h"
#include "VisitorFormeSimple.h"

//Forme2D* Trait::accept(const VisitorForme* v)const { return v->visit(this); }
FormeSimple* Trait::accept(const VisitorFormeSimple* v)const { return v->visit(this); }

