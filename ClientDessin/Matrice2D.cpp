#include "Matrice2D.h"
string Matrice2D::toString()const {
	string retour = "MATRICE 2D :\n|";
	retour += to_string(x1) + "   " + to_string(x2) + "|\n|";
	retour += to_string(y1) + "   " + to_string(y2) + "|";
	return retour;
}

bool Matrice2D::operator == (const Matrice2D& m)const {

	if (x1 == m.x1 && x2 == m.x2 && y1 == m.y1 && y2 == m.y2) {
		return true;
	}
	return false;
}
Matrice2D Matrice2D::operator +(const Matrice2D& m)const {
	Matrice2D res(*this);
	res.x1 = x1 + m.x1;
	res.x2 = x2 + m.x2;
	res.y1 = y1 + m.y1;
	res.y2 = y2 + m.y2;
	return res;
}
Matrice2D Matrice2D::operator -(const Matrice2D& m)const {
	Matrice2D res(*this);
	res.x1 = x1 - m.x1;
	res.x2 = x2 - m.x2;
	res.y1 = y1 - m.y1;
	res.y2 = y2 - m.y2;
	return res;
}
Matrice2D Matrice2D::operator *(const Matrice2D& m)const {
	Matrice2D res;
	res.x1 = x1 * m.x1 + x2 * m.y1;
	res.x2 = x1 * m.x2 + y1 * m.y2;
	res.y1 = y1 * m.x1 + y2 * m.y1;
	res.y2 = y1 * m.x2 + y2 * m.y2;
	return res;
}
Matrice2D Matrice2D::operator *(double d)const {
	Matrice2D res(*this);
	res.x1 = res.x1 * d;
	res.x2 = res.x2 * d;
	res.y1 = res.y1 * d;
	res.y2 = res.y2 * d;
	return res;
}
Vecteur2D Matrice2D::operator *(Vecteur2D v)const {
	Vecteur2D res;
	res.x = x1 * v.x + x2 * v.y;
	res.y = y1 * v.x + y2 * v.y;
	return res;
}
