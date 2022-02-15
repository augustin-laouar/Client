#include "Point2D.h"
#include "Vecteur2D.h"
void Point2D::translation(const Vecteur2D&v){
	x = x + v.x;
	y = y + v.y;
}
