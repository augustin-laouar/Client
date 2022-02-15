#include "Cercle.h"
#include "VisitorForme2D.h"

void Cercle::accept(const VisitorForme2D* v) { v->visit(this); }

