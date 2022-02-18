#include "Vecteur2D.h"
void Vecteur2D::translation(const Vecteur2D& v) {
	x = x + v.x;
	y = y + v.y;
}
Vecteur2D Vecteur2D::translation(const Vecteur2D& v)const {
	Vecteur2D res(*this);
	res.translation(*this);
	return res;
}