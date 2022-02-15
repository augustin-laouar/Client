
#include "FormeSimple.h"
#include "Forme2D.h"
#include "GroupeForme.h"
class VisitorForme2D
{
	public :
	virtual Forme2D* visit(const FormeSimple* f)const = 0;
	virtual Forme2D* visit(const GroupeForme* f)const = 0;
};
