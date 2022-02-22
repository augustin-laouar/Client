
#include "FormeSimple.h"
#include "Forme2D.h"
#include "GroupeForme.h"
#include "Polygone.h"
#include "Cercle.h"
#include "Trait.h"
class VisitorForme2D
{
	public :
	virtual ~VisitorForme2D(){}
	virtual void visit(const FormeSimple* f)const = 0;
	virtual	void visit(const GroupeForme* f)const = 0;
	virtual void visit(const Polygone* f)const = 0;
	virtual void visit(const Trait* f)const = 0;
	virtual void visit(const Cercle* f)const = 0;
};
