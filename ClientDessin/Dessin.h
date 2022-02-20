#pragma once
#include "VisitorForme2D.h"
#include "Plan2D.h"
#include "Communication.h"
class Dessin :public VisitorForme2D
{
public:
	/*
	* fonction qui associe une couleur a son format necessaire pour une requete
	*/
	string associerCouleur(Couleur c)const {

		return c.toString();
	}

	/*
	* cette methode va envoyer une requete au serveur pour dessiner la forme voulu 
	* format  d une requete  : numForme;nbpoint;x,y;couleur
	* la couleur est en format "r,g,b"
	*/
	
	
	virtual void visit(const Polygone* f) const{
		
		int nbp = f->getNbPoint();
		string p;
		string requete = "3;";
		for (int i = 0; i < nbp; i++)
		{
			p = p + to_string((int)(f->getPoint(i).x)) + "," + to_string((int)(f->getPoint(i).y)) + ";";
		}
		requete = requete + to_string(nbp) + ";"+ p + associerCouleur(f->getCouleur()) + "\n";

		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de polygone envoyé : " << requete << endl;

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
		
	}


	virtual void visit(const Trait* f) const{
		
		int nbp = f->getNbPoint();
		string p;
		string requete = "1;";


		for (int i = 0; i < nbp; i++) //construction de la chaine nbp conteant les coordonnes des points
		{
			p = p+ to_string((int)(f->getPoint(i).x)) + "," + to_string((int)(f->getPoint(i).y) )+ ";";
		}
		requete = requete + to_string(nbp) + ";" +p + associerCouleur(f->getCouleur()) + "\n";

		

		//envoi de la requet pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de trait envoyé : " << requete << endl;

		}

		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
	}


	virtual void visit(const Cercle* f)const {
		
		//pour un cercle on envoi sous forme  : 2;nbPoints;rayon;centre;color
		
		string requete;

		requete = "2;1;" + to_string((int)f->getRayon())+ ";" + to_string((int)(f->getPoint(0).x)) + "," + to_string((int)(f->getPoint(0).y)) + ";";
		
		requete = requete +  associerCouleur(f->getCouleur()) + "\n";


		//envoi de la requet pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de cercle envoyé : " << requete << endl;

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}
	}


	virtual void visit(const FormeSimple* f)const {


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
	virtual void visit(const GroupeForme* f)const {
		for (size_t i = 0; i < f->getNbForme(); i++) {
			visit(f->getForme(i));
		}
	}
	virtual void visit(const Forme2D* f)const {
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
		cout << "Dessin des formes du plan..." << endl;
		for (int i = 0; i < p.nbFormes(); i++) {
			p.getForme(i)->accept(this);
		}
		cout << "Dessin des formes du plan terminé." << endl;
	}
};

