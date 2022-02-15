#include "FormeSimple.h"
#include "Cercle.h"
#include "Trait.h"
#include "Polygone.h"
class VisitorFormeSimple
{
public:
	virtual FormeSimple* visit(const Polygone* f)const = 0;
	virtual FormeSimple* visit(const Trait* f)const = 0;
	virtual FormeSimple* visit(const Cercle* f)const = 0;
};