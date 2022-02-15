#pragma once
#include "VisitorForme2D.h"
#include "Plan2D.h"
class Dessin :public VisitorForme2D
{
	virtual void visit(const Polygone* f) {
		//format  d une requete  : numForme;nbpoint;x,y;couleur
		int nbp = f->getNbPoint();
		string p;
		string requete = "3;";


		for (int i = 0; i < nbp; i++)
		{
			p = to_string(f->getPoint(i).x) + "," + to_string(f->getPoint(i).y) +";";
		}
		requete = requete + to_string(nbp) + p + to_string(f->getCouleur())+"\n";
		
	}
	virtual void visit(const Trait* f) {
		//envoyer la requete

		int nbp = f->getNbPoint();
		string p;
		string requete = "1;";


		for (int i = 0; i < nbp; i++)
		{
			p = to_string(f->getPoint(i).x) + "," + to_string(f->getPoint(i).y) + ";";
		}
		requete = requete + to_string(nbp) + p + to_string(f->getCouleur()) + "\n";
	}
	virtual void visit(const Cercle* f) {
		int nbp = f->getNbPoint();
		string p;
		string requete = "2;";


		for (int i = 0; i < nbp; i++)
		{
			p = to_string(f->getPoint(i).x) + "," + to_string(f->getPoint(i).y) + ";";
		}
		requete = requete + to_string(nbp) + p + to_string(f->getCouleur()) + "\n";
	}
	virtual void visit(const FormeSimple* f) {
		switch (f->whoAmI()) {
			case 10: {
				Cercle* c = (Cercle*)f;
				visit(c);
			}
				   break;
			case 11: {
				Polygone* p = (Polygone*)f;
				visit(p);
			}
				   break;
			case 12: {
				Trait* t = (Trait*)f;
				visit(t);
			}
			
		}
	}
	virtual void visit(const GroupeForme* f) {
		for (size_t i = 0; i < f->getNbForme(); i++) {
			visit(f->getForme(i));
		}
	}
	virtual void visit(const Forme2D* f) {
		if (f->whoAmI() > 0) {
			FormeSimple* f2 = (FormeSimple*)f;
			visit(f2);
		}
		else {
			GroupeForme* f2 = (GroupeForme*)f;
			visit(f2);
		}
	}

	void Dessiner(const Plan2D& p)const {
		for (int i = 0; i < p.nbFormes(); i++) {
			p.getForme(i)->accept(this);
		}
	}
};

