#pragma once
#include "Forme.h"
using namespace std;
class Polygone : public Forme
{

public :
	Polygone(const Polygone & p) {
		for (size_t i = 0; i < p.ListePoint.size(); i++) {
			this->AjouterPoint(p.ListePoint[i]);
		}
	}
	Polygone* clone()const {
		return new Polygone(*this);
	}
};

