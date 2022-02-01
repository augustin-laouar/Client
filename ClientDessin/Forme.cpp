#include "Forme.h"
Forme::Forme(const Forme& f) {
	for (size_t i = 0; i < f.ListePoint.size(); i++) {
		ListePoint.push_back(f.ListePoint[i].clone());
	}
}
void Forme::translation(const Vecteur2D& v) {

}